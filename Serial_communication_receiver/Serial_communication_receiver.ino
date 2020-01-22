#include <BlynkSimpleEsp8266.h>
#include <Wire.h>
#include <ESP8266WiFi.h>
#define BLYNK_PRINT Serial
#define COMMAND_LENGTH 100  //input command

// --- Variables --- //
char command[COMMAND_LENGTH];
char c;
int sIt;
int numel;

// --- Variables analizeString --- //
float windSpeed = 0.00;
float windSpeed_kmh = 0.00;
float rainCounter = 0.00;
int windDir = 0;
float temperature = 0.00;


// ---  WiFi parameters --- //
const char* ssid = "googlewifilabs";
const char* password = "pinballmod2018";
char auth[] = "DXtEQs16HJJKCSnV7SuybTkEf0Br4n31"; 


void setup() {
  
  // Serial begin at 115200 baud
  Serial.begin(115200);
  while(!Serial){}
  
  //Establish WiFi conneCtion
  Blynk.begin(auth, ssid, password);
}

void serialEvent()
{
  while(Serial.available())
  {
    c = Serial.read();  //It starts to read the message
    if (c == 13)        //Retorno de carro (null)
    {
      command[sIt] = 0; //end of array
      numel = sIt - 1;
      sIt = 0;
      analizeString();  //it analizes the incoming command
    }
    else 
    {
      command[sIt] = c;
      sIt++;
      if (sIt == COMMAND_LENGTH) sIt = 0;
    }
  }
}

void analizeString()
{
  switch (command[0])
  {
    case 'W': // Wind speed [m/s]
    windSpeed = atof(&command[1]);
    break;
    
    case 'K': //Wind speed [km/h]
    windSpeed_kmh = atof(&command[1]);
    break;

    case 'R': //Rain counter [mm]
    rainCounter = atof(&command[1]);
    break;

    case 'D': //Wind direction [º]
    windDir = atoi(&command[1]);
    break;

    case 'T': //Temperature [ºC]
    temperature = atof(&command[1]);
    break;
  }
}

void serialPlotter()
{
  Serial.print("Datos recolectados:");
  Serial.print(" Wind speed: ");
  Serial.print(windSpeed);
  Serial.print("[m/s]- ");
  Serial.print(windSpeed_kmh);
  Serial.print("[km/h], Rain counter: ");
  Serial.print(rainCounter);
  Serial.print("[mm], Wind direction: ");
  Serial.print(windDir);
  Serial.print("[º], Temperature: ");
  Serial.print(temperature);
  Serial.println("[ºC]");
  
}

void sendUp()
{
  Blynk.virtualWrite(0, windSpeed);
  Blynk.virtualWrite(1, windSpeed_kmh);
  Blynk.virtualWrite(2, rainCounter);
  Blynk.virtualWrite(3, windDir);
  Blynk.virtualWrite(4, temperature);
}

void loop() {
  serialEvent();
  Blynk.run();
  sendUp();
  //serialPlotter();
}
