int latchPin = 12;
int clockPin = 11;
int dataPin = 8;
int btnPin = 2;
int btnstate=0;
int oldbtn=0;
int picstate=0;
byte colDataMatrix[8] = {B01111111,
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
int delay_time = 1;
       
void setup() {
pinMode(latchPin,OUTPUT);
pinMode(clockPin,OUTPUT);
pinMode(dataPin,OUTPUT);
pinMode(btnPin,INPUT);
}
void loop() {
 btnstate=digitalRead(btnPin);
 if(btnstate==HIGH){
      for(int i = 0; i < 8 ; i++){
      digitalWrite(latchPin,LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
      shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrix2[i]);
      digitalWrite(latchPin,HIGH);
      delay(delay_time);}
    
    }
    else{
      for(int i = 0; i < 8 ; i++){
      digitalWrite(latchPin,LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
      shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrix[i]);
      digitalWrite(latchPin,HIGH);
      delay(delay_time);} 
    }
    delay(10);
 
 }

