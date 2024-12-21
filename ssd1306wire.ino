#include <Wire.h>
#include <SSD1306Wire.h>

// Inisialisasi OLED
SSD1306Wire display(0x3C, D2, D1);

// Variabel untuk posisi bola
int ballX = 0, ballY = 0;
int ballDirectionX = 1, ballDirectionY = 1; // Arah gerakan bola

void setup() {
  display.init();
  display.clear();
}

void loop() {
  display.clear(); // Bersihkan layar sebelum menggambar

  // Gambar bola di posisi saat ini
  display.fillCircle(ballX, ballY, 5); // Bola dengan radius 5 piksel

  // Perbarui posisi bola
  ballX += ballDirectionX;
  ballY += ballDirectionY;

  // Pantulkan bola jika mencapai batas layar
  if (ballX <= 0 || ballX >= 128) {
    ballDirectionX *= -1; // Ubah arah horizontal
  }
  if (ballY <= 0 || ballY >= 64) {
    ballDirectionY *= -1; // Ubah arah vertikal
  }

  display.display(); // Tampilkan frame baru
  delay(20); // Jeda antar frame
}
