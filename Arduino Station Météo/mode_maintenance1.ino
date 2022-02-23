void setup()
{
  Serial.begin(9600);
}

void loop()
{
  maintenance();
}

void maintenance() {
  float mesures = recoltedonnees();
  println(mesures);
}