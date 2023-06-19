void matrixWrite(char address, char val){
  digitalWrite(CS, LOW);
  SPI.transfer(address);
  SPI.transfer(val);
  digitalWrite(CS,HIGH);
}

void resetLine(byte line[8]){
byte newLine [6] = {B11100000, B01110000, B00111000,
                 B00011100,B00001110, B00000111};
  for(int i =0; i <6; i++){
    line[i] = newLine[i];
    }  
  
}


void updateLine1(byte line[8]){
  byte newLine [7] = {B11000000, B01100000, B00110000,
                 B00011000,B00001100, B00000110, B00000011};
  for(int i = 0; i < 7; i++){
    line[i] = newLine[i];
    }
  
 }

 void updateLine2(byte line[8]){
  byte newLine[8] = {B10000000, B01000000, B00100000,
                 B00010000,B00001000, B00000100, B00000010, B00000001};
   for(int i =0; i < 8; i++){
    line[i] = newLine[i];
    }
  
  
}
  