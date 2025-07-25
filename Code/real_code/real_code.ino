#include <Servo.h>
#include "MAX31855.h"

Servo theservo;

float wiper_to_angle_scale = 0;
float wiper_to_angle_offset = 0;

float reading;

const int servo_pin = 28;
const int servo_feedback_pin = A1;
const int set_pin = 0;
const int store1_pin = 7;
const int store2_pin = 6;
const int warning_light_pin = 3;
const int fader_pin = A0; // set this up
const int big_led_dimming_pin = 29; // set this up
const int SPI_CHIP_SELECT = 1;
const int SPI_MISO = MISO;
const int SPI_SYSTEM_CLOCK = SCK;

MAX31855_Class MAX31855; // (LED temperature monitoring chip)

float store1;
float store2;

bool do_movement_limits = true;
int upper_movement_limit = 170;
int lower_movement_limit = 10;

float read_analogue_input_avg(int delay_time=5, int readings=50) {
  float avg_read;
  int i;

  avg_read = analogRead(servo_feedback_pin);
  for (i=1; i<readings; i++) {
    avg_read = (avg_read + analogRead(servo_feedback_pin)) / 2;
    delay(delay_time);
  }
  return avg_read;
}

float wiper_to_angle(float analogue_input) {
  return (analogue_input - wiper_to_angle_offset) / wiper_to_angle_scale ;
}

void smooth_rotate(int angle) {

}

void setup() {
  digitalWrite(big_led_dimming_pin, HIGH); // driving it high will make the output of the optocoupler be low in theory so the led driver is set to 0%
  float wiper_at_60;
  float wiper_at_120;
  int i;

  theservo.attach(servo_pin);
  Serial.begin(115200);
  pinMode(set_pin, INPUT_PULLUP);
  pinMode(store1_pin, INPUT_PULLUP);
  pinMode(store2_pin, INPUT_PULLUP);
  pinMode(servo_feedback_pin, INPUT_PULLUP);
  pinMode(warning_light_pin, OUTPUT);

  while (!MAX31855.begin(SPI_CHIP_SELECT) || (!digitalRead(set_pin) && !digitalRead(store1_pin) && !digitalRead(store2_pin))) {
    Serial.println("Failed to set up MAX31855 temperature monitoring, retrying in 3 seconds or press all 3 buttons to override, DOING THIS PUTS YOU AT RISK OF THE LED OVERHEATING AND DYING!!!!!!!!");
    delay(3000);
  }

  theservo.write(59);
  delay(800);
  theservo.write(60);
  delay(150);
  wiper_at_60 = read_analogue_input_avg(5, 200);

  theservo.write(121);
  delay(800);
  theservo.write(120);
  delay(150);
  wiper_at_120 = read_analogue_input_avg(5, 200);

  for (i=0; i<3; i++) {
    theservo.write(59);
    delay(800);
    theservo.write(60);
    delay(150);
    wiper_at_60 = (wiper_at_60 + read_analogue_input_avg(5, 150)) / 2;

    theservo.write(121);
    delay(800);
    theservo.write(120);
    delay(150);
    wiper_at_120 = (wiper_at_120 + read_analogue_input_avg(5, 150)) / 2;
  }

  Serial.print("60º: ");
  Serial.println(wiper_at_60);
  Serial.print("120º: ");
  Serial.println(wiper_at_120);

  wiper_to_angle_scale = (wiper_at_120 - wiper_at_60) / (120-60);
  wiper_to_angle_offset = wiper_at_60 - 60 * wiper_to_angle_scale;

  Serial.print("Scale: ");
  Serial.println(wiper_to_angle_scale);
  Serial.print("Offset: ");
  Serial.println(wiper_to_angle_offset);

  //theservo.write(0);
  delay(2000);

  //for (i=0; i<=180; i += 5) {
  //  theservo.write(i);
  //  delay(100);
  //  reading = read_analogue_input_avg(6, 200);
  //  Serial.print(i);
  //  Serial.print("º is read as ");
  //  Serial.print(wiper_to_angle(reading));
  //  Serial.println("º");
  //}
  theservo.detach();
}


float angle;

void loop() {

  // put your main code here, to run repeatedly:
  reading = read_analogue_input_avg(1, 10);
  angle = wiper_to_angle(reading);

  if (do_movement_limits) {
    if ((angle <= lower_movement_limit || angle >= upper_movement_limit) && !theservo.attached()) {
        theservo.write(angle);
        theservo.attach(servo_pin);
        digitalWrite(warning_light_pin, HIGH);
        Serial.println("hey!");
      }

    if (angle <= lower_movement_limit+10) {
      theservo.write(angle + 2);
    }
    else if (angle >= upper_movement_limit-10) {
      theservo.write(angle - 5);
    }

    if ((lower_movement_limit+2 <= angle) && (angle <= upper_movement_limit-5) && theservo.attached()) {
      theservo.write(angle);
      theservo.detach();
      digitalWrite(warning_light_pin, LOW);
      Serial.println("yay");
    }
  }


  if (digitalRead(store1_pin) == 0) {
    Serial.println("AA");
    if (digitalRead(set_pin) == 0) {
      store1 = wiper_to_angle(read_analogue_input_avg(2, 50));
    }
    else {
      if (!theservo.attached()) {
        theservo.attach(servo_pin);
      }
      theservo.write(store1);
      delay(300);
      theservo.detach();
    }
  }
  if (digitalRead(store2_pin) == 0) {
    Serial.println("BB");
    if (digitalRead(set_pin) == 0) {
      store2 = wiper_to_angle(read_analogue_input_avg(2, 50));
    }
    else {
      if (!theservo.attached()) {
        theservo.attach(servo_pin);
      }
      theservo.write(store2);
      delay(300);
      theservo.detach();
    }
  }


  //Serial.print(reading);
  //Serial.print(" = ");
  Serial.print(angle);
  Serial.println("º");
}