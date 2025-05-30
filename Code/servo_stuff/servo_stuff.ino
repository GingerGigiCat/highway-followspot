#include <Servo.h>

Servo theservo;

float wiper_to_angle_scale = 0;
float wiper_to_angle_offset = 0;

float reading;

const int servo_pin = 3;
const int servo_feedback_pin = A0;
const int set_pin = 13;
const int store1_pin = 8;
const int store2_pin = 9;
const int store3_pin = 10;
const int store4_pin = 11;

float store1;
float store2;
float store3;
float store4;

bool do_movement_limits = true;
int upper_movement_limit = 160;
int lower_movement_limit = 35;

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
  float wiper_at_60;
  float wiper_at_120;
  int i;

  theservo.attach(servo_pin);
  Serial.begin(115200);
  pinMode(set_pin, INPUT_PULLDOWN);
  pinMode(store1_pin, INPUT_PULLDOWN);
  pinMode(store2_pin, INPUT_PULLDOWN);
  pinMode(store3_pin, INPUT_PULLDOWN);
  pinMode(store4_pin, INPUT_PULLDOWN);
  pinMode(servo_feedback_pin, INPUT_PULLDOWN);


  theservo.write(59);
  delay(400);
  theservo.write(60);
  delay(80);
  wiper_at_60 = read_analogue_input_avg(5, 200);

  theservo.write(121);
  delay(300);
  theservo.write(120);
  delay(80);
  wiper_at_120 = read_analogue_input_avg(5, 200);

  for (i=0; i<3; i++) {
    theservo.write(59);
    delay(400);
    theservo.write(60);
    delay(80);
    wiper_at_60 = (wiper_at_60 + read_analogue_input_avg(5, 150)) / 2;

    theservo.write(121);
    delay(400);
    theservo.write(120);
    delay(80);
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
        Serial.println("hey!");
        theservo.attach(servo_pin);
      }

    if (angle <= lower_movement_limit+10) {
      theservo.write(angle + 5);
    }
    else if (angle >= upper_movement_limit-10) {
      theservo.write(angle - 5);
    }

    if ((lower_movement_limit+10 <= angle) && (angle <= upper_movement_limit-5) && theservo.attached()) {
      theservo.write(angle);
      theservo.detach();
      Serial.println("yay");
    }
  }


  if (digitalRead(store1_pin)) {
    if (digitalRead(set_pin)) {
      store1 = wiper_to_angle(read_analogue_input_avg(2, 50));
    }
    else {
      if (!theservo.attached()) {
        theservo.attach(servo_pin);
      }
      theservo.write(store1);
      delay(200);
      theservo.detach();
    }
  }
  if (digitalRead(store2_pin)) {
    if (digitalRead(set_pin)) {
      store2 = wiper_to_angle(read_analogue_input_avg(2, 50));
    }
    else {
      if (!theservo.attached()) {
        theservo.attach(servo_pin);
      }
      theservo.write(store2);
      delay(200);
      theservo.detach();
    }
  }
  if (digitalRead(store3_pin)) {
    if (digitalRead(set_pin)) {
      store3 = wiper_to_angle(read_analogue_input_avg(2, 50));
    }
    else {
      if (!theservo.attached()) {
        theservo.attach(servo_pin);
      }
      theservo.write(store3);
      delay(200);
      theservo.detach();
    }
  }
  if (digitalRead(store4_pin)) {
    if (digitalRead(set_pin)) {
      store4 = wiper_to_angle(read_analogue_input_avg(2, 50));
    }
    else {
      if (!theservo.attached()) {
        theservo.attach(servo_pin);
      }
      theservo.write(store4);
      delay(200);
      theservo.detach();
    }
  }


  Serial.print(reading);
  Serial.print(" = ");
  Serial.print(angle);
  Serial.println("º");
}