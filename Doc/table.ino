#include <Wire.h>              // Library untuk komunikasi I2C
#include <SSD1306Wire.h>        // Library untuk OLED SSD1306

SSD1306Wire display(0x3C, D2, D1);  // Inisialisasi objek display: Alamat I2C 0x3C, SDA di pin D2, SCL di pin D1

void setup() {
  display.init();               // Inisialisasi OLED
  display.flipScreenVertically(); // Memutar tampilan layar secara vertikal (180 derajat)
  display.clear();              // Menghapus layar OLED sebelum menampilkan teks baru
  display.setFont(ArialMT_Plain_10);

  String text = "AND GATE";
  int textWidth = display.getStringWidth(text);  // Menghitung lebar teks
  int x = (128 - textWidth) / 2;  // Menentukan posisi X untuk teks agar berada di tengah

// HORIZONRAL LINE
  display.drawLine(0, 2, 127, 2);  // Menggambar garis dari titik (0,10) ke (127,10) di layar 128x64
  display.drawLine(0, 16, 127, 16);  // Menggambar garis dari titik (0,10) ke (127,10) di layar 128x64
  display.drawLine(0, 28, 127, 28);  // Menggambar garis dari titik (0,10) ke (127,10) di layar 128x64
  display.drawLine(0, 40, 127, 40);  // Menggambar garis dari titik (0,10) ke (127,10) di layar 128x64
  display.drawLine(0, 52, 127, 52);  // Menggambar garis dari titik (0,10) ke (127,10) di layar 128x64
// HORIZONTAL TEXT
  display.drawString(x, 4, text);  // Menampilkan teks AND GATE di posisi tengah
  display.drawString(0, 17, "TRUE");  
  display.drawString(0, 29, "TRUE");  
  display.drawString(0, 41, "FALSE");  
  display.drawString(0, 53, "FALSE");  
// VERTIKAL LINE
  display.drawLine(43, 16, 43, 64);  
  display.drawLine(86, 16, 86, 64);  

// VERTICAL TEXT
  display.drawString(44, 16, "TRUE");
  display.drawString(87, 16, "TRUE");    

  display.drawString(44, 29, "FALSE");
  display.drawString(87, 29, "FALSE");

  display.drawString(44, 41, "TRUE");
  display.drawString(87, 41, "FALSE");

  display.drawString(44, 53, "FALSE");
  display.drawString(87, 53, "FALSE");
  
  display.display();            // Memperbarui tampilan OLED dengan teks yang telah digambar
}

void loop() {
  // Tidak ada proses yang perlu dijalankan dalam loop
}
