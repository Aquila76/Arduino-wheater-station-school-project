#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include <BME280I2C.h>
#include "DS1307.h"
#include "recoltedonnees.h"
#include "saveSD.h"
#define SERIAL_BAUD 9600

BME280I2C bme;
DS1307 clock;

int FILE_SIZE_MAX = 4096;



void setup(){
    Serial.begin(SERIAL_BAUD);
    Wire.begin();
    clock.begin();
    clock.fillByYMD(2020,10,21);
    clock.fillByHMS(15,59,10);
    //clock.fillDayOfWeek(WED);
    clock.setTime();
    initSD();
    while(!bme.begin())
    {
        Serial.println("Could not find BME280 sensor!");
        delay(1000);
    }
    
    
}
void loop(){
    Mesures prise;
    prise = prisemesures(bme, clock);
    saveSD(&prise);
    /*Serial.print("pression: ");
    Serial.print(prise.pression);
    Serial.print("  temperature: ");
    Serial.print(prise.temperature);
    Serial.print(" humidité: ");
    Serial.print(prise.humidite);
    Serial.print(" Luminosité: ");
    Serial.println(prise.lumin);
    Serial.print(" heure: ");
    Serial.print(prise.heure);
    Serial.print(":");
    Serial.print(prise.minute);
    Serial.print(":");
    Serial.print(prise.sec);
    Serial.print("  jour/mois/année: ");
    Serial.print(prise.jour);
    Serial.print("/");
    Serial.print(prise.mois);
    Serial.print("/");
    Serial.println(prise.annee);*/
    delay(6000);
}