/*
 * DMXUSB_simple.ino
 *
 * target : Arduino Leonardo
 * Created: 8/15/2019 3:23:37 PM
 * Author: kanta
 */ 
 
#include <DMXSerial.h>

#define TXDENpin  2
#define START_DELIMITER 0x7E
#define END_DELIMITER 0xE7

void setup()
{
  Serial.begin(115200); // USB Serial
  DMXSerial.init(DMXController, TXDENpin);

}

void loop() {
  static uint8_t rxState = 0;
  static uint16_t dataLength = 0, rxCount = 0;
  static uint8_t rxBuf[513];
  if ( Serial.available()>0 )
  {
    byte inByte = Serial.read();
    
    switch(rxState) {
      case 0:
        if ( inByte == START_DELIMITER )
        {
          rxState = 1;
        }
      break;
      case 1:
        if ( inByte == 6 )
        {
          rxState = 2;
        } else {
          rxState = 0;
        }
      break;
      case 2:
        dataLength = inByte;
        rxState = 3;
        break;
      case 3:
        dataLength |= (inByte<<8);
        if ( dataLength <= 513)
        {
          rxState = 4;
          rxCount = 0;
        } else {
          rxState = 0;
        }
      break;
      case 4:
        rxBuf[rxCount] = inByte;
        rxCount++;
        if ( rxCount == dataLength )
        {
          rxState = 5;
        } 
      break;
      case 5:
        if ( inByte == END_DELIMITER )
        {
          for (uint16_t i=1; i<dataLength; i++)
          {
            DMXSerial.write(i,rxBuf[i]);
          }
        } else {
          rxState = 0;
        }
      break;
    }  // switch
  }
}
