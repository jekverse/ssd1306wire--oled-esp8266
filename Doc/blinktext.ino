#include <Wire.h>
#include <SSD1306Wire.h>

SSD1306Wire display(0x3C, D2, D1);  // Alamat I2C, SDA, dan SCL

void setup() {
  display.init();      // Inisialisasi display OLED
  display.clear();     // Bersihkan layar OLED
  display.flipScreenVertically();
}

void loop() {

  String text = "Hello, OLED!";
  display.setFont(ArialMT_Plain_16);  // Tentukan font

  // Menghitung posisi X agar teks di tengah horizontal
  int16_t textWidth = display.getStringWidth(text);  // Lebar teks
  int16_t xPos = (128 - textWidth) / 2;  // X posisi tengah

  // Menghitung posisi Y agar teks di tengah vertikal
  int16_t yPos = (64 - 16) / 2;  // Y posisi tengah (menggunakan font 16px tinggi)

  // Gambar kotak
  display.fillRect(0, 0, 126, 63);  // x=0, y=0, lebar=126, tinggi=63
  display.display();   // Perbarui tampilan
  delay(100);          // Tunggu selama 0.5 detik

  // Hapus kotak
  display.clear();     // Bersihkan layar OLED
  display.display();   // Perbarui tampilan
  delay(100);          // Tunggu selama 0.5 detik
  // Text
  display.drawString(xPos, yPos, text);  // Tampilkan teks di posisi tengah
  display.display();     // Perbarui tampilan
  delay(2000);          // Tunggu selama 0.5 detik

  // Hapus text
  display.clear();     // Bersihkan layar OLED
  display.display();   // Perbarui tampilan
  delay(100);          // Tunggu selama 0.5 detik
}

