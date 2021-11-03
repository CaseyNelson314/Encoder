/*
        @file   EncoderDecoder.h
        @brief  EncoderReader
        @author CaseyNelson314
        @date   2021/11/02
*/

#include <Arduino.h>

#ifndef DEF_EncoderDecoder_H
#define DEF_EncoderDecoder_H
#define RpmSelect 0 //rpm 0:整数型,1:浮動小数点型
class EncoderDecoder {

  private:
    byte InputPinA, InputPinB;
    byte dataA, dataB;
    int  Encodata;
    long Countdata, OldCountdata;
    unsigned long Time, OldTime;
    unsigned long pprdata;  // 分解能(クリック/1回転)
#if !RpmSelect
    unsigned long Rpmdata;
#else
    double Rpmdata;
#endif
  public:

    EncoderDecoder(byte EncoderPinA, byte EncoderPinB): InputPinA(EncoderPinA), InputPinB(EncoderPinB) {
      pinMode(InputPinA, INPUT_PULLUP);
      pinMode(InputPinB, INPUT_PULLUP);
    }

    void Update() {
      OldCountdata = Countdata;
      Countdata += (Encodata = (dataA - dataB) * !(dataA = digitalRead(InputPinA)) * !(dataB = digitalRead(InputPinB)));
      if (abs(Countdata - OldCountdata) >= 1) {
        Time = millis();
#if !RpmSelect
        Rpmdata = 60000 / ((Time - OldTime) * pprdata);
#else
        Rpmdata = 60000 / ((double)(Time - OldTime) * (double)pprdata);
#endif
        OldCountdata = Countdata;
        OldTime = Time;
      }
    }

    int GetEncodeData() {
      return Encodata;
    }

    long GetCountData() {
      return Countdata;
    }
#if !RpmSelect
    unsigned long GetRpm() {
      return Rpmdata;
    }
#else
    double GetRpm() {
      return Rpmdata;
    }
#endif
    void Setppr(unsigned long PPRDATA) {
      pprdata = PPRDATA;
    }

    void SetCountData(long COUNTDATA) {
      Countdata = COUNTDATA;
    }

    void RpmReset() {
      Rpmdata = 0;
    }

    void CountReset() {
      Countdata = 0;
    }

};
#endif
