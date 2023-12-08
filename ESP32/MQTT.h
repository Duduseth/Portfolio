#include <WiFi.h>
#include <PubSubClient.h>

#define DEBUG

#define pinG 12   //pino de saida para acionamento do led Verde
#define pinR 32 //pino de saida para acionamento do led Vermelho

//informações da rede WIFI
const char* ssid = "Esp";                 //SSID da rede WIFI
const char* password =  "Tchacarai";    //senha da rede wifi

// MQTT Broker
const char* mqttServer = "broker.emqx.io";  //Host do broket
const int mqttPort = 1883;                 //Porta
const char* mqttUser = "";                //Usuario
const char* mqttPassword = "";           //Senha
const char* mqttTopicSub = "EDER/teste";         //Topico a ser subscrito e publicado

WiFiClient espClient;
PubSubClient client(espClient);
/*
void setup() {
 
  Serial.begin(9600);
  pinMode(pinG, OUTPUT);
  pinMode(pinR, OUTPUT);
  //pinMode(ledint, LED_BUILTIN);
  digitalWrite(pinG, HIGH);
  digitalWrite(pinR, HIGH);
  //digitalWrite(ledint, LOW);
  
  
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    #ifdef DEBUG
    Serial.println("Conectando ao WiFi..");
    #endif
  }
  #ifdef DEBUG
  Serial.println("Conectado na rede WiFi");
  #endif
 
  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);
 
  while (!client.connected()) {
    #ifdef DEBUG
    Serial.println("Conectando ao Broker MQTT...");
    #endif
 
    if (client.connect("ESP32Client", mqttUser, mqttPassword )) {
      #ifdef DEBUG
      Serial.println("Conectado");  
      #endif
 
    } else {
      #ifdef DEBUG 
      Serial.print("falha estado  ");
      Serial.print(client.state());
      #endif
      delay(2000);
 
    }
  }

  //subscreve no tópico
  client.subscribe(mqttTopicSub);
 
}
 */
void callback(char* topic, byte* payload, unsigned int length) {

  //armazena msg recebida em uma sring
  payload[length] = '\0';
  String strMSG = String((char*)payload);

  #ifdef DEBUG
  Serial.print("Mensagem chegou do topico: ");
  Serial.println(topic);
  Serial.print("Mensagem:");
  Serial.print(strMSG);
  Serial.println();
  Serial.println("-----------------------");
  #endif

  //aciona saída conforme msg recebida 
  if (strMSG == "2"){         //se msg "rele1_on"
     digitalWrite(pinG, LOW);  //coloca saída em LOW para ligar
  }else if (strMSG == "3"){   //se msg "rele1_off"
     digitalWrite(pinG, HIGH);   //coloca saída em HIGH para desligar
  }else if (strMSG == "4"){   //se msg "rele1_off"
     digitalWrite(pinR, LOW);   //coloca saída em HIGH para desligar
  }else if (strMSG == "5"){   //se msg "rele1_off"
     digitalWrite(pinR, HIGH);   //coloca saída em HIGH para desligar
  }
}

//função pra reconectar ao servido MQTT
void reconect() {
  //Enquanto estiver desconectado
  while (!client.connected()) {
    #ifdef DEBUG
    Serial.print("Tentando conectar ao servidor MQTT");
    #endif
     
    bool conectado = strlen(mqttUser) > 0 ?
                     client.connect("ESP32Client", mqttUser, mqttPassword) :
                     client.connect("ESP32Client");

    if(conectado) {
      #ifdef DEBUG
      Serial.println("Conectado!");
      #endif
      //subscreve no tópico
      client.subscribe(mqttTopicSub, 1); //nivel de qualidade: QoS 1
    } else {
      #ifdef DEBUG
      Serial.println("Falha durante a conexão.Code: ");
      Serial.println( String(client.state()).c_str());
      Serial.println("Tentando novamente em 10 s");
      #endif
      //Aguarda 10 segundos 
      delay(10000);
    }
  }
}
 /*
void loop() {
  if (!client.connected()) {
    reconect();
  }
  client.loop();
}
*/
