# DMX_USB_Simple
A simple solution for sending DMX signal via USB with Arduino and Max. Works as ENTTEC DMXUSBPRO but only for outputs.
Focused on easiness + cheapness, not for stability or robustness.
![DmxUsbSimple](https://user-images.githubusercontent.com/1097902/63932715-b4de1500-ca92-11e9-8c96-72f6376dd78f.jpg)

## Hardware
- [Arduino Leonardo](https://www.arduino.cc/en/Main/Arduino_BoardLeonardo) or equivalent. UNO won't work with this sketch.
- [DFROBOT DMX Shield for Arduino](https://www.dfrobot.com/product-984.html)

## Arduino sketch
[DMXSerial Library](https://github.com/mathertel/DMXSerial) is required. You can install it from the Library Maneger in Arduino IDE.

## Max patch
![dmxUsbSimple_sc1](https://user-images.githubusercontent.com/1097902/63922982-b0a8fc00-ca80-11e9-8a98-7bd4cfff6591.png)
Select the serial port from serport. 
If you want to send 8ch DMX data, send a list with 8 numbers 0-255. The maximum list length is 512.
You can control a real DMXUSBPRO with this patch.
