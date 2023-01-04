#include <Arduino_BuiltIn.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include "FirebaseESP8266.h"
#include <DHT.h>
#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
#define FIREBASE_HOST "baby-5610d-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "HiXW9ku2MC96ay8Mmm2mDZJIn8VV6UROlMrrqKG1" 
#define WIFI_SSID "Galaxy A30s9E61"
#define WIFI_PASSWORD "amal2000"
WiFiClient client; 
FirebaseData firebaseData;
void setup() {
    Serial.begin(9600);
    WiFi.begin (WIFI_SSID, WIFI_PASSWORD);
      while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");}  
    Serial.println ("");
    Serial.println ("Se conectó al wifi!");
    Serial.println(WiFi.localIP());
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
    dht.begin();
    }
    void loop() {
      float t = dht.readTemperature();
      int h = dht.readHumidity(); 
      Firebase.setString(firebaseData,"temperature", String(t));  
      Firebase.setString(firebaseData,"humidity", String(h));
      }
