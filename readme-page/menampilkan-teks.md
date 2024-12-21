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
     display.drawString(64, 0, "Centered Text"); // Teks rata tengah
     ```
   - **Contoh rata kanan**:  
     ```cpp     
     display.setTextAlignment(TEXT_ALIGN_RIGHT); // Teks rata kanan
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