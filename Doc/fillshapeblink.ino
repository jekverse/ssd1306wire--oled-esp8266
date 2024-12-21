#include <Wire.h>
#include <SSD1306Wire.h>

SSD1306Wire display(0x3C, D2, D1);  // Alamat I2C, SDA, dan SCL

void setup() {
  display.init();      // Inisialisasi display OLED
  display.clear();     // Bersihkan layar OLED
}

void loop() {
  // Gambar kotak
  display.fillRect(0, 0, 126, 63);  // x=0, y=0, lebar=126, tinggi=63
  display.display();   // Perbarui tampilan
  delay(100);          // Tunggu selama 0.5 detik

  // Hapus kotak
  display.clear();     // Bersihkan layar OLED
  display.display();   // Perbarui tampilan
  delay(100);          // Tunggu selama 0.5 detik
}
