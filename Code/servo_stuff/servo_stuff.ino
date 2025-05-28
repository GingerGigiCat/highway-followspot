#include <Servo.h>

Servo theservo;

float wiper_to_angle_scale = 0;
float wiper_to_angle_offset = 0;

float reading;

const int servo_pin = 3;
const int servo_feedback_pin = A0;

bool do_movement_limits = true;
int upper_movement_limit = 160;
int lower_movement_limit = 20;

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


  theservo.write(59);
  delay(400);
  theservo.write(60);
  delay(50);
  wiper_at_60 = read_analogue_input_avg(5, 200);

  theservo.write(121);
  delay(300);
  theservo.write(120);
  delay(50);
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
  reading = read_analogue_input_avg(1, 3);
  angle = wiper_to_angle(reading);

  if (do_movement_limits) {
    if (angle <= lower_movement_limit) {
      if (!theservo.attached()) {
        theservo.attach(servo_pin);
      }
      theservo.write(angle + 4);
    }
    else if (angle >= upper_movement_limit) {
      if (!theservo.attached()) {
        theservo.attach(servo_pin);
      }
      theservo.write(angle - 4);
    }
    else {
      theservo.detach();
    }
  }
  Serial.print(reading);
  Serial.print(" = ");
  Serial.print(angle);
  Serial.println("º");
}