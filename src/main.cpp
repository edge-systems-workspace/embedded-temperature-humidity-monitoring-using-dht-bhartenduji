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
