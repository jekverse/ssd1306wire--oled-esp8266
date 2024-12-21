#include <Wire.h>
#include <SSD1306Wire.h>

SSD1306Wire display(0x3C, D2, D1);  // Alamat I2C, SDA, dan SCL

void setup() {
  display.init();
  display.clear();
  
  // Menggambar persegi panjang terisi (x, y, lebar, tinggi)
  display.fillRect(10, 10, 100, 50);  // x=10, y=10, lebar=100, tinggi=50
  display.display();
}

void loop() {}
