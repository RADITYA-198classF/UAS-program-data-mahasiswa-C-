#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits> // Untuk validasi input
using namespace std;

// Struktur data untuk mahasiswa
struct Mahasiswa {
    int nim;
    string nama;
    string fakultas;
    string jurusan;
};

// Fungsi untuk menambahkan data mahasiswa
void tambahMahasiswa(vector<Mahasiswa>& daftarMahasiswa) {
    Mahasiswa mahasiswa;
    cout << "Masukkan NIM Mahasiswa: ";
    while (!(cin >> mahasiswa.nim)) {
        cout << "Input tidak valid. Masukkan angka untuk NIM.\nMasukkan NIM Mahasiswa: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(); // Membersihkan buffer input
    cout << "Masukkan Nama Mahasiswa: ";
    getline(cin, mahasiswa.nama);
    cout << "Masukkan Fakultas: ";
    getline(cin, mahasiswa.fakultas);
    cout << "Masukkan Jurusan: ";
    getline(cin, mahasiswa.jurusan);

    daftarMahasiswa.push_back(mahasiswa);
    cout << "Data mahasiswa berhasil ditambahkan!\n";
}

// Fungsi untuk menampilkan semua data mahasiswa
void lihatMahasiswa(const vector<Mahasiswa>& daftarMahasiswa) {
    if (daftarMahasiswa.empty()) {
        cout << "Belum ada data mahasiswa.\n";
        return;
    }

    cout << left << setw(10) << "NIM"
         << setw(20) << "Nama"
         << setw(20) << "Fakultas"
         << setw(20) << "Jurusan" << endl;
    cout << "------------------------------------------------------------\n";
    for (const auto& mahasiswa : daftarMahasiswa) {
        cout << left << setw(10) << mahasiswa.nim
             << setw(20) << mahasiswa.nama
             << setw(20) << mahasiswa.fakultas
             << setw(20) << mahasiswa.jurusan << endl;
    }
}

// Fungsi untuk mencari data mahasiswa berdasarkan NIM
void cariMahasiswa(const vector<Mahasiswa>& daftarMahasiswa, int nim) {
    for (const auto& mahasiswa : daftarMahasiswa) {
        if (mahasiswa.nim == nim) {
            cout << "Data Mahasiswa Ditemukan:\n";
            cout << "NIM: " << mahasiswa.nim << "\n";
            cout << "Nama: " << mahasiswa.nama << "\n";
            cout << "Fakultas: " << mahasiswa.fakultas << "\n";
            cout << "Jurusan: " << mahasiswa.jurusan << "\n";
            return;
        }
    }
    cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan.\n";
}

// Fungsi untuk menghapus data mahasiswa berdasarkan NIM
void hapusMahasiswa(vector<Mahasiswa>& daftarMahasiswa, int nim) {
    for (auto it = daftarMahasiswa.begin(); it != daftarMahasiswa.end(); ++it) {
        if (it->nim == nim) {
            daftarMahasiswa.erase(it);
            cout << "Data mahasiswa berhasil dihapus.\n";
            return;
        }
    }
    cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan.\n";
}

// Menu utama
int main() {
    vector<Mahasiswa> daftarMahasiswa;
    int pilihan, nim;

    do {
        cout << "\n=== Sistem Pengelolaan Data Mahasiswa ===\n";
        cout << "1. Tambah Mahasiswa\n";
        cout << "2. Lihat Mahasiswa\n";
        cout << "3. Cari Mahasiswa\n";
        cout << "4. Hapus Mahasiswa\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        if (!(cin >> pilihan)) {
            cout << "Input tidak valid. Masukkan angka.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (pilihan) {
            case 1:
                tambahMahasiswa(daftarMahasiswa);
                break;
            case 2:
                lihatMahasiswa(daftarMahasiswa);
                break;
            case 3:
                cout << "Masukkan NIM Mahasiswa: ";
                while (!(cin >> nim)) {
                    cout << "Input tidak valid. Masukkan angka untuk NIM.\nMasukkan NIM Mahasiswa: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cariMahasiswa(daftarMahasiswa, nim);
                break;
            case 4:
                cout << "Masukkan NIM Mahasiswa yang akan dihapus: ";
                while (!(cin >> nim)) {
                    cout << "Input tidak valid. Masukkan angka untuk NIM.\nMasukkan NIM Mahasiswa yang akan dihapus: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                hapusMahasiswa(daftarMahasiswa, nim);
                break;
            case 5:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih menu yang tersedia.\n";
        }
    } while (pilihan != 5);

    return 0;
}
