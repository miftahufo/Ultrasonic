//Token Blynk
#define BLYNK_TEMPLATE_ID "TMPL6EpJbYDj9"
#define BLYNK_TEMPLATE_NAME "Ultrasonic"
#define BLYNK_AUTH_TOKEN "HAS6j7Ju-qJxVjwmSty9WKHRrYS9ROUz"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "PKL AKTARA";
char pass[] = "pkl2024@";

BlynkTimer timer ;
#define pinecho D2
#define pintrig D4

void setup() {
  //*****SERIAL MONITOR, setting baud rate
  Serial.begin(115200);
  //*****ULTRASONIK, setting pin yang digunakan
  pinMode(pinecho, INPUT);
  pinMode(pintrig, OUTPUT);

  Blynk.begin(auth, ssid, pass);
 
}
void loop() {
  //********BLYNK, menjalankan blynk
  Blynk.run();
  timer.run();

  digitalWrite(pintrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pintrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pintrig, LOW);
  int duration=pulseIn(pinecho, HIGH);
  float distance=duration*0.034/2;
  Serial.print(distance); //Menampilkan jarak ke serial monitor
  Serial.println("cm");
  Blynk.virtualWrite(V0, distance); //menampilkan jarak ke blynk
  delay(2000);
}
