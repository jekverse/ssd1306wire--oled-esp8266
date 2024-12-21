#include <Wire.h>
#include <SSD1306Wire.h>

SSD1306Wire display(0x3C, D2, D1);  // Alamat I2C, SDA, dan SCL

void setup() {
  display.init();      // Inisialisasi display OLED
  display.clear();     // Bersihkan layar OLED
  display.flipScreenVertically();
}

void loop() {
  display.setFont(ArialMT_Plain_16);  // Tentukan font
  display.setTextAlignment(TEXT_ALIGN_CENTER);

  // Gambar kotak
  display.fillRect(0, 0, 126, 63);  // x=0, y=0, lebar=126, tinggi=63
  display.display();   // Perbarui tampilan
  delay(100);          // Tunggu selama 0.5 detik

  // Hapus kotak
  display.clear();     // Bersihkan layar OLED
  display.display();   // Perbarui tampilan
  delay(100);          // Tunggu selama 0.5 detik
  // Text
  display.drawString(64, 24, "Welcome");
  display.display();     // Perbarui tampilan
  delay(2000);          // Tunggu selama 0.5 detik

  // Hapus text
  display.clear();     // Bersihkan layar OLED
  display.display();   // Perbarui tampilan
  delay(100);          // Tunggu selama 0.5 detik

  // Gambar kotak
  display.fillRect(0, 0, 126, 63);  // x=0, y=0, lebar=126, tinggi=63
  display.display();   // Perbarui tampilan
  delay(100);          // Tunggu selama 0.5 detik

  // Hapus kotak
  display.clear();     // Bersihkan layar OLED
  display.display();   // Perbarui tampilan
  delay(100);          // Tunggu selama 0.5 detik
  // Text
  display.drawString(64, 24, "TO SAHARA");
  display.display();     // Perbarui tampilan
  delay(2000);          // Tunggu selama 0.5 detik

  // Hapus text
  display.clear();     // Bersihkan layar OLED
  display.display();   // Perbarui tampilan
  delay(100);          // Tunggu selama 0.5 detik


  // Gambar kotak
  display.fillRect(0, 0, 126, 63);  // x=0, y=0, lebar=126, tinggi=63
  display.display();   // Perbarui tampilan
  delay(100);          // Tunggu selama 0.5 detik

  // Hapus kotak
  display.clear();     // Bersihkan layar OLED
  display.display();   // Perbarui tampilan
  delay(100);          // Tunggu selama 0.5 detik
  // Text
  display.drawString(64, 24, "BitCH");
  display.display();     // Perbarui tampilan
  delay(2000);          // Tunggu selama 0.5 detik

  // Hapus text
  display.clear();     // Bersihkan layar OLED
  display.display();   // Perbarui tampilan
  delay(100);          // Tunggu selama 0.5 detik
}

