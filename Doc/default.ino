#include <Wire.h>              // Library untuk komunikasi I2C
#include <SSD1306Wire.h>        // Library untuk OLED SSD1306

SSD1306Wire display(0x3C, D2, D1);  // Inisialisasi objek display: Alamat I2C 0x3C, SDA di pin D2, SCL di pin D1

void setup() {
  display.init();               // Inisialisasi OLED
  display.flipScreenVertically(); // Memutar tampilan layar secara vertikal (180 derajat)
  display.clear();              // Menghapus layar OLED sebelum menampilkan teks baru
  display.setFont(ArialMT_Plain_16);  // Menentukan font untuk teks (ukuran 16)
  display.drawString(0, 0, "HALLO DUNIAA!");  // Menampilkan teks pada posisi (0, 0) di layar OLED
  display.display();            // Memperbarui tampilan OLED dengan teks yang telah digambar
}

void loop() {
  // Tidak ada proses yang perlu dijalankan dalam loop
}
