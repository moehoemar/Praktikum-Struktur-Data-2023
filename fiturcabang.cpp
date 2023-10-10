#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct CabangSewa {
    string namaCabang;
    string lokasiCabang;
    int stokMobil;
};

class ManajemenSewa {
public:

    ManajemenSewa() {

        cabangSewa.push_back({ "Cabang A", "Jakarta", 10 });
        cabangSewa.push_back({ "Cabang B", "Surabaya", 15 });
        cabangSewa.push_back({ "Cabang C", "Bandung", 8 });
    }

    void tampilCabang() {
        cout << "Daftar Cabang Penyewaan Mobil:" << endl;
        for (const CabangSewa& cabang : cabangSewa) {
            cout << "Nama Cabang: " << cabang.namaCabang << endl;
            cout << "Lokasi: " << cabang.lokasiCabang << endl;
            cout << "Stok Mobil: " << cabang.stokMobil << " unit" << endl;
            cout << "---------------------------" << endl;
        }
    }

private:
    vector<CabangSewa> cabangSewa;
};

int main() {
    ManajemenSewa manajemenSewa;

    manajemenSewa.tampilCabang();

    return 0;
}
