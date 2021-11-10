#include "EncoderDecoder.h"
EncoderDecoder Enc(2, 3, 20);

void setup() {
  Serial.begin(115200);
}

void loop() {
  Enc.Update();
  Serial.println(Enc.GetRpm(), 10);
}
