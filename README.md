# Encoder Library
```
エンコーダーの読み取り値を変換できます
回転速度をrpmで出力できます
```
# Data
```
version   Arduino 1.8.16
Author    CaseyNelson314
Date      2021/11/02
```
# Usage
```
EncoderDecoder(inputpinA,inputpinB);
```
#　Function list
```
GetEncodeData     正転だと1,逆転正転0
GetCountData      正転だとカウントアップ,逆転だとカウントダウン
GetRpm            rpm値,無回転だと前回のrpm値を出力
SetPpr            encoderの分解能を設定
SetCountData      カウント値を書き換える
RpmReset          rpm値を0にリセット
CountReset        カウント値をリセット
```
# Important
```
loopの中にUpdata関数を呼び出す必要があります
ヘッダーファイル内のRpmSelectを変更するとGetrpm関数の戻り値を整数型か浮動小数点型か切り替えられます
```
