#include "Wire.h"
#include <SPI.h>
byte stacker[8];  
int CS = 7;
int pinA = 2;
int pinB = 3;
int pinC = 4;
int pinD = 5;
int pinE = 6;
int pinF = A1;
int pinG = 8;
int D1 = 9;
int D2 = 10;
int D3 = A0;
int D4 = 12; 
int button = 16;
int level = 5; 
int score = 0;
int currentRow = 1;
int sim = 3;  
byte line [8] = {B11100000, B01110000, B00111000,
                 B00011100,B00001110, B00000111};
byte clearRow = B00000000;
int game_counter = 0; 
int pos = 0; 
int readVal;
int endCounter = 0;
int scoreCounter= 0;  
typedef struct task{
  int state;
  unsigned long period;  
  unsigned long elapsedTime;
  int(*TickFct)(int);
}task;
const unsigned short tasksNum = 2;
task tasks[tasksNum];



enum score{score_init, score_on, highScore_on};
int score_tick(int state1){
  switch(state1){//state transitions
    case score_init:
      state1 = highScore_on;
      break;
    case score_on:
      if(scoreCounter > 3){
        scoreCounter = 0;
        state1 = highScore_on;
        }
        break;
    case highScore_on:
      if(scoreCounter > 3){
        scoreCounter = 0;
        state1 = score_on;
        }
      break;
    }
  switch(state1){//state actions
    case score_init:
      break;
    case score_on:
      displayScore();
      ++scoreCounter;
      break;
    case highScore_on:
      displayHighScore();
      ++scoreCounter;
   break;       
  }
  return state1;  
}

enum game{game_init, game_on, game_reverse, game_end, game_win};
int game_tick(int state2){
  switch(state2){//state transitions
    case game_init:
      for(int i = 1; i < 9; ++i){
        matrixWrite(i, clearRow);
        }
      state2 = game_on;
      break;
    case game_on:
      if(sim <=0){
        state2 = game_end;
        }  
      if(currentRow >8){
        ++score;
        state2 = game_win;
        }  
      if(game_counter == level){
        state2 = game_reverse;
        }
    case game_reverse:
      if(sim <=0){
        state2 = game_end;
        }
      if(currentRow > 8 ){
        //++score;
        state2 = game_win; 
        }  
      if(game_counter ==0){
        state2 = game_on;
        }
      break;
    case game_end:
      if(sim >0){
        score = 0;
        currentRow = 1;
        game_counter = 0; 
        endCounter = 0;
        pos = 0;
        level = 5;
        state2 = game_init;
        
        }
           
      break;
      
    case game_win:
      if(currentRow == 1){
         
        sim = 3; 
        game_counter = 0; 
        endCounter = 0;
        pos = 0; 
        level = 5;
        state2 = game_init;
        }
        break;
      
    }
  switch(state2){//state actions
    case game_init:
      break;
    case game_on:

        matrixWrite(currentRow,line[game_counter]);
        if(digitalRead(button) == 1){
          if(currentRow == 0){
            stacker[pos] = line[game_counter];
            }
          if(currentRow == 3){
            if(stacker[pos] != line[game_counter]){
              --sim;
              ++pos;
              stacker[pos] = line[game_counter];
              }
            else{
              ++pos;
              ++level;
              updateLine1(line);
              stacker[pos] = line[game_counter];
              }
            }
           if(currentRow == 6){
             if(stacker[pos] != line[game_counter]){
              --sim;
              ++pos;
              ++level;
              updateLine2(line);
              stacker[pos] = line[game_counter];
              }
              else{
              ++pos;
              ++level;
              updateLine2(line);
              stacker[pos] = line[game_counter];
                } 
            }
           else{
            if(stacker[pos] != line[game_counter]){
              
              --sim;
              ++pos;
              stacker[pos] = line[game_counter];
              }
            else{
              ++pos;
              stacker[pos] = line[game_counter];
              }
            
            }
          ++currentRow;
          }
        ++game_counter;  
       
        break;
  
    case game_reverse:
        matrixWrite(currentRow,line[game_counter]);
        if(digitalRead(button) == 1){
          if(currentRow == 0){
            stacker[pos] = line[game_counter];
            }
          if(currentRow == 3){
            if(stacker[pos] != line[game_counter]){
              --sim;
              ++pos;
              stacker[pos] = line[game_counter];
              }
            else{
              ++pos;
              ++level;
              updateLine1(line);
              stacker[pos] = line[game_counter];
              }
            
            }

           if(currentRow == 6){
             if(stacker[pos] != line[game_counter]){
              --sim;
              ++pos;
              ++level;
              updateLine2(line);
              stacker[pos] = line[game_counter];
              }
              else{
              ++pos;
              ++level;
              updateLine2(line);
              stacker[pos] = line[game_counter];
                } 
            }
            
           else{
            if(stacker[pos] != line[game_counter]){
              --sim;
              ++pos;
              stacker[pos] = line[game_counter];
              }
            else{
              ++pos;
              stacker[pos] = line[game_counter];
              }
            
            }
          ++currentRow;
          }
        --game_counter;
        break;
    case game_end:
       resetLine(line);
       matrixWrite(1,B11111111);    
       matrixWrite(2,B00000001);
       matrixWrite(3,B00000001);
       matrixWrite(4,B00000001);
       matrixWrite(5,B00000001);
       matrixWrite(6,B00000001);
       matrixWrite(7,B00000001);
       matrixWrite(8,B00000001);
       ++endCounter;
       if(endCounter>=5){
        sim = 3;
        }
        break;

    case game_win: 
       resetLine(line);
       if(score > readVal){
        updateScore(score);
        }
       matrixWrite(1,B11111111);    
       matrixWrite(2,B10000001);
       matrixWrite(3,B10000001);
       matrixWrite(4,B00011000);
       matrixWrite(5,B00011000);
       matrixWrite(6,B01100110);
       matrixWrite(7,B01100110);
       matrixWrite(8,B01100110);
       ++endCounter;
       if(endCounter >= 5){
        currentRow = 1;
        }
        
    break;
    }  
  return state2;
}


void setup()
{
  pinMode(CS,OUTPUT);
  pinMode(pinA, OUTPUT);     
  pinMode(pinB, OUTPUT);     
  pinMode(pinC, OUTPUT);     
  pinMode(pinD, OUTPUT);     
  pinMode(pinE, OUTPUT);     
  pinMode(pinF, OUTPUT);     
  pinMode(pinG, OUTPUT);   
  pinMode(D1, OUTPUT);  
  pinMode(D2, OUTPUT);  
  pinMode(D3, OUTPUT);  
  pinMode(D4, OUTPUT); 
  pinMode(button, INPUT);
  Wire.begin();
  SPI.setBitOrder(MSBFIRST);
  SPI.begin();
  matrixWrite(0x09, 0x00);
  matrixWrite(0x0A, 0x0E);
  matrixWrite(0x0B, 0x0F);
  matrixWrite(0x0C,0x01);
  Serial.begin(9600);
  unsigned char i = 0;
  tasks[i].state = score_init;
  tasks[i].period = 1000;
  tasks[i].elapsedTime = 0;
  tasks[i].TickFct = &score_tick;
  i++;
  tasks[i].state = game_init;
  tasks[i].period = 350;
  tasks[i].elapsedTime = 0;
  tasks[i].TickFct = &game_tick;
  i++;  
}

void loop()
{
   unsigned char i;
   for(i = 0; i < tasksNum; i++){
    if((millis() - tasks[i].elapsedTime) >= tasks[i].period){
      tasks[i].state = tasks[i].TickFct(tasks[i].state);
      tasks[i].elapsedTime = millis();
      
      }
    
    }       
    

}