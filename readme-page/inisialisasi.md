### **1. Inisialisasi dan Konfigurasi OLED dengan Library SSD1306Wire**

Inisialisasi dan konfigurasi OLED adalah langkah pertama sebelum OLED dapat digunakan untuk menampilkan data. Dalam library **SSD1306Wire**, terdapat beberapa fungsi penting untuk inisialisasi dan konfigurasi OLED, terutama dalam mengatur protokol komunikasi, ukuran layar, dan orientasi.

---

#### **Fungsi Utama dalam Inisialisasi dan Konfigurasi**

1. **`SSD1306Wire` Constructor**  
   Digunakan untuk membuat instance OLED dengan parameter konfigurasi utama:
   - **address**: Alamat I2C OLED (default: `0x3C`).
   - **sda_pin**: Pin SDA (I2C data) pada ESP8266.
   - **scl_pin**: Pin SCL (I2C clock) pada ESP8266.
   - **geometry** (opsional): Ukuran layar, seperti `GEOMETRY_128_64` atau `GEOMETRY_128_32`.
   - **reset_pin** (opsional): Pin reset jika digunakan. Jika tidak, gunakan -1.

   **Contoh:**
   ```cpp
   SSD1306Wire display(0x3C, D2, D1); // Alamat I2C: 0x3C, SDA: D2, SCL: D1
   ```

2. **`init()`**  
   Menginisialisasi tampilan OLED berdasarkan konfigurasi yang diberikan di konstruktor.

   **Contoh:**
   ```cpp
   display.init(); // Menginisialisasi OLED
   ```

3. **`resetDisplay()`**  
   Mengatur ulang (reset) OLED, berguna untuk memulai layar dalam kondisi default.

   **Contoh:**
   ```cpp
   display.resetDisplay(); // Mereset layar OLED
   ```

4. **`setContrast(uint8_t contrast)`**  
   Mengatur tingkat kecerahan layar (nilai: 0-255).  
   **Tanpa fungsi ini**, layar akan menggunakan pengaturan default.

   **Contoh:**
   ```cpp
   display.setContrast(128); // Mengatur kontras ke nilai tengah
   ```

5. **`flipScreenVertically()`**  
   Membalik orientasi layar secara vertikal.  
   **Tanpa fungsi ini**, layar menggunakan orientasi default.

   **Contoh:**
   ```cpp
   display.flipScreenVertically(); // Membalik layar
   ```

6. **`setBrightness()`**  
   Fungsi untuk mengatur kecerahan layar. **Alternatif jika tidak menggunakan `setContrast()`**.  
   Namun, lebih jarang digunakan karena tergantung hardware tertentu.

---

#### **Kode Lengkap untuk Inisialisasi**
Berikut contoh implementasi langkah-langkah inisialisasi:

```cpp
#include <Wire.h>
#include <SSD1306Wire.h> // Library SSD1306Wire

// Buat instance OLED
SSD1306Wire display(0x3C, D2, D1); // Alamat I2C: 0x3C, SDA: D2, SCL: D1

void setup() {
  Serial.begin(115200);
  
  // 1. Inisialisasi layar
  display.init();
  Serial.println("OLED initialized.");
  
  // 2. Reset layar (opsional)
  display.resetDisplay();
  Serial.println("OLED reset.");

  // 3. Konfigurasi tambahan
  display.flipScreenVertically(); // Membalik layar
  display.setContrast(200);       // Kontras tinggi
}

void loop() {
  // Membersihkan layar
  display.clear();

  // Menampilkan teks sederhana
  display.drawString(0, 0, "Hello, OLED!");
  display.display(); // Update tampilan

  delay(1000);
}
```

---

#### **Perbandingan Menggunakan dan Tidak Menggunakan Fungsi Tertentu**

1. **Tanpa `resetDisplay()`**  
   Jika tidak menggunakan `resetDisplay()`, OLED mungkin menampilkan artefak atau data sisa jika sebelumnya digunakan. Dengan fungsi ini, OLED dimulai dalam kondisi bersih.

2. **Tanpa `setContrast()`**  
   Tanpa mengatur kontras, OLED menggunakan pengaturan default, yang mungkin terlalu terang atau redup untuk kebutuhan tertentu.

3. **Tanpa `flipScreenVertically()`**  
   Tanpa fungsi ini, layar tetap dalam orientasi default. Jika perangkat keras dipasang terbalik, teks/gambar tidak akan terlihat dengan benar.

4. **Hanya `init()`**  
   Jika hanya menggunakan `init()`, OLED dapat bekerja dengan baik, tetapi tidak ada penyesuaian khusus seperti orientasi atau kontras.

---

#### **Hasil Praktek**
- Jika semua fungsi di atas digunakan, layar OLED akan tampil dengan konfigurasi optimal (orientasi, kontras, dan reset).
- Jika sebagian fungsi dilewatkan, hasilnya mungkin kurang optimal atau memerlukan debugging tambahan.

Bagaimana jika kita coba mengimplementasikan kode ini dan melihat hasilnya pada OLED Anda? 😊