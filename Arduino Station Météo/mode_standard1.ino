int LOG_INTERVAL = 10;

void setup()
{
  Serial.begin(9600);
  /*
  float recoltesdonnees()
  {
    println("Aquisition des mesures");
    
    return 0;
  }
  
  void saveSD()
  {
    sauvegarde = mesures;
    println(sauvegarde);
  }
  */
}

void loop()
{
  delay(LOG_INTERVAL*10);
  standard();
}

void standard()
{    
  float mesures = recoltesdonnees();
    
  saveSD(mesures);
}