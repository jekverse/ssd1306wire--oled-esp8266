#include <Wire.h>
#include <SSD1306Wire.h>

// Inisialisasi OLED
SSD1306Wire display(0x3C, D2, D1);

// Variabel untuk posisi teks
int textX = 0;
int textDirection = 1; // 1 untuk ke kanan, -1 untuk ke kiri

void setup() {
  display.init();
  display.clear();
  display.setFont(ArialMT_Plain_10); // Mengatur font
  display.setTextAlignment(TEXT_ALIGN_LEFT);
}

void loop() {
  display.clear(); // Bersihkan layar sebelum menggambar

  // Gambar teks di posisi saat ini
  display.drawString(textX, 20, "Hello, Animasi!");

  // Perbarui posisi teks
  textX += textDirection;

  // Pantulkan teks jika mencapai batas layar
  if (textX < 0 || textX > 128) {
    textDirection *= -1; // Ubah arah gerakan
  }

  display.display(); // Tampilkan frame baru
  delay(30); // Jeda antar frame
}
