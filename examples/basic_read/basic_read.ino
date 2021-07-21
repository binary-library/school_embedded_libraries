#include <tsc230.hpp>

TSC_230 color_s(2,3,4,5,6);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  color_s.setup();
}

void loop() {
  RGB res = color_s.read_rgb();
  Serial.println(res.get(red));
  Serial.println(res.get(green));
  Serial.println(res.get(blue));
  Serial.println("------------");
  // put your main code here, to run repeatedly:
}
