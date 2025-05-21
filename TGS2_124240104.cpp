#include <iostream>
#include <string>
using namespace std;

struct Pesanan {
    string namacust;
    string jenisRoti;
    int totalhrg;
    Pesanan* next;
};

Pesanan* awalqueue = NULL;
Pesanan* akhirqueue = NULL;
Pesanan* topRiwayat = NULL;

void ambilAntrean() {
    Pesanan* newNode = new Pesanan;
    cout << "\nNama       : ";
    getline(cin >> ws, newNode->namacust);
    cout << "Jenis roti : ";
    getline(cin, newNode->jenisRoti);
    cout << "Total harga: Rp";
    cin >> newNode->totalhrg;
    newNode->next = NULL;

    if (awalqueue == NULL) {
        awalqueue = akhirqueue = newNode;
    } else {
        akhirqueue->next = newNode;
        akhirqueue = newNode;
    }

    cout << "Pesanan ditambahkan ke antrean.\n";
}

void layaniPembeli() {
    if (awalqueue == NULL) {
        cout << "Tidak ada antrean.\n";
        return;
    }

    Pesanan* dilayani = awalqueue;
    awalqueue = awalqueue->next;
    if (awalqueue == NULL) akhirqueue = NULL;

    dilayani->next = topRiwayat;
    topRiwayat = dilayani;

    cout << "\nMelayani pesanan:\n";
    cout << "Nama       : " << dilayani->namacust << "\n";
    cout << "Jenis Roti : " << dilayani->jenisRoti << "\n";
    cout << "Total Harga: Rp" << dilayani->totalhrg << "\n";
}

void tampilkanAntrean() {
    if (awalqueue == NULL) {
        cout << "Antrean kosong.\n";
        return;
    }

    cout << "\nDaftar Pesanan dalam Antrean:\n";
    Pesanan* terbaru = awalqueue;
    int no = 1;
    while (terbaru != NULL) {
        cout << no++ << ". " << terbaru->namacust << " - " << terbaru->jenisRoti << " - Rp" << terbaru->totalhrg << "\n";
        terbaru = terbaru->next;
    }
}

void batalkanPesanan() {
    if (awalqueue == NULL) {
        cout << "Tidak ada pesanan untuk dibatalkan.\n";
        return;
    }

    if (awalqueue == akhirqueue) {
        delete awalqueue;
        awalqueue = akhirqueue = NULL;
    } else {
        Pesanan* terbaru = awalqueue;
        while (terbaru->next != akhirqueue) {
            terbaru = terbaru->next;
        }
        delete akhirqueue;
        akhirqueue = terbaru;
        akhirqueue->next = NULL;
    }

    cout << "Pesanan terakhir di antrean berhasil dibatalkan.\n";
}

void tampilkanHistory() {
    if (topRiwayat == NULL) {
        cout << "Belum ada pesanan yang dilayani.\n";
        return;
    }

    cout << "\nRiwayat Pesanan yang Dilayani:\n";
    Pesanan* terbaru = topRiwayat;
    int no = 1;
    while (terbaru != NULL) {
        cout << no++ << ". " << terbaru->namacust << " - " << terbaru->jenisRoti << " - Rp" << terbaru->totalhrg << "\n";
        terbaru = terbaru->next;
    }
}

int main() {
    system("cls");
    int pil;
    do {
        cout << "\n``` Toko Roti 'Manis Lezat' ```\n";
        cout << "1. Ambil Antrean\n";
        cout << "2. Layani Pembeli\n";
        cout << "3. Tampilkan Pesanan\n";
        cout << "4. Batalkan Pesanan\n";
        cout << "5. Tampilkan History Pesanan\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pil;
        system("cls");

        switch (pil) {
            case 1: ambilAntrean(); break;
            case 2: layaniPembeli(); break;
            case 3: tampilkanAntrean(); break;
            case 4: batalkanPesanan(); break;
            case 5: tampilkanHistory(); break;
            case 6:
                cout << "Terima kasih telah belanja di toko kami. Selamat Menikmati!";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pil != 6);

    return 0;
}

