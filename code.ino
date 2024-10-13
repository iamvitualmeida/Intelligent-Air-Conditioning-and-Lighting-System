#include "thingProperties.h"  // Inclui as propriedades definidas para o Arduino IoT Cloud.
#include "DHT.h"               // Biblioteca para sensores DHT.

#define DHTPIN 5               // Define o pino de dados do sensor DHT.
#define DHTTYPE DHT22          // Define o tipo de sensor como DHT22.
DHT dht(DHTPIN, DHTTYPE);      // Inicializa o sensor DHT com o pino e tipo definidos.

#define LDR 33                 // Define o pino de entrada para o sensor de luminosidade (LDR).
#define releLampada 23          // Define o pino de controle do relé da lâmpada.
#define releVentilador 22       // Define o pino de controle do relé do ventilador.

void setup() {
  Serial.begin(9600);          // Inicializa a comunicação serial com uma taxa de 9600 bps.
  delay(1500);                 // Aguarda 1,5 segundos para garantir a inicialização.
  
  initProperties();            // Inicializa as propriedades definidas no Arduino IoT Cloud.
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);  // Conecta ao Arduino IoT Cloud.
  setDebugMessageLevel(2);     // Define o nível de mensagens de depuração.
  ArduinoCloud.printDebugInfo(); // Exibe informações de depuração sobre a conexão.

  dht.begin();                 // Inicializa o sensor DHT.
  pinMode(LDR, INPUT);          // Define o pino do LDR como entrada.
  pinMode(releLampada, OUTPUT); // Define o pino do relé da lâmpada como saída.
  pinMode(releVentilador, OUTPUT); // Define o pino do relé do ventilador como saída.
}

void loop() {
  ArduinoCloud.update();  // Atualiza o estado das propriedades na nuvem.

  umidade = dht.readHumidity();  // Lê a umidade do sensor DHT.
  temperatura = dht.readTemperature();  // Lê a temperatura do sensor DHT.
  
  int leituraluminosidade = analogRead(LDR);  // Lê o valor analógico do LDR.
  luminosidade = map(leituraluminosidade, 4063, 32, 0, 100);  
  // Mapeia o valor lido para uma escala de 0 a 100 (por exemplo, % de luminosidade).
}

// Função chamada automaticamente quando o status da lâmpada muda na nuvem.
void onStatusLampadaChange()  {
  if(statusLampada == HIGH){  
    digitalWrite(releLampada, HIGH);  // Liga a lâmpada.
  } else {
    digitalWrite(releLampada, LOW);   // Desliga a lâmpada.
  }
}

// Função chamada automaticamente quando o status do ventilador muda na nuvem.
void onStatusVentiladorChange()  {
  if(statusVentilador == HIGH){
    digitalWrite(releVentilador, HIGH);  // Liga o ventilador.
  } else {
    digitalWrite(releVentilador, LOW);   // Desliga o ventilador.
  }
}