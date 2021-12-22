/**********************************************************************************
 * TITULO: Deep Sleep demo 1
 * AUTOR: Jhimmy Astoraque Durán
 * DESCRIPCION: Este sencillo sketch demuestra como iniciar el modo de sueño profundo en un Esp32, despertarlo
 *              con el Timer y además llevar control del número de veces que el dispositivo se ha despertado.
 * CANAL YOUTUBE: https://www.youtube.com/c/jadsatv
 * © 2022
 * *******************************************************************************/

const uint8_t ledPin = 25;
const uint16_t ledBlinkTime = 350;
const uint32_t sleepTime = 4 * 1000000; // uS

RTC_DATA_ATTR int wakeUps = 0;


void setup(){
  pinMode(ledPin, OUTPUT);
  delay(500);
  
  wakeUps++;
  for (int i = 0; i < wakeUps; i++)
  {
      digitalWrite(ledPin, HIGH);
      delay(ledBlinkTime);
      digitalWrite(ledPin, LOW);
      delay(ledBlinkTime);
  }

  esp_sleep_enable_timer_wakeup(sleepTime);
  esp_deep_sleep_start();
}

void loop(){
  
}
