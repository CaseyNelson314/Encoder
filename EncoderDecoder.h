#include <Arduino.h>

#ifndef DEF_EncoderDecoder_H
#define DEF_EncoderDecoder_H

class EncoderDecoder {

  private:

    byte InputPinA, InputPinB;
    byte dataA, dataB;
    long Countdata;
    int  Encodata;  //回転方向によって1,-1が入る

  public:

    EncoderDecoder(byte EncoderPinA, byte EncoderPinB): InputPinA(EncoderPinA), InputPinB(EncoderPinB) {
      pinMode(InputPinA, INPUT_PULLUP);
      pinMode(InputPinB, INPUT_PULLUP);
    }

    void Update() {
      Countdata += (Encodata = (dataA - dataB) * !(dataA = digitalRead(InputPinA)) * !(dataB = digitalRead(InputPinB)));
    }

    int  GetEncodeData() {
      return Encodata;
    }

    long GetCountData() {
      return Countdata;
    }

    void CountReset() {
      Countdata = 0;
    }

    void SetCountData(long COUNTDATA) {
      Countdata = COUNTDATA;
    }

};
#endif
