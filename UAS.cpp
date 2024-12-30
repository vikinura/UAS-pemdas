#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Pasien {
    string nama;
    string umur;
    string jenisKelamin;
    string alamat;
};

struct Evaluasi {
    string kategori;
    string kritikSaran;
};

void formPendaftaran(Pasien &pasien) {
    cout << "=== Form Pendaftaran Pasien ===" << endl;
    cout << "Nama: ";
    getline(cin, pasien.nama);
    cout << "Umur: ";
    getline(cin, pasien.umur);
    cout << "Jenis Kelamin (L/P): ";
    getline(cin, pasien.jenisKelamin);
    cout << "Alamat: ";
    getline(cin, pasien.alamat);
    cout << "\nPendaftaran berhasil!\n\n";
}

void menuEvaluasi(vector<Evaluasi> &evaluasiList) {
    int pilihan;
    string kritikSaran;

    cout << "=== apa yang ingin anda evaluasi ===" << endl;
    cout << "1. Tenaga Kesehatan" << endl;
    cout << "2. Fasilitas" << endl;
    cout << "3. Makanan " << endl;
    cout << "4. Obat " << endl;
    cout << "5. Pelayanan Perawat" << endl;
    cout << "6. Kebersihan" << endl;
    cout << "Pilih kategori evaluasi (1-6): ";
    cin >> pilihan;
    cin.ignore(); 

    string kategori;
    switch (pilihan) {
        case 1:
            kategori = "Tenaga Kesehatan";
            break;
        case 2:
            kategori = "Fasilitas";
            break;
        case 3:
            kategori = "Makanan ";
            break;
        case 4:
            kategori = "Obat ";
            break;
        case 5:
            kategori = "Pelayanan Perawat";
            break;
        case 6:
            kategori = "Kebersihan";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
            return;
    }

    cout << "Berikan kritik atau saran untuk " << kategori << ": \n";
    getline(cin, kritikSaran);

    Evaluasi evaluasi = {kategori, kritikSaran};
    evaluasiList.push_back(evaluasi);
    cout << "\nEvaluasi berhasil disimpan!\n\n";
}

void buatLaporan(const Pasien &pasien, const vector<Evaluasi> &evaluasiList) {
    ofstream laporan("laporan_evaluasi.txt");
    if (!laporan.is_open()) {
        cout << "Gagal membuat laporan.\n";
        return;
    }

    laporan << "=== Laporan Evaluasi Pasien ===\n";
    laporan << "Nama: " << pasien.nama << "\n";
    laporan << "Umur: " << pasien.umur << "\n";
    laporan << "Jenis Kelamin: " << pasien.jenisKelamin << "\n";
    laporan << "Alamat: " << pasien.alamat << "\n\n";

    laporan << "=== Evaluasi ===\n";
    for (const auto &evaluasi : evaluasiList) {
        laporan << "Kategori: " << evaluasi.kategori << "\n";
        laporan << "Kritik/Saran: " << evaluasi.kritikSaran << "\n\n";
    }

    laporan.close();
    cout << "Laporan berhasil dibuat dengan nama 'laporan_evaluasi.txt'\n";
}

int main() {
    Pasien pasien;
    vector<Evaluasi> evaluasiList;

    formPendaftaran(pasien);

    char lanjut;
    do {
        menuEvaluasi(evaluasiList);
        cout << "Apakah ingin menambah evaluasi lagi? (y/n): ";
        cin >> lanjut;
        cin.ignore(); 
    } while (lanjut == 'y' || lanjut == 'Y');

    buatLaporan(pasien, evaluasiList);

    return 0;
}
