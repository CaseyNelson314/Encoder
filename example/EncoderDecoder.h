/*
        @file   EncoderDecoder.h
        @brief  EncoderReader
        @author CaseyNelson314
        @date   2021/11/10
*/

#pragma once
#include <Arduino.h>

#define RpmSelect 1 //rpm 0:整数型,1:浮動小数点型

class EncoderDecoder {

  private:
    const byte InputPinA, InputPinB;
    const unsigned long pprdata;  // 分解能(クリック/1回転)
    byte dataA, dataB;
    int  Encodata;
    long Countdata;
    unsigned long Time, OldTime;
    
#if !RpmSelect
    unsigned long Rpmdata;
#else
    double Rpmdata;
#endif

  public:

    EncoderDecoder(byte EncoderPinA, byte EncoderPinB, unsigned long PprData = 0): InputPinA(EncoderPinA), InputPinB(EncoderPinB) , pprdata(PprData) {
      pinMode(InputPinA, INPUT_PULLUP);
      pinMode(InputPinB, INPUT_PULLUP);
    }

    void Update() {
      Countdata += (Encodata = (dataA - dataB) * !(dataA = digitalRead(InputPinA)) * !(dataB = digitalRead(InputPinB)));
      if (Encodata != 0 && pprdata != 0) {
        Time = millis();
#if !RpmSelect
        Rpmdata = 60000 / ((Time - OldTime) * pprdata);
#else
        Rpmdata = 60000 / ((double)(Time - OldTime) * (double)pprdata);
#endif
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
