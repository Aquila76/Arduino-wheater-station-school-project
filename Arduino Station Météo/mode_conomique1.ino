void setup()
{
  Serial.begin(9600);
  LOG_INTERVAL = 2 * LOG_INTERVAL;
}

void loop()
{
  delay(LOG_INTERVAL * 1000);
  economique();
}

void economique()
{ 
  float mesures = recoltedonnees();
    
  saveSD(mesures);
}