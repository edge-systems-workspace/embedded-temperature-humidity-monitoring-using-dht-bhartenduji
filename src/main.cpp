/**
 * @file main.cpp
 * @brief Reads DHT11 temperature/humidity and displays values on an SSD1306 OLED.
 *
 * Wiring assumptions:
 * - DHT11 data pin on Arduino digital pin 2 (DHTPIN).
 * - SSD1306 OLED on I2C address 0x3C.
 *
 * Timing assumptions:
 * - DHT11 requires ~2s between reads (enforced in loop).
 */
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

/** @brief OLED width in pixels. */
#define SCREEN_WIDTH 128
/** @brief OLED height in pixels. */
#define SCREEN_HEIGHT 64
/** @brief OLED reset pin; -1 uses shared reset (no dedicated pin). */
#define OLED_RESET -1
/** @brief SSD1306 display instance on the default I2C bus. */
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

/** @brief DHT11 data pin (Arduino digital pin 2). */
#define DHTPIN 2
/** @brief DHT sensor type (DHT11). */
#define DHTTYPE DHT11   // Changed to DHT11
/** @brief DHT sensor instance. */
DHT dht(DHTPIN, DHTTYPE);

/**
 * @brief Arduino setup hook.
 *
 * Initializes serial logging, the DHT sensor, and the SSD1306 OLED.
 * Displays a short splash screen and halts if the OLED is not detected.
 */
void setup() {
    Serial.begin(9600);
    dht.begin();

    // Initialize OLED
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println("OLED not found");
        while (1);
    }

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.println("DHT11 Sensor");
    display.display();
    delay(2000);
}

