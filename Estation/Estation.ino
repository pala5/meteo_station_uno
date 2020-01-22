#include <math.h>
#include <SoftwareSerial.h>

//Started SoftwareSerial at RX and TX pin of Arduino UNO
SoftwareSerial Uno(1,0);

// --- PINES --- //
const int RAIN = 2;
const int WSPEED = 3;
const int WDIR = A1;
const int TEMP = A0;

// --- CONSTANTES --- //
const float pi = 3.14159265;
int period = 500;     //milliseconds
int delaytime = 2000; //milliseconds
int radio = 93; //mm

// --- VARIABLES GLOBALES --- //
int sample = 0;
int windCounter = 0;
float rainCounter = 0.00;
int windDir = 0;
float windSpeed = 0.00;
float windSpeed_kmh = 0.00;
float speedWind = 0.00;
volatile long lastWindIRQ = 0;
const int B = 4275;     // value of the thermistor
const int R0 = 100000;  // value of the resistor
float temperature = 0.00; 


void setup() {
  //Uno Begin at115200 Baud
  Uno.begin(115200);
  while(!Uno){}
  //Serial Begin at 115200 Baud
//  Serial.begin(115200);
//  while(!Serial){}

  pinMode(RAIN, INPUT_PULLUP);
  pinMode(WSPEED, INPUT_PULLUP);
  // Interrupciones
  attachInterrupt(digitalPinToInterrupt(WSPEED), wspeedirq, RISING);
  attachInterrupt(digitalPinToInterrupt(RAIN), rainirq, RISING);
}

void loop() {

  // Get parameters //
  windVelocity();
  calcSpeed();
  windSpeed_kmh = windSpeed * 3.6;
  windDir = wind_direction();
  get_temperature();

  // UNO communication //
  uno_communication();
  
  // Serial communication //
//  Serial.print('W');
//  Serial.print(windSpeed);
//  Serial.print('K');
//  Serial.print(windSpeed_kmh);
//  Serial.print('R');
//  Serial.print(rainCounter);
//  Serial.print('D');
//  Serial.print(windDir);
//  Serial.print('T');
//  Serial.println(temperature);


  delay(100);
}
