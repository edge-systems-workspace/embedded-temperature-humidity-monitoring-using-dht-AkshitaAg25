#include <Arduino.h>
/**
 * @file main.cpp
 * @brief Embedded Temperature and Humidity Monitoring using DHT11
 * @author AkshitaAg25
 * @date 2026-02-19
 *
 * @details
 * This program reads environmental data from the DHT11 sensor
 * and displays temperature and humidity values on Serial Monitor.
 * Students must complete the TODO sections.
 */

#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11
int DHT11;
DHT obj = DHT(DHTPIN, DHTTYPE);

void setup() {
    // write your initialization code here
    Serial.begin(9600);
    obj.begin();
    Serial.println("DHT11 Sensor initialized");
}

void loop() {
    // write your code here
    float temperature = obj.readTemperature();
    float humidity = obj.readHumidity();
    if (isnan(temperature) || isnan(humidity)) {
        Serial.println("Failed to read from DHT sensor!");
        delay(5000);
        return;
    }
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" *C");
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println("% | ");
    delay(5000);
}
