#include <Wire.h>
#include <SD.h>
#include <BME280I2C.h>
#include "DS1307.h"
#include <recoltedonnees.h>
#include <saveSD.h>


void initSD(){
    const byte SDCARD_CS_PIN = 4;
    pinMode(10, OUTPUT);

    Serial.print(F("Init SD card..."));
    if(!SD.begin(SDCARD_CS_PIN)){
        Serial.println(F("Fail appuyez sur reset"));
        for(;;);//appui sur reset
    }
    Serial.println(F("OK"));
}

void saveSD(Mesures *prise){
    int nbfile = 0;
    File myfile;
    char filename[14];
    File root = SD.open("/");
    File testfile = root.openNextFile();
    /*if(!SD.exists("/fichier1.txt")){//si le fichier1 n'existe pas
        Serial.println("création du fichier1");
        myfile = SD.open("/fichier1.txt", FILE_WRITE);
        myfile.print("temperature:");
        myfile.print(prise->temperature);
        myfile.print("/");
        myfile.print("pression:");
        myfile.print(prise->pression);
        myfile.print("/");
        myfile.print("humidite:");
        myfile.print(prise->humidite);
        myfile.print("/");
        myfile.print("luminosité:");
        myfile.print(prise->lumin);
        myfile.print("/");
        myfile.print("heure:");
        myfile.print(prise->heure);
        myfile.print(":");
        myfile.print(prise->minute);
        myfile.print(":");
        myfile.print(prise->sec);
        myfile.print("/");
        myfile.print("Date:");
        myfile.print(prise->jour);
        myfile.print("/");
        myfile.print(prise->mois);
        myfile.print("/");
        myfile.println(prise->annee);
        myfile.close();
        Serial.println("mesures rentrées");
        
    }*/
    myfile = SD.open("/fichier1.txt", FILE_WRITE);
        myfile.print("temperature:");
        myfile.print(prise->temperature);
        myfile.print("/");
        myfile.print("pression:");
        myfile.print(prise->pression);
        myfile.print("/");
        myfile.print("humidite:");
        myfile.print(prise->humidite);
        myfile.print("/");
        myfile.print("luminosité:");
        myfile.print(prise->lumin);
        myfile.print("/");
        myfile.print("heure:");
        myfile.print(prise->heure);
        myfile.print(":");
        myfile.print(prise->minute);
        myfile.print(":");
        myfile.print(prise->sec);
        myfile.print("/");
        myfile.print("Date:");
        myfile.print(prise->jour);
        myfile.print("/");
        myfile.print(prise->mois);
        myfile.print("/");
        myfile.println(prise->annee);
        myfile.close();
        Serial.println("mesures rentrées");
    /*while(testfile){
        nbfile = nbfile+1;
        testfile = root.openNextFile();
        Serial.println("Le nombre de fichiers est %d"+ nbfile);
    }
    sprintf(filename,"/fichier%02d.txt",nbfile);
    myfile = SD.open(filename, FILE_WRITE);
    if(myfile.size()>4018){
        myfile.close();
        Serial.println("création de nouveau fichier");
        nbfile = nbfile+1;
        sprintf(filename,"/fichier%02d.txt",nbfile);
        myfile = SD.open(filename, FILE_WRITE);
        myfile.println(F("mesures"));
        myfile.close();
    }
    else{
        myfile.println(F("mesures"));
        Serial.println("mesures enregistrées");
        myfile.close();
    }*/
}