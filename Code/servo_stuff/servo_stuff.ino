#include <Servo.h>

Servo theservo;

float wiper_to_angle_scale = 0;
float wiper_to_angle_offset = 0;


const int servo_pin = 3;
const int servo_feedback_pin = A0;

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

  theservo.write(60);
  delay(400);
  wiper_at_60 = read_analogue_input_avg(5, 500);

  theservo.write(120);
  delay(300);
  wiper_at_120 = read_analogue_input_avg(5, 50);

  for (i=0; i<3; i++) {
    theservo.write(60);
    delay(300);
    wiper_at_60 = (wiper_at_60 + read_analogue_input_avg(5, 100)) / 2;

    theservo.write(120);
    delay(300);
    wiper_at_120 = (wiper_at_120 + read_analogue_input_avg(5, 100)) / 2;
  }

  Serial.print("60º: ");
  Serial.println(wiper_at_60);
  Serial.print("120º: ");
  Serial.println(wiper_at_120);

  wiper_to_angle_scale = (wiper_at_120 - wiper_at_60) / (120-60) ;
  wiper_to_angle_offset = wiper_at_60 - 60 * wiper_to_angle_scale;

  Serial.print("Scale: ");
  Serial.println(wiper_to_angle_scale);
  Serial.print("Offset: ");
  Serial.println(wiper_to_angle_offset);


  delay(2000);
  theservo.detach();
}


float reading;

void loop() {

  // put your main code here, to run repeatedly:
  reading = read_analogue_input_avg(5, 10);
  Serial.print(reading);
  Serial.print(" = ");
  Serial.print(wiper_to_angle(reading));
  Serial.println("º");
}