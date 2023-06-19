void displayHighScore(){
  readVal = displayValue();
  digitalWrite(D1, 0);
  digitalWrite(D2, 1);
  digitalWrite(D3, 1);
  digitalWrite(D4, 1);
  
  if(readVal == 1){
  digitalWrite(pinA, 0);   
  digitalWrite(pinB, 1);   
  digitalWrite(pinC, 1);   
  digitalWrite(pinD, 0);   
  digitalWrite(pinE, 0);   
  digitalWrite(pinF, 0);   
  digitalWrite(pinG, 0);    
    
  }

  else if(readVal == 2){
  digitalWrite(pinA, 1);   
  digitalWrite(pinB, 1);   
  digitalWrite(pinC, 0);   
  digitalWrite(pinD, 1);   
  digitalWrite(pinE, 1);   
  digitalWrite(pinF, 0);   
  digitalWrite(pinG, 1); 
    }

  else if(readVal == 3){  
  digitalWrite(pinA, 1);   
  digitalWrite(pinB, 1);   
  digitalWrite(pinC, 1);   
  digitalWrite(pinD, 1);   
  digitalWrite(pinE, 0);   
  digitalWrite(pinF, 0);   
  digitalWrite(pinG, 1);
    }

  else if(readVal ==4){
      digitalWrite(pinA, 0);   
  digitalWrite(pinB, 1);   
  digitalWrite(pinC, 1);   
  digitalWrite(pinD, 0);   
  digitalWrite(pinE, 0);   
  digitalWrite(pinF, 1);   
  digitalWrite(pinG, 1);
    }   
  else if(readVal ==5){
  digitalWrite(pinA, 1);   
  digitalWrite(pinB, 0);   
  digitalWrite(pinC, 1);   
  digitalWrite(pinD, 1);   
  digitalWrite(pinE, 0);   
  digitalWrite(pinF, 1);   
  digitalWrite(pinG, 1);     
    } 
  else if(readVal ==6){
  digitalWrite(pinA, 1);   
  digitalWrite(pinB, 0);   
  digitalWrite(pinC, 1);   
  digitalWrite(pinD, 1);   
  digitalWrite(pinE, 1);   
  digitalWrite(pinF, 1);   
  digitalWrite(pinG, 1);
    }
  else if(readVal ==7){
  digitalWrite(pinA, 1);   
  digitalWrite(pinB, 1);   
  digitalWrite(pinC, 1);   
  digitalWrite(pinD, 0);   
  digitalWrite(pinE, 0);   
  digitalWrite(pinF, 0);   
  digitalWrite(pinG, 0);
    }
  else if(readVal ==8){
   digitalWrite(pinA, 1);   
  digitalWrite(pinB, 1);   
  digitalWrite(pinC, 1);   
  digitalWrite(pinD, 1);   
  digitalWrite(pinE, 1);   
  digitalWrite(pinF, 1);   
  digitalWrite(pinG, 1);    
    }
  else if(readVal == 9){
      digitalWrite(pinA, 1);   
  digitalWrite(pinB, 1);   
  digitalWrite(pinC, 1);   
  digitalWrite(pinD, 0);   
  digitalWrite(pinE, 0);   
  digitalWrite(pinF, 1);   
  digitalWrite(pinG, 1);
    }
  else{
  digitalWrite(pinA, 1);   
  digitalWrite(pinB, 1);   
  digitalWrite(pinC, 1);   
  digitalWrite(pinD, 1);   
  digitalWrite(pinE, 1);   
  digitalWrite(pinF, 1);   
  digitalWrite(pinG, 0);
  }



  
  
}

void displayScore(){
  score = score; 
  digitalWrite(D1, 1);
  digitalWrite(D2, 1);
  digitalWrite(D3, 0);
  digitalWrite(D4, 1);
    if(score == 1){
  digitalWrite(pinA, 0);   
  digitalWrite(pinB, 1);   
  digitalWrite(pinC, 1);   
  digitalWrite(pinD, 0);   
  digitalWrite(pinE, 0);   
  digitalWrite(pinF, 0);   
  digitalWrite(pinG, 0);    
    
  }

  else if(score == 2){
  digitalWrite(pinA, 1);   
  digitalWrite(pinB, 1);   
  digitalWrite(pinC, 0);   
  digitalWrite(pinD, 1);   
  digitalWrite(pinE, 1);   
  digitalWrite(pinF, 0);   
  digitalWrite(pinG, 1); 
    }

  else if(score == 3){  
  digitalWrite(pinA, 1);   
  digitalWrite(pinB, 1);   
  digitalWrite(pinC, 1);   
  digitalWrite(pinD, 1);   
  digitalWrite(pinE, 0);   
  digitalWrite(pinF, 0);   
  digitalWrite(pinG, 1);
    }

  else if(score ==4){
      digitalWrite(pinA, 0);   
  digitalWrite(pinB, 1);   
  digitalWrite(pinC, 1);   
  digitalWrite(pinD, 0);   
  digitalWrite(pinE, 0);   
  digitalWrite(pinF, 1);   
  digitalWrite(pinG, 1);
    }   
  else if(score ==5){
  digitalWrite(pinA, 1);   
  digitalWrite(pinB, 0);   
  digitalWrite(pinC, 1);   
  digitalWrite(pinD, 1);   
  digitalWrite(pinE, 0);   
  digitalWrite(pinF, 1);   
  digitalWrite(pinG, 1);     
    } 
  else if(score ==6){
  digitalWrite(pinA, 1);   
  digitalWrite(pinB, 0);   
  digitalWrite(pinC, 1);   
  digitalWrite(pinD, 1);   
  digitalWrite(pinE, 1);   
  digitalWrite(pinF, 1);   
  digitalWrite(pinG, 1);
    }
  else if(score ==7){
  digitalWrite(pinA, 1);   
  digitalWrite(pinB, 1);   
  digitalWrite(pinC, 1);   
  digitalWrite(pinD, 0);   
  digitalWrite(pinE, 0);   
  digitalWrite(pinF, 0);   
  digitalWrite(pinG, 0);
    }
  else if(score ==8){
   digitalWrite(pinA, 1);   
  digitalWrite(pinB, 1);   
  digitalWrite(pinC, 1);   
  digitalWrite(pinD, 1);   
  digitalWrite(pinE, 1);   
  digitalWrite(pinF, 1);   
  digitalWrite(pinG, 1);    
    }
  else if(score == 9){
      digitalWrite(pinA, 1);   
  digitalWrite(pinB, 1);   
  digitalWrite(pinC, 1);   
  digitalWrite(pinD, 0);   
  digitalWrite(pinE, 0);   
  digitalWrite(pinF, 1);   
  digitalWrite(pinG, 1);
    }
  else{
  digitalWrite(pinA, 1);   
  digitalWrite(pinB, 1);   
  digitalWrite(pinC, 1);   
  digitalWrite(pinD, 1);   
  digitalWrite(pinE, 1);   
  digitalWrite(pinF, 1);   
  digitalWrite(pinG, 0);
  }  
  
  
}