float version = 1.0;

int ascii[13]; 
int n = 0;
unsigned long timer;

void setup() {
  Serial.begin(9600);
}

void loop() {
  bool affichage = false;
  int incomingData = 0;
  int i;
  int n_max = 13;
  
  timer = millis();
  
  if (timer == 1800000) {
    //basculer en mode standard
  }
  
  // envoyer des données seulement quand Arduino en reçoit
  if (Serial.available() > 0) {
    // lire l'octet entrant
    incomingData = Serial.read();
    ascii[n] = incomingData;
    n++;
       
    for (i = 0; i < n_max; i++) {
      Serial.println(ascii[i]);
    }
  }
  else {
    affichage = true;
  }
  if (ascii[0] == 70 && ascii[12] == 69 && affichage) {
    Serial.println("FILE_MAX_SIZE");
    affichage = false;
    FILE_MAX_SIZE();
    clear_tab();
  }
  else if (ascii[0] == 82 && ascii[4] == 84 && affichage) {
    Serial.println("RESET");
    affichage = false;
    RESET();
    clear_tab();
  }
  else if (ascii[0] == 86 && ascii[12] == 0 && affichage) {
    Serial.println("VERSION");
    affichage = false;
    VERSION();
    clear_tab();
  }
  else if (ascii[0] == 84 && ascii[1] == 73 && ascii[12] == 0 && affichage) {
    Serial.println("TIMEOUT");
    affichage = false;
    TIMEOUT();
    clear_tab();
  }
  else if (ascii[1] == 69 && ascii[12] == 0 && affichage) {
    Serial.println("TEMP_AIR");
    affichage = false;
    TEMP_AIR();
    clear_tab();
  }
  else if (ascii[0] == 76 && ascii[1] == 79 && affichage) {
    Serial.println("LOG_INTERVALL");
    affichage = false;
    LOG_INTERVALL();
    clear_tab();
  }
  else if (ascii[0] == 76 && ascii[5] == 0 && affichage) {
    Serial.println("LUMIN");
    affichage = false;
    LUMIN();
    clear_tab();
  }
  else if (ascii[0] == 76 && ascii[6] == 76 && affichage) {
    Serial.println("LUMIN_LOW");
    affichage = false;
    LUMIN_LOW();
    clear_tab();
  }
  else if (ascii[0] == 76 && ascii[6] == 72 && affichage) {
    Serial.println("LUMIN_HIGH");
    affichage = false;
    LUMIN_HIGH();
    clear_tab();
  }
  else if (ascii[0] == 77 && ascii[1] == 73 && affichage) {
    Serial.println("MIN_TEMP_AIR");
    affichage = false;
    MIN_TEMP_AIR();
    clear_tab();
  }
  else if (ascii[0] == 77 && ascii[1] == 65 && affichage) {
    Serial.println("MAX_TEMP_AIR");
    affichage = false;
    MAX_TEMP_AIR();
    clear_tab();
  }
  else if (ascii[0] == 72 && ascii[4] == 0 && affichage) {
    Serial.println("HYGR");
    affichage = false;
    HYGR();
    clear_tab();
  }
  else if (ascii[0] == 72 && ascii[6] == 73 && affichage) {
    Serial.println("HYGR_MINT");
    affichage = false;
    HYGR_MINT();
    clear_tab();
  }
  else if (ascii[0] == 72 && ascii[6] == 65 && affichage) {
    Serial.println("HYGR_MAXT");
    affichage = false;
    HYGR_MAXT();
    clear_tab();
  }
  else if (ascii[0] == 80 && ascii[8] == 0 && affichage) {
    Serial.println("PRESSURE");
    affichage = false;
    PRESSURE();
    clear_tab();
  }
  else if (ascii[0] == 80 && ascii[10] == 73 && affichage) {
    Serial.println("PRESSURE_MIN");
    affichage = false;
    PRESSURE_MIN();
    clear_tab();
  }
  else if (ascii[0] == 80 && ascii[10] == 65 && affichage) {
    Serial.println("PRESSURE_MAX");
    affichage = false;
    PRESSURE_MAX();
    clear_tab();
  }
  else if (ascii[0] == 67 && ascii[12] == 0 && affichage) {
    Serial.println("CLOCK");
    affichage = false;
  }
  else if (ascii[0] == 68 && ascii[2] == 84 && affichage) {
    Serial.println("DATE");
    affichage = false;
  }
  else if (ascii[0] == 68 && ascii[2] == 89 && affichage) {
    Serial.println("DAY");
    affichage = false;
  }
}

int log_intervall;
int file_max_size;
unsigned long timeout;
bool lumin;
int lumin_low;
int lumin_high;
bool temp_air;
char min_temp_air;
char max_temp_air;
bool hygr;
char hygr_mint;
char hygr_maxt;
bool pressure;
int pressure_min;
int pressure_max;
char clock[3];
char date[3];
char day[3];

void RESET() {
  log_intervall = 10;
  file_max_size = 4096;
  timeout = 30000;
  lumin = 1;
  lumin_low = 255;
  lumin_high = 768;
  temp_air = 1;
  min_temp_air = -10;
  max_temp_air = 60;
  hygr = 1;
  hygr_mint = 0;
  hygr_maxt = 50;
  pressure = 1;
  pressure_min = 850;
  pressure_max = 1080;
  clock[0] = 0;
  clock[1] = 0;
  clock[2] = 0;
  date[0] = 1;
  date[1] = 1;
  date[2] = 2000;
  day[0] = 'M';
  day[1] = 'O';
  day[2] = 'N';
}

void FILE_MAX_SIZE() {
  String file_max_size = "";
  bool test = false;
  
  if (test == false) {
    Serial.println("Valeur de FILE_MAX_SIZE (Valeur par defaut: 4096 ; Plage: {0;4096}): ");
  
    while (file_max_size == "") {
      file_max_size = userMessage();
      test = true;
    }
  }
  
  Serial.print("FILE_MAX_SIZE=");
  Serial.println(file_max_size);
}

void VERSION() {
  Serial.print("Version: ");
  Serial.println(version);
}

void TIMEOUT() {
  String timeout = "";
  bool test = false;
  
  if (test == false) {
    Serial.println("Valeur de TIMEOUT (Valeur par defaut: 30): ");
  
    while (timeout == "") {
      timeout = userMessage();
      test = true;
    }
  }
  
  Serial.print("TIMEOUT=");
  Serial.println(timeout);
}

void TEMP_AIR() {
  String temp_air = "";
  bool test = false;
  
  if (test == false) {
    Serial.println("Valeur de TEMP_AIR (Valeur par defaut: 1 ; Plage: {0;1}): ");
  
    while (temp_air == "") {
      temp_air = userMessage();
      test = true;
    }
  }
  
  Serial.print("TEMP_AIR=");
  Serial.println(temp_air);
}

void LOG_INTERVALL() {
  String log_intervall = "";
  bool test = false;
  
  if (test == false) {
    Serial.println("Valeur de LOG_INTERVALL (Valeur par defaut: 10): ");
  
    while (log_intervall == "") {
      log_intervall = userMessage();
      test = true;
    }
  }
  
  Serial.print("LOG_INTERVALL=");
  Serial.println(log_intervall);
}

void LUMIN() {
  String lumin = "";
  bool test = false;
  
  if (test == false) {
    Serial.println("Valeur de LUMIN (Valeur par defaut: 1 ; Plage: {0;1}): ");
  
    while (lumin == "") {
      lumin = userMessage();
      test = true;
    }
  }
  
  Serial.print("LUMIN=");
  Serial.println(lumin);
}

void LUMIN_LOW() {
  String lumin_low = "";
  bool test = false;
  
  if (test == false) {
    Serial.println("Valeur de LUMIN_LOW (Valeur par defaut: 255 ; Plage: {0;1023}): ");
  
    while (lumin_low == "") {
      lumin_low = userMessage();
      test = true;
    }
  }
  
  Serial.print("LUMIN_LOW=");
  Serial.println(lumin_low);
}

void LUMIN_HIGH() {
  String lumin_high = "";
  bool test = false;
  
  if (test == false) {
    Serial.println("Valeur de LUMIN_HIGH (Valeur par defaut: 768 ; Plage: {0;1023}): ");
  
    while (lumin_high == "") {
      lumin_high = userMessage();
      test = true;
    }
  }
  
  Serial.print("LUMIN_HIGH=");
  Serial.println(lumin_high);
}

void MIN_TEMP_AIR() {
  String min_temp_air = "";
  bool test = false;
  
  if (test == false) {
    Serial.println("Valeur de MIN_TEMP_AIR (Valeur par defaut: -10 ; Plage: {-40;85}): ");
  
    while (min_temp_air == "") {
      min_temp_air = userMessage();
      test = true;
    }
  }
  
  Serial.print("MIN_TEMP_AIR=");
  Serial.println(min_temp_air);
}

void MAX_TEMP_AIR() {
  String max_temp_air = "";
  bool test = false;
  
  if (test == false) {
    Serial.println("Valeur de MAX_TEMP_AIR (Valeur par defaut: 60 ; Plage: {-40;85}): ");
  
    while (max_temp_air == "") {
      max_temp_air = userMessage();
      test = true;
    }
  }
  
  Serial.print("MAX_TEMP_AIR=");
  Serial.println(max_temp_air);
}

void HYGR() {
  String hygr = "";
  bool test = false;
  
  if (test == false) {
    Serial.println("Valeur de HYGR (Valeur par defaut: 1 ; Plage: {0;1}): ");
  
    while (hygr == "") {
      hygr = userMessage();
      test = true;
    }
  }
  
  Serial.print("HYGR=");
  Serial.println(hygr);
}

void HYGR_MINT() {
  String hygr_mint = "";
  bool test = false;
  
  if (test == false) {
    Serial.println("Valeur de HYGR_MINT (Valeur par defaut: 0 ; Plage: {-40;85}): ");
  
    while (hygr_mint == "") {
      hygr_mint = userMessage();
      test = true;
    }
  }
  
  Serial.print("HYGR_MINT=");
  Serial.println(hygr_mint);
}

void HYGR_MAXT() {
  String hygr_maxt = "";
  bool test = false;
  
  if (test == false) {
    Serial.println("Valeur de HYGR_MAXT (Valeur par defaut: 50 ; Plage: {-40;85}): ");
  
    while (hygr_maxt == "") {
      hygr_maxt = userMessage();
      test = true;
    }
  }
  
  Serial.print("HYGR_MAXT=");
  Serial.println(hygr_maxt);
}

void PRESSURE() {
  String pressure = "";
  bool test = false;
  
  if (test == false) {
    Serial.println("Valeur de PRESSURE (Valeur par defaut: 1 ; Plage: {0;1}): ");
  
    while (pressure == "") {
      pressure = userMessage();
      test = true;
    }
  }
  
  Serial.print("PRESSURE=");
  Serial.println(pressure);
}

void PRESSURE_MIN() {
  String pressure_min = "";
  bool test = false;
  
  if (test == false) {
    Serial.println("Valeur de PRESSURE_MIN (Valeur par defaut: 850 ; Plage: {300;1100}): ");
  
    while (pressure_min == "") {
      pressure_min = userMessage();
      test = true;
    }
  }
  
  Serial.print("PRESSURE_MIN=");
  Serial.println(pressure_min);
}

void PRESSURE_MAX() {
  String pressure_max = "";
  bool test = false;
  
  if (test == false) {
    Serial.println("Valeur de PRESSURE_MAX (Valeur par defaut: 1080 ; Plage: {300;1100}): ");
  
    while (pressure_max == "") {
      pressure_max = userMessage();
      test = true;
    }
  }
  
  Serial.print("PRESSURE_MAX=");
  Serial.println(pressure_max);
}

String userMessage() {
  String reponse = "";
  char charac = '0';
  
  if (Serial.available() > 0) {
    while (Serial.available() > 0) {
	  charac = Serial.read();
      reponse += charac;
      delay(2);
    }
    
    return reponse;
  }

  return "";
}

int clear_tab() {
  for (n=0; n < 13; n++) {
    ascii[n] = 0;
  }
  n = 0;
}