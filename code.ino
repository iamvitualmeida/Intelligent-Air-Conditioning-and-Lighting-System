#include "thingProperties.h"

#include "DHT.h"
#define DHTPIN 5
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

#define LDR 33
#define releLampada 23
#define releVentilador 22

void setup() {
  Serial.begin(9600);  
  delay(1500); 
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();

  dht.begin();
  pinMode(LDR, INPUT);
  pinMode(releLampada, OUTPUT);
  pinMode(releVentilador, OUTPUT);
}

void loop() {
  ArduinoCloud.update();

  umidade = dht.readHumidity();
  temperatura = dht.readTemperature();
  int leituraluminosidade = analogRead(LDR);
  luminosidade = map(leituraluminosidade, 4063, 32, 0 ,100);
    
}

void onStatusLampadaChange()  {
  if(statusLampada == HIGH){
   digitalWrite(releLampada, HIGH);
 }
  else{
   digitalWrite(releLampada, LOW);
 }
}

void onStatusVentiladorChange()  {
  if(statusVentilador == HIGH){
   digitalWrite(releVentilador, HIGH);
 }
  else{
   digitalWrite(releVentilador, LOW);
 }
}
