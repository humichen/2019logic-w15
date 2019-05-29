int latchPin = 12;
int clockPin = 11;
int dataPin = 8;
int btnPin = 2;
int btnstate=0;
int oldbtn=0;
int picstate=1;
byte colDataMatrix[8] = {
   B01111111,
   B10111111,
   B11011111,
   B11101111,
   B11110111,
   B11111011,
   B11111101,
   B11111110
  };
                      
byte rowDataMatrix[8] = {
    B11111111,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B11111111
  };
  byte rowDataMatrix2[8] = {
    B10000001,
    B01000010,
    B00100100,
    B00011000,
    B00011000,
    B00100100,
    B01000010,
    B10000001,
  };
  byte rowDataMatrix3[8] = {
    B01100110,
    B10011001,
    B10000001,
    B10000001,
    B10000001,
    B01000010,
    B00100100,
    B00011000
  };
  byte rowDataMatrix4[8] = {
    B00000010,
    B00000011,
    B00000100,
    B00001000,
    B00010000,
    B10100000,
    B11000000,
    B11100000
  };
int delay_time = 1;
       
void setup() {
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT);
  pinMode(btnPin,INPUT);
}
void loop() {
 btnstate=digitalRead(btnPin);
 if(btnstate==HIGH && oldbtn==0){
      if(picstate==0){
        while(1){
        for(int i = 0; i < 8 ; i++){
          digitalWrite(latchPin,LOW);
          shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
          shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrix4[i]);
          digitalWrite(latchPin,HIGH);
          delay(delay_time);
          }
          picstate=1;
          btnstate=digitalRead(btnPin);
          if(btnstate==LOW && oldbtn==0){delay(10);break;}
          
        }
        
      }
      else if(picstate==1){
        while(1){
        for(int i = 0; i < 8 ; i++){
          digitalWrite(latchPin,LOW);
          shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
          shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrix3[i]);
          digitalWrite(latchPin,HIGH);
          delay(delay_time);
          } 
          picstate=0;
          btnstate=digitalRead(btnPin);
          if(btnstate==LOW && oldbtn==0){delay(10);break;}
          
        }
      }  
    }
    else{
       if(picstate==1){
        for(int i = 0; i < 8 ; i++){
          digitalWrite(latchPin,LOW);
          shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
          shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrix4[i]);
          digitalWrite(latchPin,HIGH);
          delay(delay_time);
          }
      }
      else if(picstate==0){
        for(int i = 0; i < 8 ; i++){
          digitalWrite(latchPin,LOW);
          shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
          shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrix3[i]);
          digitalWrite(latchPin,HIGH);
          delay(delay_time);
          } 
      }
      }
    oldbtn=btnstate;
    delay(10);
 }
