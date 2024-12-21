### **6. Buffer Handling di OLED**

Buffer handling mengacu pada proses pengelolaan data yang akan ditampilkan di layar OLED. Dalam library **SSD1306Wire**, data tampilan disimpan dalam buffer di memori mikrokontroler sebelum dikirimkan ke OLED. Pendekatan ini memungkinkan Anda menggambar elemen secara terpisah tanpa langsung mengubah layar, sehingga mencegah efek flicker (kedipan).

---

#### **Prinsip Buffer Handling**
1. **Double Buffering**:  
   Semua elemen digambar di buffer memori terlebih dahulu. Hanya setelah selesai, buffer ditampilkan ke layar menggunakan **`display()`**.

2. **Buffer Size**:  
   Buffer memuat data piksel untuk seluruh layar OLED. Untuk layar **128x64**, buffer membutuhkan sekitar 1KB memori (128 * 64 / 8 = 1024 byte).

3. **Operasi pada Buffer**:  
   Anda dapat menambah, menghapus, atau memodifikasi elemen pada buffer tanpa langsung memengaruhi tampilan di layar.

---

### **Fungsi Buffer Handling Utama**
1. **`clear()`**  
   Menghapus semua elemen dalam buffer.  
   - **Contoh**:  
     ```cpp
     display.clear(); // Buffer kosong
     ```

2. **`display()`**  
   Menyalin isi buffer ke layar OLED.  
   - **Contoh**:  
     ```cpp
     display.display(); // Tampilkan buffer ke layar
     ```

3. **Menggunakan Buffer untuk Efisiensi**  
   Buffer memungkinkan Anda menggambar banyak elemen sekaligus sebelum menampilkan hasil akhir ke layar, mencegah layar terlihat kosong atau berkedip selama proses pembaruan.

---

### **Contoh Kode Buffer Handling**
Berikut adalah contoh sederhana penggunaan buffer untuk mencegah flicker saat menggambar animasi.

```cpp
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
```

---

### **Penjelasan Kode**
1. **`clear()` untuk Menghapus Buffer**:  
   Buffer dihapus sebelum menggambar elemen baru. Ini mencegah elemen lama tetap muncul di layar.

2. **Menggambar Elemen di Buffer**:  
   Semua elemen digambar di buffer sebelum ditampilkan, memastikan layar hanya diperbarui setelah semua elemen siap.

3. **Efisiensi Tampilan**:  
   Proses ini menghilangkan flicker karena layar hanya diperbarui setelah buffer selesai diproses.

4. **Animasi Tanpa Kedipan**:  
   Pergerakan lingkaran di layar tidak menyebabkan efek kedipan karena buffer digunakan dengan baik.

---

### **Penggunaan Lanjutan: Partial Updates**
Anda dapat menggunakan **partial updates** (pembaruan sebagian) untuk mengurangi beban buffer saat layar hanya memerlukan pembaruan kecil. Namun, library **SSD1306Wire** tidak mendukung partial updates secara langsung.

---

### **Hasil Output**
1. Teks "Buffer Handling Example" ditampilkan di bagian atas layar.
2. Sebuah lingkaran bergerak dari kiri ke kanan tanpa efek flicker.
