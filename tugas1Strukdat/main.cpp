#include <iostream>
#include <vector>
#include <string>

using namespace std;


void tampilkanMenu() {
    cout << "\nMenu:\n";
    cout << "1. Tampilkan Data\n";
    cout << "2. Tambah Data\n";
    cout << "3. Hapus Data\n";
    cout << "4. Ubah Data\n";
    cout << "5. Cari Data\n";
    cout << "6. Keluar\n";
    cout << "Masukkan pilihan Anda: ";
}

int main() {
    vector<string> data;
    string namaBaru;
    string namaCari;
    bool ditemukan = false;

    while (true) {
        tampilkanMenu();
        int pilihan;
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                if (data.empty()) {
                    cout << "Tidak ada data untuk ditampilkan.\n";
                } else {
                    cout << "Data:\n";
                    for (const string& nama : data) {
                        cout << nama << endl;
                    }
                }
                break;

            case 2:
                cout << "Masukkan sebuah nama untuk ditambahkan: ";
                cin.ignore();
                getline(cin, namaBaru);
                data.push_back(namaBaru);
                cout << "Data berhasil ditambahkan.\n";
                break;

            case 3:
                if (data.empty()) {
                    cout << "Tidak ada data untuk dihapus.\n";
                } else {
                    cout << "Masukkan indeks untuk dihapus (0-" << data.size() - 1 << "): ";
                    int indeks;
                    cin >> indeks;

                    if (indeks >= 0 && indeks < data.size()) {
                        data.erase(data.begin() + indeks);
                        cout << "Data berhasil dihapus.\n";
                    } else {
                        cout << "Indeks tidak valid.\n";
                    }
                }
                break;

            case 4:
                if (data.empty()) {
                    cout << "Tidak ada data untuk diubah.\n";
                } else {
                    cout << "Masukkan indeks untuk diubah (0-" << data.size() - 1 << "): ";
                    int indeks;
                    cin >> indeks;

                    if (indeks >= 0 && indeks < data.size()) {
                        cout << "Masukkan nama baru: ";
                        cin.ignore();
                        getline(cin, namaBaru);
                        data[indeks] = namaBaru;
                        cout << "Data berhasil diubah.\n";
                    } else {
                        cout << "Indeks tidak valid.\n";
                    }
                }
                break;

            case 5: // Cari Data
                cout << "Masukkan nama yang ingin dicari: ";
                cin.ignore(); 
                getline(cin, namaCari);

                ditemukan = false;
                for (int i = 0; i < data.size(); ++i) {
                    if (data[i] == namaCari) {
                        cout << "Ditemukan pada indeks " << i << ": " << data[i] << endl;
                        ditemukan = true;
                    }
                }

                if (!ditemukan) {
                    cout << "Nama tidak ditemukan.\n";
                }
                break;

            case 6: // Keluar
                cout << "Selamat tinggal!\n";
                return 0;

            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
        }
    }

    return 0;
}
