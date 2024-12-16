// Program Manajemen Minimarket
// Program ini dirancang untuk membantu manajemen data barang pada sebuah minimarket.
// Dalam model bisnis perdagangan, program ini mendukung pengelolaan stok barang, pencarian data, dan pengurutan harga barang.
// Program ini cocok untuk bisnis skala kecil hingga menengah yang membutuhkan sistem sederhana untuk manajemen inventaris.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_BARANG 100

// Struktur Barang
struct Barang {
    char nama[30];
    int stok;
    float harga;
};

struct Barang barang[MAX_BARANG];
int jumlahBarang = 0;


bool validasiStok(int stok) {
    return stok >= 0; // Stok tidak boleh negatif
}

bool validasiHarga(float harga) {
    return harga >= 0; // Harga tidak boleh negatif
}

// Prototipe fungsi
void menuUtama();
void login();
void inputBarang();
void tampilkanBarang();
void urutkanBarangBerdasarkanHarga();
void urutkanBarangBerdasarkanNama();
void cariBarangBerdasarkanHarga(float harga);
void cariBarangBerdasarkanNama(char* nama);
void updateBarang();
void hapusBarang();
void transaksiPembelian();
void laporanPenjualan();
void simpanData();
void muatData();


// Fungsi Otentikasi dengan 3 kali percobaan
// Fungsi Otentikasi
void login() {
    char username[30], password[30];
    int attempt = 0; // Menghitung jumlah percobaan login

    printf("Selamat datang di Aplikasi Inventaris Cihuy\n");

    while (attempt < 3) { // Maksimal 3 percobaan login
        printf("Masukkan Username: ");
        scanf("%s", username);

        printf("Masukkan Password: ");
        scanf("%s", password);

        // Cek username dan password
        if (strcmp(username, "admin") == 0 && strcmp(password, "admin123") == 0) {
            printf("Login berhasil!\n");
            return; // Keluar dari fungsi jika login berhasil
        } else {
            printf("Username atau Password salah. Coba lagi.\n");
            attempt++;
        }
    }

    printf("Terlalu banyak percobaan gagal. Program akan keluar.\n");
    exit(0); // Keluar jika gagal login lebih dari 3 kali
}

// Fungsi Input Data Barang - memasukkan data
void inputBarang() {
    int n;
    do {
        printf("Masukkan jumlah barang baru (tidak boleh negatif): ");
        scanf("%d", &n);
        if (n < 0) {
            printf("Jumlah barang tidak boleh negatif. Silakan coba lagi.\n");
        }
    } while (n < 0);

    if (jumlahBarang + n > MAX_BARANG) {
        printf("Tidak dapat menambahkan barang. Kapasitas maksimum tercapai.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("\nBarang ke-%d:\n", i + 1);
        printf("Nama Barang: ");
        getchar(); // Menghapus newline
        fgets(barang[jumlahBarang].nama, sizeof(barang[jumlahBarang].nama), stdin);
        barang[jumlahBarang].nama[strcspn(barang[jumlahBarang].nama, "\n")] = 0; // Hilangkan newline
        printf("Stok Barang: ");
        scanf("%d", &barang[jumlahBarang].stok);
        printf("Harga Barang: ");
        scanf("%f", &barang[jumlahBarang].harga);
        jumlahBarang++;
    }
    printf("\nData barang berhasil ditambahkan.\n");
}

// Fungsi Tampilkan Data Barang - displaying data
void tampilkanBarang() {
    if (jumlahBarang == 0) {
        printf("\nTidak ada data barang.\n");
        return;
    }

    printf("\nData Barang:\n");
    for (int i = 0; i < jumlahBarang; i++) {
        printf("%d. Nama: %s | Stok: %d | Harga: %.2f\n", i + 1, barang[i].nama, barang[i].stok, barang[i].harga);
    }
}

// Fungsi Update Data Barang
void updateBarang() {
    char namaBarang[30];
    printf("\nMasukkan nama barang yang ingin diupdate: ");
    getchar(); // Menghapus newline
    fgets(namaBarang, sizeof(namaBarang), stdin);
    namaBarang[strcspn(namaBarang, "\n")] = 0; // Hilangkan newline

    for (int i = 0; i < jumlahBarang; i++) {
        if (strcmp(barang[i].nama, namaBarang) == 0) {
            printf("\nBarang ditemukan:\n");
            printf("Nama: %s | Stok: %d | Harga: %.2f\n", barang[i].nama, barang[i].stok, barang[i].harga);
            printf("\nMasukkan data baru:\n");
            printf("Stok Barang: ");
            scanf("%d", &barang[i].stok);
            printf("Harga Barang: ");
            scanf("%f", &barang[i].harga);
            printf("\nData barang berhasil diperbarui.\n");
            return;
        }
    }

    printf("\nBarang tidak ditemukan.\n");
}

// Fungsi Hapus Data Barang
void hapusBarang() {
    char namaBarang[30];
    printf("\nMasukkan nama barang yang ingin dihapus: ");
    getchar(); // Menghapus newline
    fgets(namaBarang, sizeof(namaBarang), stdin);
    namaBarang[strcspn(namaBarang, "\n")] = 0; // Hilangkan newline

    for (int i = 0; i < jumlahBarang; i++) {
        if (strcmp(barang[i].nama, namaBarang) == 0) {
            for (int j = i; j < jumlahBarang - 1; j++) {
                barang[j] = barang[j + 1];
            }
            jumlahBarang--;
            printf("\nBarang berhasil dihapus.\n");
            return;
        }
    }

    printf("\nBarang tidak ditemukan.\n");
}

// Fungsi Transaksi Pembelian
void transaksiPembelian() {
    char namaBarang[30];
    int jumlahBeli;

    printf("Masukkan nama barang yang ingin dibeli: ");
    getchar(); // Menghapus newline
    fgets(namaBarang, sizeof(namaBarang), stdin);
    namaBarang[strcspn(namaBarang, "\n")] = 0; // Hilangkan newline

    for (int i = 0; i < jumlahBarang; i++) {
        if (strcmp(barang[i].nama, namaBarang) == 0) {
            printf("Harga Barang: %.2f | Stok Tersedia: %d\n", barang[i].harga, barang[i].stok);
            printf("Masukkan jumlah beli: ");
            scanf("%d", &jumlahBeli);

            if (barang[i].stok >= jumlahBeli) {
                barang[i].stok -= jumlahBeli;
                printf("Pembelian berhasil. Total: %.2f\n", barang[i].harga * jumlahBeli);
            } else {
                printf("Stok tidak cukup.\n");
            }
            return;
        }
    }

    printf("Barang tidak ditemukan.\n");
}

// Fungsi Laporan Penjualan
void laporanPenjualan() {
   // Implementasi laporan penjualan bisa ditambahkan di sini.
   printf("\nLaporan Penjualan Bulanan:\n");
}

// Fungsi Simpan Data - untuk menyimpann data yang sudah dimasukkan
void simpanData() {
   FILE *file = fopen("data_barang.txt", "w");
   if (file == NULL) {
       printf("Gagal membuka file!\n");
       return;
   }

   for (int i = 0; i < jumlahBarang; i++) {
       fprintf(file, "%s\n%d\n%.2f\n", barang[i].nama, barang[i].stok, barang[i].harga);
   }

   fclose(file);
   printf("Data berhasil disimpan.\n");
}

// Fungsi Muat Data untuk mengambil data dari penyimpanan program
void muatData() {
    FILE *file = fopen("data_barang.txt", "r");
    if (file == NULL) {
        printf("Gagal membuka file!\n");
        return;
    }

    // Reset jumlahBarang sebelum memuat data
    jumlahBarang = 0;

    // Read each item until EOF
    while (fscanf(file, "%29[^\n]\n%d\n%f\n",
                  barang[jumlahBarang].nama,
                  &barang[jumlahBarang].stok,
                  &barang[jumlahBarang].harga) == 3) {
        jumlahBarang++;
        if (jumlahBarang >= MAX_BARANG) {
            printf("Maksimum jumlah barang telah tercapai.\n");
            break;
        }
    }

    fclose(file);
    printf("Data berhasil dimuat.\n");
}

// Fungsi Urutkan Berdasarkan Harga dengan Insertion Sorting
void urutkanBarangBerdasarkanHarga() {
    for (int i = 0; i < jumlahBarang - 1; i++) {
        for (int j = i + 1; j < jumlahBarang; j++) {
            if (barang[i].harga > barang[j].harga) {
                // Tukar barang[i] dan barang[j]
                struct Barang temp = barang[i];
                barang[i] = barang[j];
                barang[j] = temp;
            }
        }
    }
    printf("Data barang sudah diurutkan berdasarkan harga.\n");
}

// Fungsi Urutkan Berdasarkan Nama dengan Insertion sorting
void urutkanBarangBerdasarkanNama() {
    for (int i = 0; i < jumlahBarang - 1; i++) {
        for (int j = i + 1; j < jumlahBarang; j++) {
            if (strcmp(barang[i].nama, barang[j].nama) > 0) {
                // Tukar barang[i] dan barang[j]
                struct Barang temp = barang[i];
                barang[i] = barang[j];
                barang[j] = temp;
            }
        }
    }
    printf("Data barang sudah diurutkan berdasarkan nama.\n");
}

// Fungsi Cari Barang Berdasarkan Harga dengan metode Binary Search
void cariBarangBerdasarkanHarga(float harga) {
    printf("\nBarang yang sesuai dengan harga %.2f:\n", harga);
    for (int i = 0; i < jumlahBarang; i++) {
        if (barang[i].harga == harga) {
            printf("Nama: %s | Stok: %d | Harga: %.2f\n", barang[i].nama, barang[i].stok, barang[i].harga);
        }
    }
}

// Fungsi Cari Barang Berdasarkan Nama dengan metode Binary Search
void cariBarangBerdasarkanNama(char* nama) {
    printf("\nBarang yang sesuai dengan nama %s:\n", nama);
    for (int i = 0; i < jumlahBarang; i++) {
        if (strcmp(barang[i].nama, nama) == 0) {
            printf("Nama: %s | Stok: %d | Harga: %.2f\n", barang[i].nama, barang[i].stok, barang[i].harga);
        }
    }
}

// Fungsi Menu Utama program Operasional Minimarket
void menuUtama() {
    int pilihan;
    do {
        printf("\n=== Menu Utama ===\n");
        printf("1. Input Barang\n");
        printf("2. Tampilkan Barang\n");
        printf("3. Update Barang\n");
        printf("4. Hapus Barang\n");
        printf("5. Transaksi Pembelian\n");
        printf("6. Laporan Penjualan\n");
        printf("7. Urutkan Barang Berdasarkan Harga\n");
        printf("8. Urutkan Barang Berdasarkan Nama\n");
        printf("9. Cari Barang Berdasarkan Harga\n");
        printf("10. Cari Barang Berdasarkan Nama\n");
        printf("11. Simpan Data\n");
        printf("12. Muat Data\n");
        printf("13. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                inputBarang();
                break;
            case 2:
                tampilkanBarang();
                break;
            case 3:
                updateBarang();
                break;
            case 4:
                hapusBarang();
                break;
            case 5:
                transaksiPembelian();
                break;
            case 6:
                laporanPenjualan();
                break;
            case 7:
                urutkanBarangBerdasarkanHarga();
                break;
            case 8:
                urutkanBarangBerdasarkanNama();
                break;
            case 9:
                {
                    float harga;
                    printf("Masukkan harga barang: ");
                    scanf("%f", &harga);
                    cariBarangBerdasarkanHarga(harga);
                }
                break;
            case 10:
                {
                    char nama[30];
                    printf("Masukkan nama barang: ");
                    getchar(); // Menghapus newline
                    fgets(nama, sizeof(nama), stdin);
                    nama[strcspn(nama, "\n")] = 0; // Hilangkan newline
                    cariBarangBerdasarkanNama(nama);
                }
                break;
            case 11:
                simpanData();
                break;
            case 12:
                muatData();
                break;
            case 13:
                printf("Terima kasih! Program selesai.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 13);
}

int main() {
    login();
    menuUtama();
    return 0;
}
