// Program Manajemen Minimarket
// Program ini dirancang untuk membantu manajemen data barang pada sebuah minimarket.
// Dalam model bisnis perdagangan, program ini mendukung pengelolaan stok barang, pencarian data, dan pengurutan harga barang.
// Program ini cocok untuk bisnis skala kecil hingga menengah yang membutuhkan sistem sederhana untuk manajemen inventaris.

#include <stdio.h>
#include <string.h>

#define MAX_BARANG 100 // Membuat program dengan kapasitas varian barang mencapai 100 barang

// Struktur Barang
struct Barang {
    char nama[30];
    int stok;
    float harga;
};

struct Barang barang[MAX_BARANG]; 
int jumlahBarang = 0;

// Prototipe fungsi
void menuUtama();
void inputBarang();
void tampilkanBarang();
void urutkanBarang();
void cariBarang();
void updateBarang();
void hapusBarang();

// Fungsi Input Data Barang
void inputBarang() {
    int n;
    printf("Masukkan jumlah barang baru: ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        printf("\nBarang ke-%d:\n", i + 1);
        printf("Nama Barang: ");
        fgets(barang[jumlahBarang].nama, 30, stdin);
        barang[jumlahBarang].nama[strcspn(barang[jumlahBarang].nama, "\n")] = 0; // Hilangkan newline
        printf("Stok Barang: ");
        scanf("%d", &barang[jumlahBarang].stok);
        printf("Harga Barang: ");
        scanf("%f", &barang[jumlahBarang].harga);
        getchar();

        jumlahBarang++;
    }
    printf("\nData barang berhasil ditambahkan.\n");
}

// Fungsi Tampilkan Data Barang
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
    getchar();
    fgets(namaBarang, 30, stdin);
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
            printf("\nData barang berhasil diupdate.\n");
            return;
        }
    }
    printf("\nBarang tidak ditemukan.\n");
}

// Fungsi Hapus Data Barang atau delesi-nya
void hapusBarang() {
    char namaBarang[30];
    printf("\nMasukkan nama barang yang ingin dihapus: ");
    getchar();
    fgets(namaBarang, 30, stdin);
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

// Fungsi Sorting (Bubble Sort)
void urutkanBarang() {
    struct Barang temp;
    for (int i = 0; i < jumlahBarang - 1; i++) {
        for (int j = 0; j < jumlahBarang - i - 1; j++) {
            if (barang[j].harga > barang[j + 1].harga) {
                temp = barang[j];
                barang[j] = barang[j + 1];
                barang[j + 1] = temp;
            }
        }
    }
    printf("\nData barang berhasil diurutkan berdasarkan harga.\n");
}

// Fungsi Searching (Sequential Search)
void cariBarang() {
    char namaBarang[30];
    printf("\nMasukkan nama barang yang dicari: ");
    getchar();
    fgets(namaBarang, 30, stdin);
    namaBarang[strcspn(namaBarang, "\n")] = 0; // Hilangkan newline

    for (int i = 0; i < jumlahBarang; i++) {
        if (strcmp(barang[i].nama, namaBarang) == 0) {
            printf("\nBarang ditemukan:\n");
            printf("Nama: %s | Stok: %d | Harga: %.2f\n", barang[i].nama, barang[i].stok, barang[i].harga);
            return;
        }
    }
    printf("\nBarang tidak ditemukan.\n");
}

// Fungsi Menu Utamanya
void menuUtama() {
    int pilihan;

    do {
        printf("\nMenu Program Minimarket:\n");
        printf("1. Input Data Barang\n");
        printf("2. Tampilkan Data Barang\n");
        printf("3. Urutkan Barang Berdasarkan Harga\n");
        printf("4. Cari Barang Berdasarkan Nama\n");
        printf("5. Update Data Barang\n");
        printf("6. Hapus Data Barang\n");
        printf("7. Keluar\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                inputBarang();
                break;
            case 2:
                tampilkanBarang();
                break;
            case 3:
                urutkanBarang();
                break;
            case 4:
                cariBarang();
                break;
            case 5:
                updateBarang();
                break;
            case 6:
                hapusBarang();
                break;
            case 7:
                printf("\nKeluar dari program.\n");
                break;
            default:
                printf("\nPilihan tidak valid.\n");
        }
    } while (pilihan != 7);
}

// Fungsi Utama
int main() {
    menuUtama();
    return 0;
}