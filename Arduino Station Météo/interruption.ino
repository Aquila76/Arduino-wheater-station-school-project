#include <ChainableLED.h>
#define LED 8

volatile int mode = 0;
int button1 =2;

volatile unsigned long sec1;
volatile unsigned long sec2;
volatile int sec =0;


ChainableLED leds(8,9,LED);

void setup(){
Serial.begin(9600);
pinMode(button1,INPUT);
attachInterrupt(digitalPinToInterrupt(button1), Changer, CHANGE);

}

void loop(){

volatile int mode_pre;

// On change la couleur de la led en fonction du mode actuel
if(mode == 0){leds.setColorRGB(0, 0, 0, 0);}
if(mode == 1){leds.setColorRGB(0, 0, 255, 0);}
if(mode == 2){leds.setColorRGB(0, 255, 255, 0);}
if(mode == 3){leds.setColorRGB(0, 0, 0, 255);}
if(mode == 4){leds.setColorRGB(0, 255, 70, 0);}

// on change le mode en fonction des pressions du bouton
if(mode == 0){
if(sec >= 1000 && sec <= 5000 && mode == 0){mode = 1; sec = 0;}
if(sec >= 5000 && mode == 0){mode = 2; sec = 0;}
}

else if(mode == 1){
if(sec >= 1000 && sec <= 5000 && mode == 1){mode = 4; sec = 0;mode_pre = 1;}
if(sec >= 5000 && mode == 1){mode = 3; sec = 0;mode_pre = 1;}
}
else if(mode == 3){
if(sec >= 1000 && sec <= 5000 && mode == 3){mode = 4; sec =0;mode_pre = 3;}
if(sec >= 5000 && mode == 3){mode = 1; sec = 0;mode_pre = 3;}
}
else if(mode == 4){
if(sec >= 1000 && sec <= 5000 && mode == 4 && mode_pre == 1){mode = 1; sec = 0; mode_pre = 4;}
if(sec >= 1000 && sec <= 5000 && mode == 4 && mode_pre == 3){mode = 3; sec = 0; mode_pre = 4;}
}

if(digitalRead(button1)==HIGH){sec1=0;}

}

// interruption qui mesure le temps de pression du bouton. On réccupère ce temps dans la variable sec
void Changer(){
int secb = 0;
if(sec1==0){
sec1 = millis();
}else{
sec2 = millis();
secb=sec2-sec1;
sec1=0;
if(secb<100){
sec1=millis();
}else{
sec=secb;
}
}
}
