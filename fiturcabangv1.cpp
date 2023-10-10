#include <iostream>
#include <string>

using namespace std;


struct CabangSewa {
    string namaCabang;
    string lokasiCabang;
    int stokMobil[3]; 
};


class ManajemenSewa {
public:

    ManajemenSewa() {

        cabangSewa[0] = { "Cabang A", "Jakarta", {10, 5, 8} };
        cabangSewa[1] = { "Cabang B", "Surabaya", {15, 7, 10} };
        cabangSewa[2] = { "Cabang C", "Bandung", {8, 3, 6} };
    }


    void tampilCabang() {
        cout << "Daftar Cabang Penyewaan Mobil:" << endl;
        cout << "---------------------------" << endl;
        for (const CabangSewa& cabang : cabangSewa) {
            cout << "Nama Cabang: " << cabang.namaCabang << endl;
            cout << "Lokasi: " << cabang.lokasiCabang << endl;
            cout << "Stok Mobil (Tipe A, Tipe B, Tipe C): ";
            for (int i = 0; i < 3; i++) {
                cout << cabang.stokMobil[i];
                if (i < 2) {
                    cout << ", ";
                }
            }
            cout << " unit" << endl;
            cout << "---------------------------" << endl;
        }
    }

private:
    CabangSewa cabangSewa[3];
};

int main() {
    ManajemenSewa manajemenSewa;

    manajemenSewa.tampilCabang();

    return 0;
}
