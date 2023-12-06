#include <iostream>
#include <string>

using namespace std;

struct CabangSewa {
    string namaCabang;
    string lokasiCabang;
    int* stokMobil;
    CabangSewa* next;

    CabangSewa() : namaCabang(""), lokasiCabang(""), stokMobil(nullptr), next(nullptr) {}

    CabangSewa(const CabangSewa& cabang) : namaCabang(cabang.namaCabang), lokasiCabang(cabang.lokasiCabang), next(nullptr) {
        stokMobil = new int[3];
        for (int i = 0; i < 3; i++) {
            stokMobil[i] = cabang.stokMobil[i];
        }
    }
};

class ManajemenSewa {
public:
    ManajemenSewa() : cabangSewaHead(nullptr) {}

    ~ManajemenSewa() {
        while (cabangSewaHead) {
            CabangSewa* temp = cabangSewaHead;
            cabangSewaHead = cabangSewaHead->next;
            delete[] temp->stokMobil;
            delete temp;
        }
    }

    void tambahCabangManual() {
        CabangSewa cabang;
        cout << "Masukkan nama cabang: ";
        cin.ignore();
        getline(cin, cabang.namaCabang);
        cout << "Masukkan lokasi cabang: ";
        getline(cin, cabang.lokasiCabang);
        cabang.stokMobil = new int[3];
        cout << "Masukkan stok mobil (Tipe A, Tipe B, Tipe C): ";
        cin >> cabang.stokMobil[0] >> cabang.stokMobil[1] >> cabang.stokMobil[2];

        if (!cabangSewaHead) {
            cabangSewaHead = new CabangSewa(cabang);
        } else {
            CabangSewa* current = cabangSewaHead;
            while (current->next) {
                current = current->next;
            }
            current->next = new CabangSewa(cabang);
        }

        cout << "Cabang baru berhasil ditambahkan." << endl;
    }

    void tampilCabang() {
        cout << "Daftar Cabang Penyewaan Mobil:" << endl;
        CabangSewa* current = cabangSewaHead;
        while (current) {
            cout << "Nama Cabang: " << current->namaCabang << endl;
            cout << "Lokasi: " << current->lokasiCabang << endl;
            cout << "Stok Mobil (Tipe A, Tipe B, Tipe C): ";
            for (int j = 0; j < 3; j++) {
                cout << current->stokMobil[j];
                if (j < 2) {
                    cout << ", ";
                }
            }
            cout << " unit" << endl;
            cout << "---------------------------" << endl;
            current = current->next;
        }
    }

    void hapusCabang(string namaCabang) {
        if (!cabangSewaHead) {
            cout << "Daftar cabang kosong." << endl;
            return;
        }

        if (cabangSewaHead->namaCabang == namaCabang) {
            CabangSewa* temp = cabangSewaHead;
            cabangSewaHead = cabangSewaHead->next;
            delete[] temp->stokMobil;
            delete temp;
            cout << "Cabang berhasil dihapus." << endl;
            return;
        }

        CabangSewa* current = cabangSewaHead;
        while (current->next && current->next->namaCabang != namaCabang) {
            current = current->next;
        }

        if (current->next) {
            CabangSewa* temp = current->next;
            current->next = current->next->next;
            delete[] temp->stokMobil;
            delete temp;
            cout << "Cabang berhasil dihapus." << endl;
        } else {
            cout << "Cabang dengan nama " << namaCabang << " tidak ditemukan." << endl;
        }
    }

private:
    CabangSewa* cabangSewaHead;
};

int main() {
    ManajemenSewa manajemenSewa;

    int pilihan;

    do {
        cout << "Menu:\n";
        cout << "1. Tampilkan Cabang\n";
        cout << "2. Tambah Cabang\n";
        cout << "3. Hapus Cabang\n";
        cout << "4. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                manajemenSewa.tampilCabang();
                break;
            case 2:
                manajemenSewa.tambahCabangManual();
                break;
            case 3:
                {
                    cin.ignore();
                    string namaCabang;
                    cout << "Masukkan nama cabang yang ingin dihapus: ";
                    getline(cin, namaCabang);
                    manajemenSewa.hapusCabang(namaCabang);
                }
                break;
            case 4:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Opsi tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 4);

    return 0;
}
