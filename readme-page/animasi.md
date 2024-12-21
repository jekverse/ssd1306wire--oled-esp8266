### **5. Membuat Animasi di OLED**

Animasi pada OLED mencakup kemampuan untuk memperbarui layar secara dinamis dalam interval waktu tertentu, memberikan kesan gerakan. Dengan **SSD1306Wire**, Anda dapat membuat animasi sederhana seperti teks bergerak, objek berpindah posisi, atau transisi layar.

---

#### **Konsep Animasi dengan SSD1306Wire**
Animasi bekerja dengan mengatur ulang konten layar secara berkala:
1. **Looping**: Menggunakan fungsi `loop()` untuk terus memperbarui tampilan.
2. **Pembersihan**: Membersihkan layar sebelum menggambar ulang frame baru.
3. **Interval Waktu**: Menambahkan jeda waktu dengan fungsi `delay()` atau menggunakan logika berbasis waktu (`millis()`).
4. **Perubahan Parameter**: Mengubah posisi, ukuran, atau properti elemen pada setiap iterasi.

---

#### **Fungsi Utama untuk Animasi**
Fungsi berikut mendukung pembuatan animasi:
1. **`clear()`**: Membersihkan layar sebelum menggambar ulang.
2. **`display()`**: Menampilkan elemen yang telah digambar.
3. **Fungsi menggambar**: Gunakan fungsi seperti `drawString()`, `drawRect()`, atau `drawCircle()` untuk membuat elemen visual yang dapat dianimasikan.

---

### **Kode Contoh: Animasi Teks Bergerak**

```cpp
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
```

---

### **Penjelasan Kode**
1. **Variabel Posisi dan Arah**  
   - `textX` menyimpan posisi horizontal teks.
   - `textDirection` mengontrol arah gerakan (ke kanan atau ke kiri).

2. **Logika Gerakan**  
   - Pada setiap iterasi, `textX` diperbarui dengan nilai `textDirection`.
   - Jika teks mencapai batas layar (0 atau 128 piksel), arah gerakan dibalik.

3. **Pembersihan dan Pembaruan Layar**  
   - **`clear()`** membersihkan layar sebelum menggambar frame baru.
   - **`display()`** memastikan perubahan diterapkan ke layar OLED.

4. **Jeda Antar Frame**  
   - **`delay(30)`** menentukan kecepatan animasi (30ms per frame).

---

### **Kode Contoh: Animasi Bola Bergerak**

```cpp
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
```

---

### **Penjelasan Kode**
1. **Variabel Posisi dan Arah Bola**  
   - `ballX` dan `ballY` menyimpan posisi horizontal dan vertikal bola.
   - `ballDirectionX` dan `ballDirectionY` menentukan arah gerakan bola.

2. **Logika Gerakan dan Pantulan**  
   - Bola bergerak dengan menambahkan nilai arah ke posisinya.
   - Jika bola mencapai tepi layar, arah gerakan dibalik.

3. **Animasi Halus**  
   - **`fillCircle()`** menggambar bola pada setiap frame.
   - Jeda 20ms antar frame memberikan animasi yang halus.

---

### **Hasil Output**
1. **Animasi Teks Bergerak**:  
   Teks "Hello, Animasi!" bergerak bolak-balik secara horizontal di layar OLED.

2. **Animasi Bola Bergerak**:  
   Sebuah bola kecil akan bergerak dan memantul di dalam batas layar OLED.

---

Jika ada jenis animasi tertentu yang ingin Anda eksplorasi lebih lanjut, beri tahu saya! 😊