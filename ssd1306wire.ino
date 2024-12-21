#include <Wire.h>
#include <SSD1306Wire.h> // Library SSD1306Wire

// Inisialisasi OLED
SSD1306Wire display(0x3C, D2, D1); // Alamat I2C: 0x3C, SDA: D2, SCL: D1

void setup() {
  Serial.begin(115200);

  // Inisialisasi layar
  display.init();
  display.clear(); // Bersihkan layar
  display.display();

  // Menampilkan pesan awal
  display.drawString(0, 0, "Kontrol Dasar OLED");
  display.display();
  delay(2000);
}

void loop() {
  // 1. "Mematikan" layar dengan membersihkan konten
  display.clear();
  display.display();
  Serial.println("Layar dimatikan (buffer dikosongkan)");
  delay(2000);

  // 2. "Menghidupkan" layar dengan menampilkan konten
  display.drawString(0, 0, "Layar hidup kembali");
  display.display();
  Serial.println("Layar dihidupkan");
  delay(2000);

  // 3. Meredupkan layar dengan kontras rendah
  display.setContrast(50);
  display.drawString(0, 16, "Kontras rendah");
  display.display();
  Serial.println("Kontras rendah");
  delay(2000);

  // 4. Mengembalikan kecerahan normal
  display.setContrast(255);
  display.drawString(0, 32, "Kontras normal");
  display.display();
  Serial.println("Kontras normal");
  delay(2000);

  // 5. Membersihkan layar dan menampilkan pesan akhir
  display.clear();
  display.drawString(0, 0, "Demo selesai!");
  display.display();
  delay(2000);
}
