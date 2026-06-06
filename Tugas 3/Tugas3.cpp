#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>
using namespace std;

void tampilJudul() {
    cout << "\n======================================================\n";
    cout << "   PROGRAM PENCARIAN PASANGAN DENGAN BINARY SEARCH   \n";
    cout << "======================================================\n";
    cout << " Deskripsi : Mencari pasangan elemen array yang\n";
    cout << "             jumlahnya sama dengan target X\n";
    cout << " Sorting   : Merge Sort\n";
    cout << " Searching : Binary Search\n";
    cout << "======================================================\n\n";
}

// ----- MERGE SORT -----
void gabungArray(int arr[], int kiri, int tengah, int kanan) {
    int ukuranKiri = tengah - kiri + 1;
    int ukuranKanan = kanan - tengah;

    int tempKiri[ukuranKiri], tempKanan[ukuranKanan];

    for (int i = 0; i < ukuranKiri; i++)
        tempKiri[i] = arr[kiri + i];
    for (int j = 0; j < ukuranKanan; j++)
        tempKanan[j] = arr[tengah + 1 + j];

    int i = 0, j = 0, k = kiri;
    while (i < ukuranKiri && j < ukuranKanan) {
        if (tempKiri[i] <= tempKanan[j])
            arr[k++] = tempKiri[i++];
        else
            arr[k++] = tempKanan[j++];
    }
    while (i < ukuranKiri) arr[k++] = tempKiri[i++];
    while (j < ukuranKanan) arr[k++] = tempKanan[j++];
}

void mergeSort(int arr[], int kiri, int kanan) {
    if (kiri >= kanan) return;
    int tengah = kiri + (kanan - kiri) / 2;
    mergeSort(arr, kiri, tengah);
    mergeSort(arr, tengah + 1, kanan);
    gabungArray(arr, kiri, tengah, kanan);
}

// ----- BINARY SEARCH -----
bool binarySearch(int arr[], int kiri, int kanan, int target) {
    while (kiri <= kanan) {
        int tengah = kiri + (kanan - kiri) / 2;
        if (arr[tengah] == target)
            return true;
        else if (arr[tengah] < target)
            kiri = tengah + 1;
        else
            kanan = tengah - 1;
    }
    return false;
}

int main() {
    tampilJudul();

    int N, X;
    cout << "Masukkan N (jumlah elemen) dan X (target): ";
    cin >> N >> X;

    int arr[N];
    srand(time(NULL));

    cout << "\nArray yang di-generate (1-25): ";
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 25 + 1;
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr, 0, N - 1);

    cout << "Array setelah diurutkan     : ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n" << endl;

    // cari pasangan - loop tiap elemen, cari komplemen di sebelah kanannya
    set<pair<int, int>> hasilPasangan;

    for (int i = 0; i < N - 1; i++) {
        int komplemen = X - arr[i];

        // cari komplemen mulai dari i+1 biar tidak pakai indeks yang sama
        if (binarySearch(arr, i + 1, N - 1, komplemen)) {
            hasilPasangan.insert({arr[i], komplemen});
        }
    }

    cout << "Pasangan yang ditemukan:" << endl;
    if (hasilPasangan.empty()) {
        cout << "  Tidak ada pasangan yang jumlahnya " << X << endl;
    } else {
        for (auto p : hasilPasangan) {
            cout << "  " << p.first << " + " << p.second << " = " << X << endl;
        }
    }

    cout << "\nTotal pasangan unik: " << hasilPasangan.size() << endl;
    cout << "======================================================\n";

    return 0;
}