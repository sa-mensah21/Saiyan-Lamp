#include <CapacitiveSensor.h>
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip(30, A0);
Adafruit_NeoPixel strip2(30, A1);
#include "SerialMP3Player.h"
SerialMP3Player mp3(52,53);

CapacitiveSensor ball1 = CapacitiveSensor(12, 13);
CapacitiveSensor ball2 = CapacitiveSensor(10, 11);
CapacitiveSensor ball3 = CapacitiveSensor(8, 9);
CapacitiveSensor ball4 = CapacitiveSensor(6, 7);
CapacitiveSensor ball5 = CapacitiveSensor(4, 5);
CapacitiveSensor ball6 = CapacitiveSensor(2, 3);
CapacitiveSensor ball7 = CapacitiveSensor(23, 22);

static unsigned long startTime1 = millis();
static unsigned long startTime2 = millis();
static unsigned long startTime3 = millis();
static unsigned long startTime4 = millis();
static unsigned long startTime5 = millis();
static unsigned long startTime6 = millis();
static unsigned long startTime7 = millis();
int waitTime=4000;
int state=0;
long val1;
long val2;
long val3;
long val4;
long val5;
long val6;
long val7;

int hair=1;
int pos;

int buttonPin = 36;
boolean currentReading = false;
boolean prevReading = false;

int buttonPin2 = 45;
boolean currentReading2 = false;
boolean prevReading2 = false;

int buttonPin3 = 44;
boolean currentReading3 = false;
boolean prevReading3 = false;


boolean on = false;

void setup(){
  
  strip.begin();
  strip.setBrightness(255);
  strip.clear();
  strip.show();

  strip2.begin();
  strip2.setBrightness(255);
  strip2.clear();
  strip2.show();
  
  Serial.begin(9600);
  mp3.begin(9600); delay(500);
  mp3.sendCommand(CMD_SEL_DEV, 0, 2); 
  delay(500); 
  

  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  
  playFile(1,3000);
}

void loop()
{

val1 = ball1.capacitiveSensor(30);
val2 = ball2.capacitiveSensor(30);
val3 = ball3.capacitiveSensor(30);
val4 = ball4.capacitiveSensor(30);
val5 = ball5.capacitiveSensor(30);
val6 = ball6.capacitiveSensor(30);
val7 = ball7.capacitiveSensor(30);

  prevReading = currentReading;
  currentReading = debounce(buttonPin, prevReading);
  
  if (currentReading == HIGH && prevReading == LOW){
  state++;
  if(state>1){
    state=0;
  }
  Serial.println("Hi Sean-Anthony!!!");
  }
  prevReading3 = currentReading3;
  currentReading3 = debounce(buttonPin3, prevReading3);
  
  if (currentReading3 == HIGH && prevReading3 == LOW){
    colorWipe(strip.Color(255,0,0),50); // Red
  colorWipe(strip.Color(0,255,0),50); // Green
  colorWipe(strip.Color(0,0,255),50); 
   colorWipe(strip.Color(219,94,31),50);
    playFile(7,45000);
  }
  Serial.println(val7);
// switch(state){
//  
//  case 0:
//for(int i=0; i < 30; i++){
//  strip.setPixelColor(i,strip.Color(219, 94, 31));
//  strip.show();  
//}
//   prevReading2 = currentReading2;
//  currentReading2 = debounce(buttonPin2, prevReading2);
//  
//  if (currentReading2 == HIGH && prevReading2 == LOW){
//    hair=hair+1;
//    if(hair>3){
//      hair=1;
//    }  
//  }
//
//if(hair==1){
//  for(int i=0; i < strip2.numPixels(); i++){
//  strip2.setPixelColor(i,strip2.Color(255,255,0));
//  strip2.show();
//  }
//}
//if(hair==2){
//  for(int i=0; i < strip2.numPixels(); i++){
//  strip2.setPixelColor(i,strip2.Color(219, 94, 31));
//  strip2.show();
//  }
//}
//if(hair==3){
//  for(int i=0; i < strip2.numPixels(); i++){
//  strip2.setPixelColor(i,strip2.Color(0,255,0));
//  strip2.show();
//}
//}
//
//  break;
//  
//  case 1:
  prevReading2 = currentReading2;
  currentReading2 = debounce(buttonPin2, prevReading2);
  strip.clear();
  if (currentReading2 == HIGH && prevReading2 == LOW){
    hair=hair+1;
    if(hair>4){
      hair=1;
    }  
  }

if(hair==1){
  for(int i=0; i < strip2.numPixels(); i++){
  strip2.setPixelColor(i,strip2.Color(255,255,0));
  strip2.show();
  }
}
if(hair==2){
  for(int i=0; i < strip2.numPixels(); i++){
  strip2.setPixelColor(i,strip.Color(219, 100, 0));
  strip2.show();
  }
}
if(hair==3){
  for(int i=0; i < strip2.numPixels(); i++){
  strip2.setPixelColor(i,strip2.Color(0,250,50));
  strip2.show();
}
}
if(hair==4){
  for(int i=0; i < strip2.numPixels(); i++){
  strip2.setPixelColor(i,strip2.Color(0,100,100));
  strip2.show();
}
}

//Ball1
if(val1<20){
  for(int i=0; i < 2; i++){
  strip.setPixelColor(i,strip.Color(0,0,0));
  strip.show();
}
}

if(val1>20){
  for(int i=0; i < 2; i++){
  strip.setPixelColor(i,strip.Color(219, 94, 31));
  strip.show();  
}
startTime1=millis();
if(millis() - startTime1 >= waitTime){
  for(int i=0; i < 2; i++){
  strip.setPixelColor(i,strip.Color(0, 0, 0));
  strip.show(); 
}
}
}

//Ball2
if(val2<30){
  for(int i=4; i < 6; i++){
  strip.setPixelColor(i,strip.Color(0,0,0));
  strip.show();
}
}

if(val2>30){
  for(int i=4; i < 6; i++){
  strip.setPixelColor(i,strip.Color(219, 94, 31));
  strip.show();
}
startTime2=millis();
if(millis() - startTime2 >= waitTime){
  for(int i=4; i <6; i++){
  strip.setPixelColor(i,strip.Color(0, 0, 0));
  strip.show(); 
}
}
}
//Ball3
if(val3<30){
  for(int i=8; i < 10; i++){
  strip.setPixelColor(i,strip.Color(0,0,0));
  strip.show();
}
}

if(val3>30){
  for(int i=8; i < 10; i++){
  strip.setPixelColor(i,strip.Color(219, 94, 31));
  strip.show();
}
startTime3=millis();
if(millis() - startTime3 >= waitTime){
  for(int i=8; i < 10; i++){
  strip.setPixelColor(i,strip.Color(0, 0, 0));
  strip.show(); 
}
}
}
//Ball4
if(val4<25){
  for(int i=12; i < 14; i++){
  strip.setPixelColor(i,strip.Color(0,0,0));
  strip.show();
}
}

if(val4>25){
  for(int i=12; i < 14; i++){
  strip.setPixelColor(i,strip.Color(219, 94, 31));
  strip.show();
}
startTime4=millis();
if(millis() - startTime4 >= waitTime){
  for(int i=12; i < 14; i++){
  strip.setPixelColor(i,strip.Color(0, 0, 0));
  strip.show(); 
}
}
}
//Ball5
if(val5<16){
  for(int i=16; i < 18; i++){
  strip.setPixelColor(i,strip.Color(0,0,0));
  strip.show();
}
}

if(val5>16){
  for(int i=16; i < 18; i++){
  strip.setPixelColor(i,strip.Color(219, 94, 31));
  strip.show();
}
startTime5=millis();
if(millis() - startTime5 >= waitTime){
  for(int i=16; i < 18; i++){
  strip.setPixelColor(i,strip.Color(0, 0, 0));
  strip.show(); 
}
}
}
//Ball6
if(val6<30){
  for(int i=20; i < 22; i++){
  strip.setPixelColor(i,strip.Color(0,0,0));
  strip.show();
}
}

if(val6>30){
  for(int i=20; i < 22; i++){
  strip.setPixelColor(i,strip.Color(219, 94, 31));
  strip.show();
}
startTime6=millis();
if(millis() - startTime6 >= waitTime){
  for(int i=20; i < 22; i++){
  strip.setPixelColor(i,strip.Color(0, 0, 0));
  strip.show(); 
}
}
}
//Ball7
if(val7<27){
  for(int i=25; i < 27; i++){
  strip.setPixelColor(i,strip.Color(0,0,0));
  strip.show();
}
}

if(val7>27){
  for(int i=25; i < 27; i++){
  strip.setPixelColor(i,strip.Color(219, 94, 31));
  strip.show();
}
startTime7=millis();
if(millis() - startTime7 >= waitTime){
  for(int i=25; i < 27; i++){
  strip.setPixelColor(i,strip.Color(0, 0, 0));
  strip.show(); 
}
} 
}
}
//break;
// }
//Serial.println(val3);
//}

void playFile(int file, int dur){
  //int whichFile = (file * 2) - 1;
  mp3.play(file);
  delay(dur);
  mp3.stop();
}
boolean debounce(int aButPin, boolean aPrevState){
  boolean rawState = digitalRead(aButPin);

  if (rawState == HIGH && aPrevState == LOW){
    delay(50);
  }

  return rawState;
}
void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}
