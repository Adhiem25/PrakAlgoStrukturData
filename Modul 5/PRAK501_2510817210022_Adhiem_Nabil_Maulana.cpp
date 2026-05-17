#include <iostream>
using namespace std;

int NIM[] = {2, 5, 1, 0, 8, 1, 7, 2, 1, 0, 0, 2, 2};
char Nama[] = {'A', 'D', 'H', 'I', 'E', 'M', 'N', 'A', 'B', 'I', 'L', 'M', 'A', 'U', 'L', 'A', 'N', 'A'};
int sz_nim  = sizeof(NIM)  / sizeof(NIM[0]);
int sz_nama = sizeof(Nama) / sizeof(Nama[0]);

void tampilAngka(int arr[], int sz) {
    cout << "[ ";
    for (int i = 0; i < sz; i++) cout << arr[i] << (i < sz-1 ? ", " : " ");
    cout << "]";
}

void tampilHuruf(char arr[], int sz) {
    cout << "[ ";
    for (int i = 0; i < sz; i++) cout << arr[i] << (i < sz-1 ? ", " : " ");
    cout << "]";
}

void tukarAngka(int &x, int &y) {
    int tmp = x; x = y; y = tmp;
}


void insertionSortNama() {
    char tmp[sz_nama];
    for (int i = 0; i < sz_nama; i++) tmp[i] = Nama[i];

    cout << "\n  Data Awal   : "; tampilHuruf(tmp, sz_nama);

    for (int i = 1; i < sz_nama; i++) {
        char kunci = tmp[i];
        int  j     = i - 1;
        while (j >= 0 && tmp[j] > kunci) {
            tmp[j + 1] = tmp[j];
            j--;
        }
        tmp[j + 1] = kunci;
    }

    cout << "\n  Hasil Urut  : "; tampilHuruf(tmp, sz_nama);
    cout << "\n  Metode      : Insertion Sort (karakter huruf nama)\n";
}


void gabungkan(char arr[], int kiri, int tengah, int kanan) {
    int sz1 = tengah - kiri + 1;
    int sz2 = kanan - tengah;
    char L[sz1], R[sz2];

    for (int i = 0; i < sz1; i++) L[i] = arr[kiri + i];
    for (int j = 0; j < sz2; j++) R[j] = arr[tengah + 1 + j];

    int i = 0, j = 0, k = kiri;
    while (i < sz1 && j < sz2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < sz1) arr[k++] = L[i++];
    while (j < sz2) arr[k++] = R[j++];
}

void mergeRekursif(char arr[], int kiri, int kanan) {
    if (kiri < kanan) {
        int tengah = kiri + (kanan - kiri) / 2;
        mergeRekursif(arr, kiri, tengah);
        mergeRekursif(arr, tengah + 1, kanan);
        gabungkan(arr, kiri, tengah, kanan);
    }
}

void mergeSortNama() {
    char tmp[sz_nama];
    for (int i = 0; i < sz_nama; i++) tmp[i] = Nama[i];

    cout << "\n  Data Awal   : "; tampilHuruf(tmp, sz_nama);

    mergeRekursif(tmp, 0, sz_nama - 1);

    cout << "\n  Hasil Urut  : "; tampilHuruf(tmp, sz_nama);
    cout << "\n  Metode      : Merge Sort (karakter huruf nama)\n";
}

void shellSortNama() {
    char tmp[sz_nama];
    for (int i = 0; i < sz_nama; i++) tmp[i] = Nama[i];

    cout << "\n  Data Awal   : "; tampilHuruf(tmp, sz_nama);

    int jarak = sz_nama / 2;
    while (jarak > 0) {
        for (int i = jarak; i < sz_nama; i++) {
            char simpan = tmp[i];
            int  j      = i;
            while (j >= jarak && tmp[j - jarak] > simpan) {
                tmp[j] = tmp[j - jarak];
                j -= jarak;
            }
            tmp[j] = simpan;
        }
        jarak /= 2;
    }

    cout << "\n  Hasil Urut  : "; tampilHuruf(tmp, sz_nama);
    cout << "\n  Metode      : Shell Sort (karakter huruf nama)\n";
}


int partisi(int arr[], int kiri, int kanan) {
    int pivot = arr[kiri]; 
    int i     = kiri + 1;
    int j     = kanan;

    while (true) {
        while (i <= j && arr[i] <= pivot) i++;
        while (j >= i && arr[j] >  pivot) j--;
        if (i >= j) break;
        tukarAngka(arr[i], arr[j]);
    }
    tukarAngka(arr[kiri], arr[j]);
    return j;
}

void quickRekursif(int arr[], int kiri, int kanan) {
    if (kiri < kanan) {
        int p = partisi(arr, kiri, kanan);
        quickRekursif(arr, kiri, p - 1);
        quickRekursif(arr, p + 1, kanan);
    }
}

void quickSortNIM() {
    int tmp[sz_nim];
    for (int i = 0; i < sz_nim; i++) tmp[i] = NIM[i];

    cout << "\n  Data Awal   : "; tampilAngka(tmp, sz_nim);

    quickRekursif(tmp, 0, sz_nim - 1);

    cout << "\n  Hasil Urut  : "; tampilAngka(tmp, sz_nim);
    cout << "\n  Metode      : Quick Sort (digit angka NIM)\n";
}

void bubbleSortNIM() {
    int tmp[sz_nim];
    for (int i = 0; i < sz_nim; i++) tmp[i] = NIM[i];

    cout << "\n  Data Awal   : "; tampilAngka(tmp, sz_nim);

    bool adaTukar;
    for (int i = 0; i < sz_nim - 1; i++) {
        adaTukar = false;
        for (int j = sz_nim - 1; j > i; j--) {
            if (tmp[j] < tmp[j - 1]) {
                tukarAngka(tmp[j], tmp[j - 1]);
                adaTukar = true;
            }
        }
        if (!adaTukar) break;
    }

    cout << "\n  Hasil Urut  : "; tampilAngka(tmp, sz_nim);
    cout << "\n  Metode      : Bubble Sort (digit angka NIM)\n";
}

void selectionSortNIM() {
    int tmp[sz_nim];
    for (int i = 0; i < sz_nim; i++) tmp[i] = NIM[i];

    cout << "\n  Data Awal   : "; tampilAngka(tmp, sz_nim);

    for (int i = sz_nim - 1; i > 0; i--) { 
        int idx_max = 0;
        for (int j = 1; j <= i; j++) {
            if (tmp[j] > tmp[idx_max]) idx_max = j;
        }
        tukarAngka(tmp[i], tmp[idx_max]);
    }

    cout << "\n  Hasil Urut  : "; tampilAngka(tmp, sz_nim);
    cout << "\n  Metode      : Selection Sort (digit angka NIM)\n";
}

int main() {
    int pilihan;
    do {
        cout << "\n+---------------------------+" << endl;
        cout << "|        S O R T I N G      |" << endl;
        cout << "+---------------------------+" << endl;
        cout << "  1. Insertion Sort  (Nama)"   << endl;
        cout << "  2. Merge Sort      (Nama)"   << endl;
        cout << "  3. Shell Sort      (Nama)"   << endl;
        cout << "  4. Quick Sort      (NIM) "   << endl;
        cout << "  5. Bubble Sort     (NIM) "   << endl;
        cout << "  6. Selection Sort  (NIM) "   << endl;
        cout << "  7. Exit"                      << endl;
        cout << "+---------------------------+" << endl;
        cout << "  Pilihan : ";
        cin  >> pilihan;

        switch (pilihan) {
            case 1: insertionSortNama(); break;
            case 2: mergeSortNama();     break;
            case 3: shellSortNama();     break;
            case 4: quickSortNIM();      break;
            case 5: bubbleSortNIM();     break;
            case 6: selectionSortNIM();  break;
            case 7:
                cout << "\n  Terima kasih!" << endl;
                cout << "  Dibuat oleh : Adhiem Nabil Maulana" << endl;
                cout << "  NIM         : 2510817210022" << endl;
                return 0;
            default:
                cout << "\n  [!] Pilihan tidak valid.\n";
        }

        cout << "\nTekan Enter untuk melanjutkan...";
        cin.ignore();
        cin.get();
        system("cls");

    } while (pilihan != 7);
    return 0;
}