typedef struct Mesures Mesures;
    struct Mesures{
        int heure;
        int minute;
        int sec;
        int jour;
        int mois;
        int annee;
        float lumin;
        float pression;
        float temperature;
        float humidite;
    };
Mesures prisemesures(BME280I2C, DS1307);