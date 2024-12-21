### **Penjelasan Perubahan (Versi Lengkap)**

Kontrol tampilan dasar adalah langkah penting untuk memastikan layar OLED dapat berfungsi dengan optimal. Library SSD1306Wire menyediakan fungsi-fungsi yang memungkinkan pengendalian tampilan dasar, seperti menghidupkan/mematikan layar, membalik orientasi, dan mengatur kecerahan.

---

#### **1. Pengganti Fungsi `turnOff()` dan `turnOn()`**
Fungsi **`turnOff()`** dan **`turnOn()`** bertujuan untuk mematikan dan menghidupkan layar OLED. Karena fungsi ini tidak tersedia, kita dapat mencapai efek serupa dengan cara berikut:

- **"Mematikan layar" (turn off):**  
  Gunakan fungsi **`clear()`** untuk menghapus semua data dari buffer layar, lalu panggil **`display()`** untuk memperbarui layar dengan buffer kosong. Ini membuat layar tampak seperti mati karena tidak ada data yang ditampilkan, meskipun perangkat keras OLED masih aktif.

  **Kode:**
  ```cpp
  display.clear();   // Bersihkan buffer layar
  display.display(); // Tampilkan buffer kosong
  ```

- **"Menghidupkan layar" (turn on):**  
  Tampilkan kembali data atau konten ke layar dengan menambahkan data ke buffer menggunakan fungsi seperti **`drawString()`**, lalu panggil **`display()`** untuk menampilkan konten tersebut.

  **Kode:**
  ```cpp
  display.drawString(0, 0, "Layar hidup kembali");
  display.display();
  ```

#### **2. Pengganti Fungsi `dim(bool)`**
Fungsi **`dim(bool)`** digunakan untuk meredupkan layar (dim = `true`) atau mengembalikannya ke kecerahan normal (dim = `false`). Karena fungsi ini tidak tersedia, kita bisa menggunakan **`setContrast(uint8_t contrast)`**, yang memungkinkan pengaturan tingkat kecerahan layar.

- **Meredupkan layar:**  
  Atur kontras ke nilai rendah (misalnya, `50` untuk redup tetapi masih terlihat).

  **Kode:**
  ```cpp
  display.setContrast(50); // Kontras rendah untuk tampilan redup
  ```

- **Mengembalikan kecerahan normal:**  
  Atur kontras ke nilai tinggi (misalnya, `255` untuk tampilan paling terang).

  **Kode:**
  ```cpp
  display.setContrast(255); // Kontras tinggi untuk tampilan penuh
  ```
---

### **Kode Lengkap Kontrol Tampilan Dasar**

```cpp
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
```

---

### **Kesimpulan**
Pendekatan ini memberikan fleksibilitas untuk mengontrol OLED tanpa memerlukan fungsi `turnOff()`, `turnOn()`, atau `dim()`. Dengan memanfaatkan **`clear()`**, **`display()`**, dan **`setContrast()`**, kita tetap bisa mengatur tampilan layar secara efektif sesuai kebutuhan.