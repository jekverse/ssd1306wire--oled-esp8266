#include <Wire.h>
#include <SSD1306Wire.h>

// Inisialisasi OLED
SSD1306Wire display(0x3C, D2, D1);

// Variabel untuk posisi objek
int posX = 0, posY = 20;

void setup() {
  display.init();
  display.clear();
}

void loop() {
  // Langkah 1: Bersihkan buffer
  display.clear();

  // Langkah 2: Gambar elemen di buffer
  display.drawString(0, 0, "Buffer Handling Example");
  display.drawCircle(posX, posY, 10);

  // Langkah 3: Tampilkan buffer ke layar
  display.display();

  // Langkah 4: Perbarui posisi objek
  posX += 2;
  if (posX > 128) posX = 0; // Reset posisi jika melewati layar

  delay(50); // Jeda antar frame
}
