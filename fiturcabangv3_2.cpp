#include <iostream>
#include <string>

using namespace std;

struct CabangSewa {
    string namaCabang;
    string lokasiCabang;
    int* stokMobil;
};

class ManajemenSewa {
public:
    ManajemenSewa() {
        cabangSewa = new CabangSewa[MAX_CABANG];
        cabangSewaCount = 0;
    }

    ~ManajemenSewa() {
        for (int i = 0; i < cabangSewaCount; i++) {
            delete[] cabangSewa[i].stokMobil;
        }
        delete[] cabangSewa;
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
        cabangSewa[cabangSewaCount++] = cabang;
        cout << "Cabang baru berhasil ditambahkan." << endl;
    }

    void tampilCabang() {
        cout << "Daftar Cabang Penyewaan Mobil:" << endl;
        for (int i = 0; i < cabangSewaCount; i++) {
            cout << "Nama Cabang: " << cabangSewa[i].namaCabang << endl;
            cout << "Lokasi: " << cabangSewa[i].lokasiCabang << endl;
            cout << "Stok Mobil (Tipe A, Tipe B, Tipe C): ";
            for (int j = 0; j < 3; j++) {
                cout << cabangSewa[i].stokMobil[j];
                if (j < 2) {
                    cout << ", ";
                }
            }
            cout << " unit" << endl;
            cout << "---------------------------" << endl;
        }
    }

private:
    CabangSewa* cabangSewa;
    int cabangSewaCount;
    static const int MAX_CABANG = 10;
};

int main() {
    ManajemenSewa manajemenSewa;

    int pilihan;

    do {
        cout << "Menu:\n";
        cout << "1. Tampilkan Cabang\n";
        cout << "2. Tambah Cabang\n";
        cout << "3. Keluar\n";
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
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Opsi tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 3);

    return 0;
}
