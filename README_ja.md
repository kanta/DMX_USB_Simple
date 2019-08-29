# DMX_USB_Simple
USB経由でDMXを出力するシンプルなArduinoスケッチと、Maxのサンプルパッチです。ENTTECのDMXUSB PROのように使えます（ただしDMXを出力する機能のみで、受信などはできません）。

安定性や堅牢性などよりも、とにかくまずは手軽に動くというのを重視しています。

![DmxUsbSimple](https://user-images.githubusercontent.com/1097902/63932715-b4de1500-ca92-11e9-8c96-72f6376dd78f.jpg)

## ハードウェア
[Arduino Leonardo](https://www.arduino.cc/en/Main/Arduino_BoardLeonardo) または相当品。※このスケッチはUNOでは動きません。

[DFROBOT DMX Shield for Arduino](https://www.dfrobot.com/product-984.html)  
Switch Scienceなどから通販で購入できます。

## Arduinoスケッチ
[DMXSerialライブラリ](https://github.com/mathertel/DMXSerial)を使用します。Arduino IDEのライブラリマネージャからインストールできます。

## Maxパッチ
![dmxUsbSimple_sc1](https://user-images.githubusercontent.com/1097902/63922982-b0a8fc00-ca80-11e9-8a98-7bd4cfff6591.png)
serportから、シリアルポートを選んでください。
例えば8ch分のDMXを送りたい場合は、0-255の数値が8個並んだリストを送ります。最大512chまで送れます。
このパッチを使って、本物のDMXUSBPROを動かすことも可能です。
