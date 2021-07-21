#include <zk_5ad.h>

ZK_5AD driv(3,4,5,6);
void setup() {
  // put your setup code here, to run once:
  driv.setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  driv.turn_clockwise(motor_one);
  delay(1000);
  driv.turn_counter_clockwise(motor_one);
}
