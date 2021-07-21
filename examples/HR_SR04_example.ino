#include <hr_sr04.h>

HR_SR04 distance_sensor(3,4);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  Serial.print("cm: ");
  Serial.println(distance_cm_average(5));
}
