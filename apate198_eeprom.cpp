#include "Wire.h"
#define eeprom_address 0x50

void updateScore(byte value){
  Wire.beginTransmission(eeprom_address);
  Wire.write((int)(0x01 >> 8));
  Wire.write((int)(0x01 & 0xFF));
  Wire.write(value);
  Wire.endTransmission();
}

byte displayValue(){
  byte reader = 0x00;  
  Wire.beginTransmission(eeprom_address);
  Wire.write((int)(0x01>>8));
  Wire.write((int)(0x01 & 0xFF));
  Wire.endTransmission();
  Wire.requestFrom(eeprom_address, 1);
  reader = Wire.read();
  return reader;
}