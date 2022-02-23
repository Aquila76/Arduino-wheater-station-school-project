#include <SD.h>
#include <SdFat.h>
 
SdFat carteSD;  
SdFile fichier;            // fichier pour les données
const byte SD_PIN = 4;     // port de la carte SD (ne pas changer)
 
unsigned long t0 = 0;                 // variable pour le timer
const unsigned long periode = 1000;   // période d'enregistrement (en ms)
 
void setup() {
  // Initialisation de la carte SD
  carteSD.begin(SD_PIN);
 
  // Mise à zéro du timer
  t0 = millis();
}
 
void loop() {
  unsigned long t = millis();
 
  if (t-t0 > periode) {
    t0 = t;
    EcrireDonnees(t);
    }
 
  // Autres opérations à réaliser .......
  delay(100);
}
 
void EcrireDonnees(unsigned long t) {
  // Acquisition des données
  float donnee = float(analogRead(A0)) / 180;
 
  // Enregistrement des données
  if (fichier.open("donnees.csv", O_RDWR | O_CREAT | O_AT_END)) {
    fichier.print(t);
    fichier.print(",");
    fichier.println(donnee, 1);
    
    fichier.close();   // fermeture du fichier
    }
}