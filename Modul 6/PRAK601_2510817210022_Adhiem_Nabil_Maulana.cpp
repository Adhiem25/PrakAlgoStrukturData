#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;

void clrscr() { system("cls"); }

void sequentialSearching() {
    clrscr();
    int data[100], cari = 7, counter = 0, flag = 0, save;
    srand(time(NULL));
    printf("generating 100 number . . .\n");
    for (int i = 0; i < 100; i++) {
        data[i] = rand() % 100 + 1;
        printf("%d ", data[i]);
    }
    printf("\ndone.\n");
    for (int i = 0; i < 100; i++) {
        if (data[i] == cari) { counter++; flag = 1; save = i; }
    }
    if (flag == 1) {
        printf("Data ada, sebanyak %d!\n", counter);
        printf("pada indeks ke-%d\n", save);
    } else {
        printf("Data tidak ada!\n");
    }
    printf("\nTekan Enter untuk kembali ke menu...");
    cin.ignore(); cin.get();
}

void binarySearching() {
    clrscr();
    int n, kiri, kanan, tengah, temp, key;
    bool ketemu = false;
    cout << "Masukan jumlah data (maks 100)? "; cin >> n;
    if (n > 100) n = 100;
    int angka[100];
    for (int i = 0; i < n; i++) {
        cout << "Angka ke - [" << i << "] : "; cin >> angka[i];
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - 1; j++)
            if (angka[j] > angka[j+1]) { temp=angka[j]; angka[j]=angka[j+1]; angka[j+1]=temp; }
    cout << "----------------------------------------\n";
    cout << "Data yang telah diurutkan adalah:\n";
    for (int i = 0; i < n; i++) cout << angka[i] << " ";
    cout << "\n----------------------------------------\n";
    cout << "Masukan angka yang dicari: "; cin >> key;
    kiri = 0; kanan = n - 1;
    while (kiri <= kanan) {
        tengah = (kiri + kanan) / 2;
        if (key == angka[tengah])      { ketemu = true; break; }
        else if (key < angka[tengah])  { kanan = tengah - 1; }
        else                           { kiri  = tengah + 1; }
    }
    if (ketemu) cout << "Angka ditemukan! Berada di indeks ke-" << tengah << "\n";
    else        cout << "Angka tidak ditemukan!\n";
    cout << "\nTekan Enter untuk kembali ke menu...";
    cin.ignore(); cin.get();
}

void jelaskanPerbedaan() {
    clrscr();
    cout << "=======================================================\n";
    cout << "  PERBEDAAN SEQUENTIAL SEARCHING & BINARY SEARCHING\n";
    cout << "=======================================================\n";
    cout << "1. SEQUENTIAL SEARCHING\n";
    cout << "   Cara Kerja : Memeriksa elemen satu per satu dari awal.\n";
    cout << "   Kelebihan  : Sederhana, data tidak perlu terurut.\n";
    cout << "   Kekurangan : Lambat untuk data besar (O(n)).\n\n";
    cout << "2. BINARY SEARCHING\n";
    cout << "   Cara Kerja : Membagi array jadi dua, cek nilai tengah.\n";
    cout << "   Kelebihan  : Sangat cepat untuk data besar (O(log n)).\n";
    cout << "   Kekurangan : Data HARUS diurutkan terlebih dahulu.\n";
    cout << "=======================================================\n";
    cout << "  KESIMPULAN:\n";
    cout << "  Sequential -> data kecil/tidak terurut.\n";
    cout << "  Binary     -> data besar yang sudah terurut.\n";
    cout << "=======================================================\n";
    cout << "\nTekan Enter untuk kembali ke menu...";
    cin.ignore(); cin.get();
}

int main() {
    int pilih;
    do {
        clrscr();
        cout << "Pilih menu\n";
        cout << "1. Sequential Searching\n";
        cout << "2. Binary Searching\n";
        cout << "3. Jelaskan Perbedaan Sequential Searching dan Binary Searching!\n";
        cout << "4. Exit\n";
        cout << "Pilih : "; cin >> pilih;
        switch (pilih) {
            case 1: sequentialSearching(); break;
            case 2: binarySearching();     break;
            case 3: jelaskanPerbedaan();   break;
            case 4: cout << "Terima kasih! Program selesai.\n"; break;
            default: cout << "Pilihan tidak valid!\n"; break;
        }
    } while (pilih != 4);
    return 0;
}