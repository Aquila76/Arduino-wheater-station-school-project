#include <Wire.h>
#include <BME280I2C.h>
#include "DS1307.h"
#include "recoltedonnees.h"
#define SERIAL_BAUD 9600



void priseheure(Mesures *prise, DS1307 clock){
    clock.getTime();
    prise->heure = clock.hour;
    prise->minute = clock.minute;
    prise->sec = clock.second;
    prise->mois = clock.month;
    prise->annee = clock.year;
}

Mesures prisemesures(BME280I2C bme, DS1307 clock){
    float temp(NAN), hum(NAN), pres(NAN);
    Mesures prise;// on créé notre structure prise

    BME280::TempUnit tempUnit(BME280::TempUnit_Celsius);
    BME280::PresUnit presUnit(BME280::PresUnit_Pa);

    bme.read(pres,temp,hum,tempUnit,presUnit);
    prise.pression = pres;
    prise.temperature = temp;
    prise.humidite = hum;
    prise.lumin = analogRead(A0);
    priseheure(&prise, clock);

    return (prise);
}