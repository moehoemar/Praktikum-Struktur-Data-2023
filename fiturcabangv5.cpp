#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct CabangSewa {
    string namaCabang;
    string lokasiCabang;
    int* stokMobil;
    CabangSewa* next;
    CabangSewa* previous;

    CabangSewa() : namaCabang(""), lokasiCabang(""), stokMobil(nullptr), next(nullptr), previous(nullptr) {}

    CabangSewa(const CabangSewa& cabang) : namaCabang(cabang.namaCabang), lokasiCabang(cabang.lokasiCabang), next(nullptr), previous(nullptr) {
        stokMobil = new int[3];
        for (int i = 0; i < 3; i++) {
            stokMobil[i] = cabang.stokMobil[i];
        }
    }
};

class ManajemenSewa {
public:
    ManajemenSewa() : cabangSewaHead(nullptr), cabangSewaTail(nullptr) {}

    ~ManajemenSewa() {
        while (!cabangStack.empty()) {
            deleteCabang(cabangStack.top());
            cabangStack.pop();
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
            cabangSewaTail = cabangSewaHead;
        } else {
            cabangSewaTail->next = new CabangSewa(cabang);
            cabangSewaTail->next->previous = cabangSewaTail;
            cabangSewaTail = cabangSewaTail->next;
        }

        cout << "Cabang baru berhasil ditambahkan." << endl;

        cabangStack.push(cabangSewaTail);
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

        CabangSewa* current = cabangSewaHead;
        while (current && current->namaCabang != namaCabang) {
            current = current->next;
        }

        if (current) {
            cabangStack.push(current);

            if (current->previous) {
                current->previous->next = current->next;
            } else {
                cabangSewaHead = current->next;
            }

            if (current->next) {
                current->next->previous = current->previous;
            } else {
                cabangSewaTail = current->previous;
            }

            cout << "Cabang berhasil dihapus." << endl;
        } else {
            cout << "Cabang dengan nama " << namaCabang << " tidak ditemukan." << endl;
        }
    }

    void batalHapusCabang() {
        if (cabangStack.empty()) {
            cout << "Tidak ada operasi penghapusan yang dapat dibatalkan." << endl;
            return;
        }

        CabangSewa* cabang = cabangStack.top();
        cabangStack.pop();

        if (!cabangSewaHead) {
            cabangSewaHead = cabang;
            cabangSewaTail = cabangSewaHead;
        } else {
            cabangSewaTail->next = cabang;
            cabangSewaTail->next->previous = cabangSewaTail;
            cabangSewaTail = cabangSewaTail->next;
        }

        cout << "Operasi penghapusan dibatalkan." << endl;
    }

private:
    CabangSewa* cabangSewaHead;
    CabangSewa* cabangSewaTail;
    stack<CabangSewa*> cabangStack;

    void deleteCabang(CabangSewa* cabang) {
        if (!cabang) {
            return;
        }

        delete[] cabang->stokMobil;
        delete cabang;
    }
};

int main() {
    ManajemenSewa manajemenSewa;

    int pilihan;

    do {
        cout << "Menu:\n";
        cout << "1. Tampilkan Cabang\n";
        cout << "2. Tambah Cabang\n";
        cout << "3. Hapus Cabang\n";
        cout << "4. Batal Hapus Cabang\n";
        cout << "5. Keluar\n";
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
                manajemenSewa.batalHapusCabang();
                break;
            case 5:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Opsi tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 5);

    return 0;
}
