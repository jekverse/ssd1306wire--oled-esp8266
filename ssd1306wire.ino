#include <Wire.h>
#include <SSD1306Wire.h>

// Inisialisasi OLED
SSD1306Wire display(0x3C, D2, D1); // Alamat I2C: 0x3C, SDA: D2, SCL: D1

void setup() {
  display.init();
  display.clear(); // Bersihkan layar
  display.flipScreenVertically();

  display.setFont(ArialMT_Plain_10); 
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.drawStringMaxWidth(64, 0, 30, "Teks dengan batas lebar 30 piksel!");

  // Tampilkan semua teks
  display.display();
}

void loop() {
  // Tidak ada aksi di loop
}