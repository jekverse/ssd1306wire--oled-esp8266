# **2. Kontrol Tampilan Dasar dengan SSD1306Wire**

Kontrol tampilan dasar adalah langkah penting untuk memastikan layar OLED dapat berfungsi dengan optimal. Library **SSD1306Wire** menyediakan fungsi-fungsi yang memungkinkan pengendalian tampilan dasar, seperti menghidupkan/mematikan layar, membalik orientasi, dan mengatur kecerahan.

---

#### **Fungsi Kontrol Dasar yang Disediakan**

1. **`display()`**  
   - Menampilkan semua data dari buffer ke layar OLED.  
   - Tanpa fungsi ini, perubahan pada buffer tidak akan terlihat di layar.  
   **Contoh:**
   ```cpp
   display.display();
   ```

2. **`clear()`**  
   - Membersihkan layar (buffer), menghapus semua konten yang ditampilkan.  
   - **Tanpa fungsi ini**, data sebelumnya tetap ditampilkan.  
   **Contoh:**
   ```cpp
   display.clear();
   ```

3. **`turnOn()`**  
   - Menghidupkan layar OLED tanpa memutus daya.  
   - **Tanpa fungsi ini**, layar mungkin tetap mati jika sebelumnya dinonaktifkan.  
   **Contoh:**
   ```cpp
   display.turnOn();
   ```

4. **`turnOff()`**  
   - Mematikan layar OLED tanpa memutus daya.  
   - Berguna untuk hemat daya.  
   **Contoh:**
   ```cpp
   display.turnOff();
   ```

5. **`dim(bool)`**  
   - Mengaktifkan mode hemat daya dengan meredupkan layar.  
   - Nilai `true` untuk redup, `false` untuk normal.  
   **Contoh:**
   ```cpp
   display.dim(true); // Layar redup
   ```

6. **`setContrast(uint8_t contrast)`**  
   - Mengatur kecerahan layar dengan nilai 0-255.  
   - Nilai lebih rendah = lebih redup, nilai tinggi = lebih terang.  
   **Contoh:**
   ```cpp
   display.setContrast(128); // Mengatur kontras ke nilai sedang
   ```

---

#### **Kode Lengkap Kontrol Tampilan Dasar**
Berikut adalah contoh implementasi kontrol tampilan dasar:

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
  // 1. Mematikan layar selama 2 detik
  display.turnOff();
  Serial.println("Layar mati");
  delay(2000);

  // 2. Menghidupkan layar kembali
  display.turnOn();
  Serial.println("Layar hidup");
  delay(2000);

  // 3. Meredupkan layar
  display.dim(true);
  Serial.println("Layar redup");
  delay(2000);

  // 4. Mengembalikan kecerahan normal
  display.dim(false);
  Serial.println("Kecerahan normal");
  delay(2000);

  // 5. Mengubah kontras ke rendah
  display.setContrast(50);
  Serial.println("Kontras rendah");
  delay(2000);

  // 6. Mengubah kontras ke tinggi
  display.setContrast(200);
  Serial.println("Kontras tinggi");
  delay(2000);

  // 7. Membersihkan layar dan menampilkan teks baru
  display.clear();
  display.drawString(0, 0, "Demo Selesai!");
  display.display();
  delay(2000);
}
```

---

#### **Penjelasan Fungsi dan Perbandingan**

1. **Tanpa `turnOff()` / `turnOn()`**  
   Jika tidak menggunakan fungsi ini, layar akan tetap menyala sepanjang waktu, meskipun mungkin ingin dihemat daya.

2. **Tanpa `dim()`**  
   Fungsi ini opsional, tetapi sangat berguna untuk mode hemat daya atau ketika layar tidak perlu sepenuhnya terang.

3. **Tanpa `clear()`**  
   Layar akan tetap menampilkan data lama, dan data baru hanya akan ditambahkan di atasnya.

4. **Tanpa `setContrast()`**  
   OLED akan menggunakan tingkat kontras default, yang mungkin tidak sesuai untuk kondisi pencahayaan tertentu.

---