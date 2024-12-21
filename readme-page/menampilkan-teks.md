# **4. Mengatur Teks pada Layar**

Fitur ini mencakup kemampuan untuk menampilkan teks pada OLED, termasuk mengatur posisi, ukuran font, perataan, dan gaya teks. Library **SSD1306Wire** menyediakan fungsi untuk menangani berbagai aspek tampilan teks.

---

#### **Fungsi Utama untuk Menampilkan Teks**
Berikut adalah fungsi utama untuk menampilkan teks menggunakan **SSD1306Wire**:

1. **`setFont(const uint8_t* font)`**  
   Mengatur ukuran font yang akan digunakan.  
   - **Parameter**:  
     `font` adalah pointer ke font yang digunakan. Font default biasanya cukup untuk kebutuhan dasar.  
   - **Contoh**:  
     ```cpp
     display.setFont(ArialMT_Plain_10); // Menggunakan font Arial ukuran 10
     ```
     ```cpp
     display.setFont(ArialMT_Plain_16); // Menggunakan font Arial ukuran 10
     ```
     ```cpp
     display.setFont(ArialMT_Plain_24); // Menggunakan font Arial ukuran 10
     ```
     ```cpp
     display.setFont(ArialMT_Plain_32); // Menggunakan font Arial ukuran 10
     ```

2. **`setTextAlignment(TextAlignment alignment)`**  
   Mengatur perataan teks (kiri, kanan, tengah).  
   - **Parameter**:  
     - `TEXT_ALIGN_LEFT` (default): rata kiri.  
     - `TEXT_ALIGN_CENTER`: rata tengah.  
     - `TEXT_ALIGN_RIGHT`: rata kanan.  

   - **Contoh rata kiri**:  
     ```cpp     
     display.setTextAlignment(TEXT_ALIGN_LEFT); // Teks rata kiri
     display.drawString(0, 0, "Hello, OLED!");
     ```

   - **Contoh rata tengah**:  
     ```cpp     
     display.setTextAlignment(TEXT_ALIGN_CENTER);
     display.drawString(64, 0, "Centered Text");
     ```
   - **Contoh rata kanan**:  
     ```cpp     
     display.setTextAlignment(TEXT_ALIGN_RIGHT);
     display.drawString(128, 0, "Right Align");
     ```

3. **`drawString(int16_t x, int16_t y, const String& text)`**  
   Menampilkan teks di posisi `(x, y)` tertentu.  
   - **Parameter**:  
     - `x`, `y`: koordinat awal teks.  
     - `text`: teks yang akan ditampilkan.  
   - **Contoh**:  
     ```cpp
     display.drawString(0, 0, "Hello, OLED!");
     ```

4. **`drawStringMaxWidth(int16_t x, int16_t y, int16_t maxWidth, const String& text)`**  
   Menampilkan teks dengan lebar maksimum tertentu, memotong teks jika melebihi batas.  
   - **Parameter**:  
     - `maxWidth`: lebar maksimum area teks.  
   - **Contoh**:  
     ```cpp
     display.drawStringMaxWidth(0, 0, 50, "Text yang panjang!");
     ```
---

### **Kode Contoh: Menampilkan Teks**

```cpp
#include <Wire.h>
#include <SSD1306Wire.h>

// Inisialisasi OLED
SSD1306Wire display(0x3C, D2, D1); // Alamat I2C: 0x3C, SDA: D2, SCL: D1

void setup() {
  display.init();
  display.clear(); // Bersihkan layar

  // 1. Menampilkan teks dasar
  display.setFont(ArialMT_Plain_10);        // Mengatur font
  display.setTextAlignment(TEXT_ALIGN_LEFT); // Teks rata kiri
  display.drawString(0, 0, "Hello, OLED!");

  // 2. Menampilkan teks rata tengah
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.drawString(64, 10, "Centered Text");

  // 3. Menampilkan teks rata kanan
  display.setTextAlignment(TEXT_ALIGN_RIGHT);
  display.drawString(128, 20, "Right Align");

  // 4. Menampilkan teks dengan lebar maksimum
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.drawStringMaxWidth(0, 30, 128, "Teks dengan batas lebar 128 piksel!");

  // Tampilkan semua teks
  display.display();
}

void loop() {
  // Tidak ada aksi di loop
}
```

---

### **Penjelasan Kode**
1. **Mengatur Font**  
   - Gunakan **`setFont()`** untuk memilih jenis dan ukuran font.
   - Font default adalah Arial ukuran 10.

2. **Mengatur Perataan Teks**  
   - **`setTextAlignment()`** menentukan posisi teks (kiri, tengah, atau kanan).  

3. **Menampilkan Teks**  
   - **`drawString()`** menampilkan teks pada koordinat tertentu.  
   - **`drawStringMaxWidth()`** membatasi panjang teks sehingga tidak melebihi area layar.

4. **Menampilkan Teks dengan Layout yang Berbeda**  
   - Kombinasi font, perataan, dan koordinat dapat menghasilkan berbagai desain teks.

---

### **Hasil Output**
Setelah kode ini diunggah:
- Teks "Hello, OLED!" akan muncul di sudut kiri atas.
- Teks "Centered Text" akan berada di tengah layar (secara horizontal).
- Teks "Right Align" akan muncul di sisi kanan layar.
- Teks panjang "Teks dengan batas lebar 128 piksel!" akan dibatasi lebarnya hingga 128 piksel.
