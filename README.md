# Library SSD1306Wire

Library SSD1306Wire adalah library yang ringan dan mudah digunakan untuk mengontrol OLED berbasis SSD1306 menggunakan protokol I2C. Library ini dirancang untuk penggunaan memori rendah, sehingga cocok untuk perangkat dengan RAM terbatas seperti ESP8266. Mendukung berbagai platform, termasuk ESP8266, ESP32, dan platform lain dengan driver SSD1306.

## Fitur Utama

Berikut adalah fitur utama yang disediakan oleh modul SSD1306Wire untuk OLED:

*   **Pengaturan Dasar Display:**
    *   **Inisialisasi Display:** Memudahkan pengaturan koneksi I2C (alamat I2C, SDA, dan SCL).
    *   **Rotasi Display:** Mendukung rotasi tampilan (normal atau terbalik).
    *   **Kecerahan (Contrast):** Dapat mengatur tingkat kecerahan layar.
*   **Rendering Teks:**
    *   Menampilkan teks dengan berbagai ukuran font.
    *   Mendukung perataan teks: kiri, tengah, atau kanan.
    *   Menambahkan font kustom menggunakan file eksternal.
*   **Gambar (Images):**
    *   Menampilkan gambar bitmap (monokrom).
    *   Mendukung format gambar 1-bit (contoh: array byte dari file .bmp).
*   **Menggambar Bentuk Geometris:**
    *   **Garis:** Menggambar garis horizontal, vertikal, atau miring.
    *   **Kotak dan Persegi Panjang:** Dengan atau tanpa isi (hollow atau filled).
    *   **Lingkaran dan Elips:** Dengan opsi untuk membuat isi penuh.
*   **Manajemen Layar:**
    *   **Clear Screen:** Membersihkan layar untuk memulai dari awal.
    *   **Flip Screen:** Membalik tampilan layar secara vertikal.
    *   **Sleep Mode:** Mematikan layar sementara untuk menghemat daya.
*   **Fitur Tambahan:**
    *   **Scrolling:** Mendukung efek scrolling (horizontal, vertikal, atau diagonal).
    *   **Buffering:** Semua perubahan dilakukan pada buffer terlebih dahulu, lalu diperbarui ke layar menggunakan metode `.display()` untuk efisiensi.
    *   **Support Multiplatform:** Mendukung ESP8266, ESP32, dan platform lain dengan driver SSD1306.
*   **Efisiensi Resource:** Library ini dirancang untuk penggunaan memori rendah.

## Dokumentasi API Utama

Berikut beberapa contoh penggunaan API utama:

*   `SSD1306Wire display(0x3C, SDA, SCL);`: Inisialisasi OLED dengan alamat I2C `0x3C`, pin `SDA`, dan pin `SCL`.
*   `display.init();`: Menginisialisasi modul OLED.
*   `display.setFont(ArialMT_Plain_10);`: Mengatur font untuk teks.
*   `display.drawString(x, y, "Hello!");`: Menampilkan teks di koordinat `(x, y)`.
*   `display.drawXbm(x, y, width, height, bitmap);`: Menampilkan gambar bitmap pada koordinat `(x, y)`.
*   `display.display();`: Memperbarui tampilan layar dengan data di buffer.

## Instalasi

(Bagian ini perlu ditambahkan informasi cara instalasi library, misalnya melalui Arduino Library Manager atau manual)

## Contoh Penggunaan

(Bagian ini idealnya berisi cuplikan kode yang menunjukkan penggunaan library dalam konteks yang lebih lengkap)

## Kontribusi

(Bagian ini opsional, tetapi disarankan untuk proyek open source. Jelaskan bagaimana orang lain dapat berkontribusi pada proyek Anda.)

## Lisensi

(Tambahkan informasi lisensi, misalnya MIT License)