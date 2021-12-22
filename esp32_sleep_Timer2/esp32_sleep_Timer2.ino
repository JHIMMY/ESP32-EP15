/**********************************************************************************
 * TITULO: Deep Sleep demo 2
 * AUTOR: Jhimmy Astoraque Durán
 * DESCRIPCION: Este script conecta el esp32 a una red wifi para hacer un request a una URL, imprimirla a través del
 *              monitor serial para luego entrar a modo de sueño profundo por un tiempo definido por el programador.
 *              Este proceso ocurrirá en forma de bucle indefinido.
 * CANAL YOUTUBE: https://www.youtube.com/c/jadsatv
 * © 2022
 * *******************************************************************************/

#include <WiFi.h>
#include <HTTPClient.h>
 
const char* ssid = "JADSA CORP";
const char* password = "Taquiperenda2021";

const uint8_t ledPin = 25;
const uint32_t sleepTime = 5 * 1000000; // uS

void setup(){
  //Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  WiFi.begin(ssid, password);
  delay(500);

  //Serial.println("\nDespertando y Conectando a la red WiFi...");
  digitalWrite(ledPin, HIGH);
  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    //Serial.print(".");
  }
  //Serial.println("\nConectado a la Red!\n");
  getOnlineData();


  digitalWrite(ledPin, LOW);
  //Serial.println("Esp entrando a modo sueño profundo");
  //Serial.flush();
  esp_sleep_enable_timer_wakeup(sleepTime);
  esp_deep_sleep_start();
}

void loop(){  
}


void getOnlineData(){
  HTTPClient http;
 
    http.begin("http://example.com/");
    int httpCode = http.GET();
 
    if (httpCode > 0) { 
 
        String payload = http.getString();
        //Serial.println(httpCode);
        //Serial.println(payload);
    }
    else {
      //Serial.println("Falla en el requerimiento http");
    }
 
    http.end(); // liberamos recursos
}
