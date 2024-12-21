#include <Wire.h>
#include <SSD1306Wire.h>

// Inisialisasi OLED
SSD1306Wire display(0x3C, D2, D1); // Alamat I2C: 0x3C, SDA: D2, SCL: D1

// Fungsi untuk menggambar kotak
void drawBox(int x, int y, int width, int height, int delayMs) {
  display.fillRect(x, y, width, height); // Gambar kotak
  display.display();                     // Perbarui tampilan
  delay(delayMs);
}
void clear(){
    display.clear();
    display.display();
}
void center_text(String text, int delayMs){
    display.setFont(ArialMT_Plain_16);  // Tentukan font
    display.setTextAlignment(TEXT_ALIGN_CENTER);
    display.drawString(64, 24, text);
    display.display();
    delay(delayMs);
}

void setup() {
  display.init();
  display.clear(); // Bersihkan layar1
  display.flipScreenVertically();

}

void loop() {
  drawBox(0, 0, 126, 63, 100);
  clear();
  center_text("Welcome", 2000);
  clear();

  drawBox(0, 0, 126, 63, 100);
  clear();
  center_text("To Sahara", 2000);
  clear();

  drawBox(0, 0, 126, 63, 100);
  clear();
  center_text("BitcH", 2000);
  clear();
}
