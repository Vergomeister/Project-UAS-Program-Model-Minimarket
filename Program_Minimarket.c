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

// Fungsi Input Data Barang atau untuk memasukkan data barang
void inputBarang() {
    int n;
    printf("Masukkan jumlah barang baru : ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        printf("\nBarang ke-%d:\n", i + 1);
        printf("Nama Barang : ");
        fgets(barang[jumlahBarang].nama, 30, stdin);
        barang[jumlahBarang].nama[strcspn(barang[jumlahBarang].nama, "\n")] = 0; // Hilangkan newline
        printf("Stok Barang : ");
        scanf("%d", &barang[jumlahBarang].stok);
        printf("Harga Barang : ");
        scanf("%f", &barang[jumlahBarang].harga);
        getchar();

        jumlahBarang++;
    }
    printf("\nData barang berhasil ditambahkan.\n");
}

// Fungsi Tampilkan Data Barang atau displaying data barang
void tampilkanBarang() {
    if (jumlahBarang == 0) {
        printf("\nTidak ada data barang.\n");
        return;
    }

    printf("\nData Barang :\n");
    for (int i = 0; i < jumlahBarang; i++) {
        printf("%d. Nama : %s | Stok: %d | Harga: %.2f\n", i + 1, barang[i].nama, barang[i].stok, barang[i].harga);
    }
}

// Fungsi Update Data Barang atau pembaruan data barang
void updateBarang() {
    char namaBarang[30];
    printf("\nMasukkan nama barang yang ingin diupdate : ");
    getchar();
    fgets(namaBarang, 30, stdin);
    namaBarang[strcspn(namaBarang, "\n")] = 0; // Hilangkan newline

    for (int i = 0; i < jumlahBarang; i++) {
        if (strcmp(barang[i].nama, namaBarang) == 0) {
            printf("\nBarang ditemukan :\n");
            printf("Nama: %s | Stok: %d | Harga: %.2f\n", barang[i].nama, barang[i].stok, barang[i].harga);
            printf("\nMasukkan data baru :\n");
            printf("Stok Barang : ");
            scanf("%d", &barang[i].stok);
            printf("Harga Barang : ");
            scanf("%f", &barang[i].harga);
            printf("\nData barang berhasil diperbarui.\n");
            return;
        }
    }
    printf("\nBarang tidak ditemukan.\n");
}

// Fungsi Hapus Data Barang atau delesi-nya
void hapusBarang() {
    char namaBarang[30];
    printf("\nMasukkan nama barang yang ingin dihapus : ");
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

// Fungsi Sorting (Insertion Sort) untuk kebutuhan pengurutan barang
void urutkanBarang() {
    struct Barang key;
    int i, j;
    for (i = 1; i < jumlahBarang; i++) {
        key = barang[i];  // Menyimpan elemen yang akan disisipkan
        j = i - 1;

        // Menggeser elemen yang lebih besar dari key ke posisi satu langkah lebih maju
        while (j >= 0 && barang[j].harga > key.harga) {
            barang[j + 1] = barang[j];  // Geser ke kanan
            j = j - 1;
        }
        barang[j + 1] = key;  // Sisipkan key ke posisi yang tepat
    }
    printf("\nData barang berhasil diurutkan berdasarkan harga.\n");
}


void cariBarang() {
    char namaBarang[30];
    printf("\nMasukkan nama barang yang dicari : ");
    getchar();
    fgets(namaBarang, 30, stdin);
    namaBarang[strcspn(namaBarang, "\n")] = 0; // Hilangkan newline

    // Pastikan barang sudah terurut berdasarkan nama sebelum pencarian
    urutkanBarang();

    int left = 0;
    int right = jumlahBarang - 1;
    int mid;

    while (left <= right) {
        mid = left + (right - left) / 2;

        int comparison = strcmp(barang[mid].nama, namaBarang);

        // Jika nama barang ditemukan
        if (comparison == 0) {
            printf("\nBarang ditemukan :\n");
            printf("Nama : %s | Stok : %d | Harga : %.2f\n", barang[mid].nama, barang[mid].stok, barang[mid].harga);
            return;
        }

        // Jika nama barang lebih kecil dari mid, cari di sebelah kiri
        if (comparison < 0) {
            right = mid - 1;
        }
        // Jika nama barang lebih besar dari mid, cari di sebelah kanan
        else {
            left = mid + 1;
        }
    }
    printf("\nBarang tidak ditemukan.\n");
}


void menuUtama() {
    int pilihan;
    char buffer[10]; // Buffer untuk membaca input sebagai string

    do {
        printf("\nMenu Program Minimarket Cihuy :\n");
        printf("1. Input Data Barang\n");
        printf("2. Tampilkan Data Barang\n");
        printf("3. Urutkan Barang Berdasarkan Harga\n");
        printf("4. Cari Barang Berdasarkan Nama\n");
        printf("5. Update Data Barang\n");
        printf("6. Hapus Data Barang\n");
        printf("7. Keluar\n");
        printf("Masukkan pilihan : ");

        // Membaca input sebagai string
        fgets(buffer, sizeof(buffer), stdin);

        // Validasi apakah input adalah angka
        if (sscanf(buffer, "%d", &pilihan) != 1) {
            printf("\nInput tidak valid. Masukkan angka dari 1 hingga 7 untuk memilih menu.\n");
            continue; // Kembali ke awal loop
        }

        // Switch case untuk memproses pilihan
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
                printf("\nInput tidak valid. Masukkan angka dari 1 hingga 7 untuk memilih menu.\n");
        }
    } while (pilihan != 7);
}

// Fungsi Utama dari program
int main() {
    menuUtama();
    return 0;
}
