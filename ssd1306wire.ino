#include <Wire.h>
#include <SSD1306Wire.h>

SSD1306Wire display(0x3C, D2, D1);  // Alamat I2C, SDA, dan SCL

void setup() {
  display.init();
  display.clear();
}

void loop() {
  // Array teks
  String texts[] = {"Hello, World!", "ESP8266 Rocks!"};

  for (int i = 0; i < 2; i++) {
    display.clear();
    display.setFont(ArialMT_Plain_16);

    // Hitung posisi tengah
    int16_t xPos = (128 - display.getStringWidth(texts[i])) / 2;
    int16_t yPos = (64 - 16) / 2;

    // Tampilkan teks
    display.drawString(xPos, yPos, texts[i]);
    display.display();

    delay(1000);  // Tunggu 1 detik
  }
}
