# Sistema de Climatização e Iluminação Inteligente

## Descrição  
Este projeto é um **sistema de climatização e iluminação inteligente** desenvolvido com a plataforma **Arduino IoT Cloud** e uma **ESP32**. Ele permite monitorar e controlar as condições ambientais de um ambiente doméstico ou comercial, com foco em oferecer conforto e automação.  
Com este sistema, é possível:
- **Monitorar** a temperatura, umidade e luminosidade do ambiente em tempo real.  
- **Controlar** remotamente a lâmpada e o ventilador, usando comandos pela interface da Arduino IoT Cloud.  
- **Automatizar** ações para melhorar a eficiência energética e proporcionar maior comodidade.

---

## Componentes e Hardware Utilizados  
- **ESP32:** Microcontrolador responsável pela execução do sistema e comunicação com a Arduino IoT Cloud.  
- **Sensor DHT22:** Realiza a leitura de temperatura e umidade do ambiente.  
- **Sensor LDR:** Mede a luminosidade do ambiente.  
- **Relé (x2):** Um para controlar a lâmpada e outro para controlar o ventilador.  
- **Conexão Wi-Fi:** Utilizada para enviar e receber dados em tempo real com a nuvem.  

---

## Bibliotecas Utilizadas  
- **`DHT.h`**: Biblioteca necessária para operar o sensor DHT22 e realizar leituras de temperatura e umidade.  
- **`thingProperties.h`**: Gerencia a integração entre a ESP32 e a plataforma Arduino IoT Cloud, permitindo que as propriedades (como temperatura e status dos dispositivos) sejam enviadas e controladas remotamente.  

---

## Funcionalidades  
### Monitoramento  
- **Temperatura e Umidade:** O sensor DHT22 faz a leitura periódica do ambiente e envia os dados para a Arduino IoT Cloud, onde podem ser visualizados.  
- **Luminosidade:** O sensor LDR mede a intensidade de luz, convertendo-a em uma escala de 0 a 100%, para fácil interpretação.

### Controle Remoto  
- **Lâmpada e Ventilador:** O sistema permite ligar e desligar ambos remotamente pela interface da Arduino IoT Cloud.  
- **Ações Automatizadas:** A integração com a nuvem permite definir automações, como acender a lâmpada quando a luminosidade estiver baixa ou ligar o ventilador em dias quentes.  

### Sincronização com a Nuvem  
- A cada ciclo de execução, a ESP32 sincroniza os dados e comandos com a Arduino IoT Cloud, garantindo que as leituras e controles sejam atualizados em tempo real.  

---

## Como Montar o Sistema  
1. **Conecte os Componentes:**
   - Sensor DHT22 no pino 5 da ESP32.
   - Sensor LDR no pino analógico 33 da ESP32.
   - Relé da lâmpada no pino 23 e do ventilador no pino 22.  
2. **Realize o Upload do Código:**  
   - Use a Arduino IDE ou outro ambiente compatível para programar a ESP32 com o código do projeto.  
3. **Configure a Arduino IoT Cloud:**  
   - Crie um projeto e vincule as propriedades para temperatura, umidade, luminosidade e controle dos dispositivos.  
   - Adicione a ESP32 como dispositivo e conecte-a ao projeto.  
4. **Acesse a Interface da Nuvem:**  
   - Use o painel da Arduino IoT Cloud para visualizar as leituras e controlar os dispositivos.

---

## Possíveis Melhorias  
- **Automação Avançada:**  
  - Ligar o ventilador automaticamente em uma determinada faixa de temperatura.  
  - Acender a lâmpada em horários programados ou quando a luminosidade estiver baixa.  
- **Notificações:**  
  - Envio de alertas por e-mail ou mensagem quando a temperatura ou umidade ultrapassar limites predefinidos.  
- **Integração com Assistentes Virtuais:**  
  - Controle dos dispositivos via **Google Assistant** ou **Amazon Alexa**.  
- **Aplicativo Móvel:**  
  - Desenvolvimento de um app para facilitar o controle e monitoramento fora do painel da Arduino IoT Cloud.

---

## Conclusão  
Este projeto de **Sistema de Climatização e Iluminação Inteligente** apresenta uma forma simples e eficaz de automatizar o controle de temperatura, umidade e iluminação de um ambiente. A integração com a Arduino IoT Cloud proporciona controle remoto e monitoramento em tempo real, além de possibilitar futuras expansões e personalizações para atender às necessidades específicas de cada usuário.

---
