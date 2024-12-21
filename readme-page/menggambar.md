# **3. Menggambar di Layar (Drawing Functions)**

Fitur menggambar di layar memungkinkan kita membuat grafik sederhana seperti garis, lingkaran, persegi panjang, dan elemen visual lainnya pada OLED. Library **SSD1306Wire** menyediakan berbagai fungsi untuk menggambar objek di layar, yang sangat berguna untuk membuat tampilan interaktif atau visualisasi data.

---

#### **Fungsi-Fungsi Menggambar**
Berikut adalah fungsi-fungsi menggambar dasar yang disediakan oleh **SSD1306Wire**:

1. **`drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1)`**  
   Menggambar garis dari titik `(x0, y0)` ke `(x1, y1)`.  
   - **Parameter**:  
     `x0`, `y0` adalah titik awal; `x1`, `y1` adalah titik akhir.  
   - **Contoh**:  
     ```cpp
     display.drawLine(0, 0, 50, 50); // Garis diagonal dari (0, 0) ke (50, 50)
     ```

2. **`drawRect(int16_t x, int16_t y, int16_t width, int16_t height)`**  
   Menggambar persegi panjang dengan posisi `(x, y)` sebagai titik kiri atas.  
   - **Parameter**:  
     `x`, `y` adalah koordinat kiri atas; `width` dan `height` adalah lebar dan tinggi.  
   - **Contoh**:  
     ```cpp
     display.drawRect(10, 10, 40, 20); // Persegi panjang 40x20 mulai dari (10, 10)
     ```

3. **`fillRect(int16_t x, int16_t y, int16_t width, int16_t height)`**  
   Menggambar persegi panjang berisi (diisi penuh).  
   - **Parameter**:  
     Sama seperti `drawRect`.  
   - **Contoh**:  
     ```cpp
     display.fillRect(10, 10, 40, 20); // Persegi panjang penuh 40x20 mulai dari (10, 10)
     ```

4. **`drawCircle(int16_t x, int16_t y, int16_t radius)`**  
   Menggambar lingkaran dengan pusat `(x, y)` dan jari-jari `radius`.  
   - **Parameter**:  
     `x`, `y` adalah koordinat pusat; `radius` adalah jari-jari lingkaran.  
   - **Contoh**:  
     ```cpp
     display.drawCircle(30, 30, 20); // Lingkaran di pusat (30, 30) dengan radius 20
     ```

5. **`fillCircle(int16_t x, int16_t y, int16_t radius)`**  
   Menggambar lingkaran berisi (diisi penuh).  
   - **Parameter**:  
     Sama seperti `drawCircle`.  
   - **Contoh**:  
     ```cpp
     display.fillCircle(30, 30, 20); // Lingkaran penuh di pusat (30, 30) dengan radius 20
     ```
