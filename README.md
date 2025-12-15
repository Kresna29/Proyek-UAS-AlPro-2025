# POKEDEX CLI

## Deskripsi Program

Program **Pokedex CLI** adalah aplikasi berbasis *Command Line Interface* (CLI) yang dibuat menggunakan bahasa **C++**. Program ini bertujuan untuk mengelola data Pokémon seperti pada konsep **Pokémon GO**, di mana pengguna dapat memiliki beberapa Pokémon dengan nama yang sama tetapi atribut yang berbeda (power, shiny, dan tipe).

---

## Fitur Program

1. **Tambah Pokémon**

   * ID Pokémon (4 digit, sesuai Pokédex)
   * Nama Pokémon
   * Tipe tunggal atau dual type
   * Status shiny / normal
   * Power Pokémon

2. **Tampilkan Semua Pokémon**

   * Menampilkan seluruh data Pokémon yang tersimpan

3. **Urutkan Berdasarkan Power**

   * Mengurutkan Pokémon dari power terkecil ke terbesar
   * Menampilkan pesan jika data belum ada

4. **Cari Pokémon (Case-Insensitive)**

   * Pencarian nama Pokémon tidak sensitif huruf besar/kecil
   * Menampilkan **semua Pokémon dengan nama yang sama**

5. **Filter Berdasarkan Tipe**

   * Single type (contoh: `Fire`)
   * Dual type menggunakan koma (contoh: `Grass,Poison`)

6. **Simpan & Load File**

   * Data disimpan ke file `pokemon.txt`
   * Data dapat dimuat kembali saat program dijalankan

---

## Konsep Algoritma yang Digunakan

* **Array of Struct** untuk menyimpan data Pokémon
* **Linear Search** untuk pencarian Pokémon
* **Selection Sort** untuk pengurutan berdasarkan power
* **Validasi input** untuk tipe Pokémon
* **File I/O** menggunakan `fstream`

---

## Cara Menjalankan Program

1. Compile program:

   ```bash
   g++ Pokedex.cpp -o Pokedex
   ```
2. Jalankan program:

   ```bash
   ./Pokedex
   ```

---

## Catatan

* Program bersifat CLI dan tidak menggunakan library tambahan di luar standar C++
* Program mendukung banyak Pokémon dengan nama yang sama (sesuai konsep Pokémon GO)

---

## Penutup

Program ini dibuat sebagai bentuk penerapan konsep dasar Algoritma dan Pemrograman menggunakan bahasa C++ dengan struktur yang rapi, logika jelas, dan mudah dipahami.

**Nama:** Kresna Bayu W.

**NPM:** 140810230025

**Kelas:** B

**Mata Kuliah:** Algoritma dan Pemrograman
