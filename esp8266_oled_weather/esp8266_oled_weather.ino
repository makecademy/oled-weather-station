// Libraries
#include <ESP8266WiFi.h>
#include <Wire.h>
#include "SSD1306.h"
#include "DHT.h"

// Pins
#define SDA 4
#define SCL 5
#define I2C 0x3D

// Pin
#define DHTPIN 12

// Use DHT11
#define DHTTYPE DHT11

// Create instance
DHT dht(DHTPIN, DHTTYPE, 15);

// Create display
SSD1306 display(I2C, SDA, SCL);

void setup() {

  // Serial
  Serial.begin(115200);
  delay(10);

  // Init DHT
  dht.begin();

   // Initialize display
  display.init();
  display.flipScreenVertically();
  display.clear();
  display.display();

}

void loop() {

  // Reading temperature & humidity
  int h = dht.readHumidity();
  int t = dht.readTemperature();

  Serial.println(t);

  // Format strings for display
  String tempString = "Temperature: " + String(t) + "C" ;
  String humString = "Humidity: " + String(h) + "%" ;

  // Display on OLED
  display.clear();
  display.setFont(ArialMT_Plain_16);
  display.drawString(0, 5, tempString);
  display.drawString(0, 40, humString);
  display.display();

  // Wait 1 second
  delay(1000);
  
}
