#include <zk_5ad.h>


#include <l298n.h>

L298N driv(3,4,5,6,7,8);
void setup() {
  // put your setup code here, to run once:
  driv.setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  driv.turn_clockwise(motor_one);
  delay(1000);
  driv.set_speed_percentage(motor_one, 100);
  delay(1000);
  driv.set_speed_percentage(motor_one, 75);
  delay(1000);
  driv.set_speed_percentage(motor_one, 50);
  delay(1000);
  driv.set_speed_percentage(motor_one, 0);
}
