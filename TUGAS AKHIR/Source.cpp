#include <iostream>
#include<iomanip>
#include <Windows.h>
#include<fstream>
#include<string>
using namespace std;

int jumlah_beat = 7, jumlah_vario = 5, jumlah_supra = 7;
string daftar[19][5];

int main();

void simpan() {
	fstream file;
	file.open("Storage.txt");
	if (!file.is_open())
	{
		cout << "Gagal Membuka File!!!!\n";
	}
	for (int i = 0; i <= 19; i++) {
		for (int j = 0; j < 5; j++) {
			file << daftar[i][j]<<" ";
		}
	}

	file.close();
}


void simpan2() {
	fstream file;
	file.open("Jumlah Motor.txt");
	if (!file.is_open())
	{
		cout << "Gagal Membuka File!!!!\n";
	}
	file << jumlah_beat << " " << jumlah_vario << " " << jumlah_supra;

	file.close();
}


void ambil() {
	fstream file;
	file.open("Storage.txt");
	if (!file.is_open())
	{
		cout << "Unable to open the file.\n";
	}
	for (int i = 0; i <= 19; i++) {
		for (int j = 0; j < 5; j++) {
			file >> daftar[i][j];
		}
	}

	file.close();
}

void ambil2() {
	fstream file;
	file.open("Jumlah Motor.txt");
	if (!file.is_open())
	{
		cout << "Gagal Membuka File!!!!\n";
	}
	file >> jumlah_beat;
	file >> jumlah_vario;
	file >> jumlah_supra;

	file.close();
}

void kepala() {
	cout << "================================" << endl;
	cout << "         SELAMAT DATANG" << endl;
	cout << "================================" << endl;
	cout << " Program Penyewaan Sepeda Motor" << endl;
	cout << "================================" << endl;
}


//Fungsi Pengisian Data
void pilihan1() {
	string check;

	for (int g = 0; g <= 19; g++) {
		if (daftar[g][0] == "1") {
			check = "Fill";
		}
		else {
			break;
		}
	}

	for (int i = 0; i <= 19; i++) {
		if (daftar[i][0] == "" || daftar[i][0] == "0" || daftar[i][0]=="N/A") {
			cout << "Nama: ";
			cin >> daftar[i][1];
			cout << "NIK: ";
			cin >> daftar[i][2];
			//cout << "Jenis motor: ";
			//cin >> daftar[i][3];
			cout << "Durasi pemakaian(hari): ";
			cin >> daftar[i][4];


			pilihmotor:
			system("cls");
			string temp;
			kepala();
			cout << "1. Motor Beat (Tersedia " << jumlah_beat << " unit)" << endl;
			cout << "2. Motor Vario (Tersedia " << jumlah_vario << " unit)" << endl;
			cout << "3. Motor Supra (Tersedia " << jumlah_supra << " unit)" << endl;
			cout << "Silahkan Pilih Jenis Motor Yang Akan Disewa(1-3): ";
			cin >> temp;
			if (temp == "1" && jumlah_beat != 0) {
				daftar[i][3] = "Beat";
				jumlah_beat--;
			}
			else if (temp == "2" && jumlah_vario != 0) {
				daftar[i][3] = "Vario";
				jumlah_vario--;
			}
			else if (temp == "3" && jumlah_supra != 0) {
				daftar[i][3] = "Supra";
				jumlah_supra--;
			}
			else {
				cout << "Maaf pilihan yang anda masukkan tidak tersedia";
				Sleep(3000);
				goto pilihmotor;
			}

			daftar[i][0] = "1";
			simpan();
			simpan2();
			break;
		}
	}
}

void pilihan2() {
	cout << "Nomor Urut" << setw(20) << "Nama" << setw(20) << "NIK" << setw(20) << "Jenis Motor" << setw(20)<<"Durasi(hari)"<< endl;
	for (int i = 0; i <= 19; i++) {
		cout <<i+1<< setw(30) << daftar[i][1] << setw(20) << daftar[i][2] << setw(20) << daftar[i][3] << setw(20) << daftar[i][4] << endl;
	}
}

void pilihan3() {
	string nama, no;
	int no_urut, X, uang;
	int bayar=1;
	kepala();
	cout << "MENU PENGEMBALIAN SEPEDA MOTOR" << endl;
	cout << "================================" << endl;
	cout << "Masukkan nomor urut: ";
	cin >> no;
	cout << "Masukkan nama penyewa: ";
	cin >> nama;
	no_urut = stoi(no);
	X = no_urut - 1;
	if (nama != daftar[no_urut - 1][1] || daftar[X][0] == "0") {
		cout << "VERIFIKASI GAGAL | DATA TIDAK SESUAI" << endl;
		cout << "Mohon masukkan data sesuai dengan list!!!";
		Sleep(5000);
		system("cls");
		main();
	}
	else {
		int hari = stoi(daftar[X][4]);
		if (daftar[X][3] == "Beat") {
			bayar = hari * 85000;
			jumlah_beat++;
		}
		else if (daftar[X][3] == "Vario") {
			bayar = hari * 90000;
			jumlah_vario++;
		}
		else if (daftar[X][3] == "Supra") {
			bayar = hari * 70000;
			jumlah_supra++;
		} else{}

	
		pembayaran:
		system("cls");
		kepala();
		cout << "MENU PENGEMBALIAN SEPEDA MOTOR" << endl;
		cout << "================================" << endl;
		cout << "Nama: " << daftar[X][1] << endl;
		cout << "NIK: " << daftar[X][2] << endl;
		cout << "Jenis motor: " << daftar[X][3] << endl;
		cout << "Durasi penyewaan: " << daftar[X][4] << " Hari" << endl;
		cout << "Total biaya sewa: Rp. " << bayar << endl;
		cout << "Jumlah yang dibayarkan: ";
		cin >> uang;
		if (bayar > uang) {
			cout << "Maaf uang tidak cukup"<<endl;
			system("pause");
			goto pembayaran;
		}
		else {
			cout << "Kembalian: Rp. " << uang - bayar<< endl;
		}
		system("pause");

		for (int i = 0; i <= 5; i++) {
			daftar[X][i] = "N/A";
		}
		daftar[X][0] = "0";

	}
	simpan();
	simpan2();



}

//FUNGSI UTAMA
int main() {
	system("color b");
	char pilihan;
utama:
	ambil();
	ambil2();
	kepala();
	cout << "Menu: " << endl;
	cout << "1. Tarif Harga" << endl;
	cout << "2. Sewa Sepeda" << endl;
	cout << "3. List Penyewa" << endl;
	cout << "4. Pengembalian Sepeda" << endl;
	cout << "5. Keluar" << endl;
	cout << "Masukkan pilihan anda: ";
	cin >> pilihan;
	switch (pilihan)
	{
	case '1':
		system("cls");
		kepala();
		cout << "TARIF HARGA PENYEWAAN SEPEDA MOTOR" << endl;
		cout << "================================" << endl;
		cout << "1. Motor beat = Rp. 85.000 / hari" << endl;
		cout << "2. Motor vario = Rp. 90.000 / hari" << endl;
		cout << "1. Motor supra = Rp. 70.000 / hari" << endl;
		system("pause");
		system("cls");
		goto utama;
		break;
	case '2':
		system("cls");
		kepala();
		pilihan1();
		system("cls");
		kepala();
		cout << endl;
		cout << "      PENDAFTARAN BERHASIL" << endl;
		Sleep(2000);
		system("cls");
		goto utama;
		break;
	case '3':
		system("cls");
		kepala();
		pilihan2();
		system("pause");
		system("cls");
		goto utama;
		break;
	case '4':
		system("cls");
		pilihan3();
		system("cls");
		goto utama;
		break;
	case '5':
		break;
	default:
		cout << "Maaf pilihan yang anda masukkan tidak tersedia.";
		Sleep(2000);
		system("cls");
		goto utama;
		break;
	}
}