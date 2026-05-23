#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <sstream>

using namespace std;

typedef struct TNode {
    string data;
    TNode *next;
    TNode *prev;
} TNode;

TNode *head, *tail;

int pil, menu;
char pilihan[10];
string dataBaru;

void initH();
void initHT();
int isEmptyH();
int isEmptyHT();

void tambahDepanH();
void tambahDepanHT();
void tambahBelakangH();
void tambahBelakangHT();
void hapusDepanH();
void hapusDepanHT();
void hapusBelakangH();
void hapusBelakangHT();
void tampilkanH();
void tampilkanHT();
void clearH();
void clearHT();
void hapusTargetH();
void hapusTargetHT();

int main()
{
menu:
    cout<<"Double Linked List Non Circular (DLLNC)"<<endl;
    cout<<"=============================="<<endl;
    cout<<"Silahkan pilih program DLLNC yang ingin dijalankan!"<<endl;
    cout<<"1. DLLNC dengan Head"<<endl;
    cout<<"2. DLLNC dengan Head dan Tail"<<endl;
    cout<<"3. Quit"<<endl;
    cout<<"Pilihan : ";
    cin>>menu;
    system("cls");
    if(menu==1){
        do {
            cout<<"Double Linked List Non Circular (DLLNC) (Head)"<<endl;
            cout<<"=============================================="<<endl;
            cout<<"1. Tambah Depan"<<endl;
            cout<<"2. Tambah Belakang"<<endl;
            cout<<"3. Tampilkan Data"<<endl;
            cout<<"4. Hapus Depan"<<endl;
            cout<<"5. Hapus Belakang (ke-N)"<<endl;
            cout<<"6. Hapus Target"<<endl;
            cout<<"7. Clear"<<endl;
            cout<<"8. Kembali ke Menu"<<endl;
            cout<<"Pilihan : ";
            cin>>pilihan;
            pil=atoi(pilihan);

            switch(pil) {
                case 1:
                    tambahDepanH();
                    break;
                case 2:
                    tambahBelakangH();
                    break;
                case 3:
                    tampilkanH();
                    break;
                case 4:
                    hapusDepanH();
                    break;
                case 5:
                    hapusBelakangH();
                    break;
                case 6:
                    hapusTargetH();
                    break;
                case 7:
                    clearH();
                    break;
                default:
                    system("cls");
                    goto menu;
            }

            cout<<"\npress any key to continue"<<endl;
            getch();
            system("cls");

        } while (pil<8);
    } else if(menu==2){
        do {
            cout<<"Double Linked List Non Circular (DLLNC) (Head dan Tail)"<<endl;
            cout<<"------------------------------------------------------"<<endl;
            cout<<"1. Tambah Depan"<<endl;
            cout<<"2. Tambah Belakang"<<endl;
            cout<<"3. Tampilkan Data"<<endl;
            cout<<"4. Hapus Depan"<<endl;
            cout<<"5. Hapus Belakang (ke-N)"<<endl;
            cout<<"6. Hapus Target"<<endl;
            cout<<"7. Clear"<<endl;
            cout<<"8. Kembali ke Menu"<<endl;
            cout<<"Pilihan : ";
            cin>>pilihan;
            pil=atoi(pilihan);

            switch(pil) {
                case 1:
                    tambahDepanHT();
                    break;
                case 2:
                    tambahBelakangHT();
                    break;
                case 3:
                    tampilkanHT();
                    break;
                case 4:
                    hapusDepanHT();
                    break;
                case 5:
                    hapusBelakangHT();
                    break;
                case 6:
                    hapusTargetHT();
                    break;
                case 7:
                    clearHT();
                    break;
                default:
                    system("cls");
                    goto menu;
            }

            cout<<"\nPress any key to continue"<<endl;
            getch();
            system("cls");
        } while (pil!=8);
    }

    cout<<"\nTERIMA KASIH"<<endl;
    cout<<"Program was made by Muhammad Ramadhon (2510817210015)."<<endl;
}


void initH(){
    head = NULL;
}

void initHT(){
    head = NULL;
    tail = NULL;
}

int isEmptyH(){
    if(head == NULL) return 1;
    else return 0;
}

int isEmptyHT(){
    if(tail == NULL) return 1;
    else return 0;
}


void tambahDepanH() {
    cout<<"Masukkan data (pisahkan dengan spasi) : ";
    string inputLine;
    getline(cin >> ws, inputLine);

    stringstream ss(inputLine);
    string token;
    string tokens[1000];
    int jumlah = 0;

    while (ss >> token) {
        tokens[jumlah++] = token;
    }

    if (jumlah == 0) {
        cout<<"Tidak ada data yang dimasukkan.";
        return;
    }

    for (int i = jumlah - 1; i >= 0; i--) {
        TNode *baru = new TNode;
        baru->data  = tokens[i];
        baru->next  = head;
        baru->prev  = NULL;

        if (isEmptyH() == 1) {
            head = baru;
        } else {
            head->prev = baru;
            head = baru;
        }
    }

    cout<<"Data berhasil dimasukkan di bagian depan sesuai urutan input.";
}

void tambahDepanHT() {
    cout<<"Masukkan data (pisahkan dengan spasi) : ";
    string inputLine;
    getline(cin >> ws, inputLine);

    stringstream ss(inputLine);
    string token;
    string tokens[1000];
    int jumlah = 0;

    while (ss >> token) {
        tokens[jumlah++] = token;
    }

    if (jumlah == 0) {
        cout<<"Tidak ada data yang dimasukkan.";
        return;
    }

    for (int i = jumlah - 1; i >= 0; i--) {
        TNode *baru = new TNode;
        baru->data  = tokens[i];
        baru->next  = head;
        baru->prev  = NULL;

        if (isEmptyHT() == 1) {
            head = baru;
            tail = baru;
        } else {
            head->prev = baru;
            head = baru;
        }
    }

    cout<<"Data berhasil dimasukkan di bagian depan sesuai urutan input.";
}

void tambahBelakangH() {
    cout<<"Masukkan data (pisahkan dengan spasi) : ";
    string inputLine;
    getline(cin >> ws, inputLine);

    stringstream ss(inputLine);
    string token;

    bool ada = false;

    while (ss >> token) {
        ada = true;
        TNode *baru = new TNode;
        baru->data  = token;
        baru->next  = NULL;
        baru->prev  = NULL;

        if (isEmptyH() == 1) {
            head = baru;
        } else {
            TNode *bantu = head;
            while (bantu->next != NULL)
                bantu = bantu->next;
            bantu->next = baru;
            baru->prev  = bantu;
        }
    }

    if (!ada) cout<<"Tidak ada data yang dimasukkan.";
    else      cout<<"Data berhasil dimasukkan di bagian belakang sesuai urutan input.";
}

void tambahBelakangHT() {
    cout<<"Masukkan data (pisahkan dengan spasi) : ";
    string inputLine;
    getline(cin >> ws, inputLine);

    stringstream ss(inputLine);
    string token;

    bool ada = false;

    while (ss >> token) {
        ada = true;
        TNode *baru = new TNode;
        baru->data  = token;
        baru->next  = NULL;
        baru->prev  = NULL;

        if (isEmptyHT() == 1) {
            head = baru;
            tail = baru;
        } else {
            tail->next = baru;
            baru->prev = tail;
            tail = baru;
        }
    }

    if (!ada) cout<<"Tidak ada data yang dimasukkan.";
    else      cout<<"Data berhasil dimasukkan di bagian belakang sesuai urutan input.";
}


void tampilkanH() {
    if (isEmptyH() == 0) {
        TNode *bantu = head;
        while (bantu != NULL) {
            cout<<bantu->data<<' ';
            bantu = bantu->next;
        }
        cout<<endl;
    } else cout<<"Tidak terdapat data pada Linked List";
}

void tampilkanHT() {
    if (isEmptyHT() == 0) {
        TNode *bantu = head;
        while (bantu != NULL) {
            cout<<bantu->data<<' ';
            bantu = bantu->next;
        }
        cout<<endl;
    } else cout<<"Tidak terdapat data pada Linked List";
}


void hapusDepanH() {
    if (isEmptyH() == 0) {
        TNode *hapus = head;
        string data  = hapus->data;
        if (head->next != NULL) {
            head       = head->next;
            head->prev = NULL;
        } else {
            initH();
        }
        delete hapus;
        cout<<"Data \""<<data<<"\" yang berada di depan telah berhasil dihapus.";
    } else cout<<"Tidak terdapat data pada Linked List";
}

void hapusDepanHT() {
    if (isEmptyHT() == 0) {
        TNode *hapus = head;
        string data  = hapus->data;
        if (head->next != NULL) {
            head       = head->next;
            head->prev = NULL;
        } else {
            initHT();
        }
        delete hapus;
        cout<<"Data \""<<data<<"\" yang berada di depan telah berhasil dihapus.";
    } else cout<<"Tidak terdapat data pada Linked List";
}


void hapusBelakangH() {
    if (isEmptyH() == 0) {
        int total = 0;
        TNode *bantu = head;
        while (bantu != NULL) {
            total++;
            bantu = bantu->next;
        }

        int N;
        cout<<"Masukkan posisi ke-N dari belakang yang ingin dihapus : ";
        cin>>N;

        N = ((N - 1) % total) + 1;

        int posisiDariDepan = total - N + 1;

        TNode *hapus = head;
        for (int i = 1; i < posisiDariDepan; i++) {
            hapus = hapus->next;
        }

        string data = hapus->data;

        if (hapus->prev != NULL)
            hapus->prev->next = hapus->next;
        else
            head = hapus->next;

        if (hapus->next != NULL)
            hapus->next->prev = hapus->prev;

        delete hapus;
        cout<<"Data \""<<data<<"\" (posisi ke-"<<N<<" dari belakang) telah berhasil dihapus.";
    } else cout<<"Tidak terdapat data pada Linked List";
}

void hapusBelakangHT() {
    if (isEmptyHT() == 0) {
        int total = 0;
        TNode *bantu = head;
        while (bantu != NULL) {
            total++;
            bantu = bantu->next;
        }

        int N;
        cout<<"Masukkan posisi ke-N dari belakang yang ingin dihapus : ";
        cin>>N;

        N = ((N - 1) % total) + 1;

        TNode *hapus = tail;
        for (int i = 1; i < N; i++) {
            hapus = hapus->prev;
        }

        string data = hapus->data;

        if (hapus->prev != NULL)
            hapus->prev->next = hapus->next;
        else
            head = hapus->next;

        if (hapus->next != NULL)
            hapus->next->prev = hapus->prev;
        else
            tail = hapus->prev;

        delete hapus;
        cout<<"Data \""<<data<<"\" (posisi ke-"<<N<<" dari belakang) telah berhasil dihapus.";
    } else cout<<"Tidak terdapat data pada Linked List";
}


void hapusTargetH() {
    if (isEmptyH() == 0) {
        string target;
        cout<<"Masukkan data yang ingin dihapus : ";
        cin>>target;

        TNode *bantu = head;
        int hitungHapus = 0;

        while (bantu != NULL) {
            TNode *berikutnya = bantu->next;

            if (bantu->data == target) {
                if (bantu->prev != NULL)
                    bantu->prev->next = bantu->next;
                else
                    head = bantu->next;

                if (bantu->next != NULL)
                    bantu->next->prev = bantu->prev;

                delete bantu;
                hitungHapus++;
            }

            bantu = berikutnya;
        }

        if (hitungHapus > 0)
            cout<<"Sebanyak "<<hitungHapus<<" node dengan data \""<<target<<"\" telah berhasil dihapus.";
        else
            cout<<"Data \""<<target<<"\" tidak ditemukan pada Linked List.";
    } else cout<<"Tidak terdapat data pada Linked List";
}

void hapusTargetHT() {
    if (isEmptyHT() == 0) {
        string target;
        cout<<"Masukkan data yang ingin dihapus : ";
        cin>>target;

        TNode *bantu = head;
        int hitungHapus = 0;

        while (bantu != NULL) {
            TNode *berikutnya = bantu->next;

            if (bantu->data == target) {
                if (bantu->prev != NULL)
                    bantu->prev->next = bantu->next;
                else
                    head = bantu->next;

                if (bantu->next != NULL)
                    bantu->next->prev = bantu->prev;
                else
                    tail = bantu->prev;

                delete bantu;
                hitungHapus++;
            }

            bantu = berikutnya;
        }

        if (hitungHapus > 0)
            cout<<"Sebanyak "<<hitungHapus<<" node dengan data \""<<target<<"\" telah berhasil dihapus.";
        else
            cout<<"Data \""<<target<<"\" tidak ditemukan pada Linked List.";
    } else cout<<"Tidak terdapat data pada Linked List";
}


void clearH() {
    if (isEmptyH() == 0) {
        int urutan = 1;

        while (head != NULL) {
            TNode *hapusDep = head;
            cout<<"Penghapusan ke-"<<urutan<<" : \""<<hapusDep->data<<"\" (dari depan)"<<endl;
            urutan++;

            if (head->next != NULL) {
                head       = head->next;
                head->prev = NULL;
            } else {
                delete hapusDep;
                initH();
                break;
            }
            delete hapusDep;

            if (head == NULL) break;

            TNode *hapusBel = head;
            while (hapusBel->next != NULL)
                hapusBel = hapusBel->next;

            cout<<"Penghapusan ke-"<<urutan<<" : \""<<hapusBel->data<<"\" (dari belakang)"<<endl;
            urutan++;

            if (hapusBel->prev != NULL) {
                hapusBel->prev->next = NULL;
            } else {
                delete hapusBel;
                initH();
                break;
            }
            delete hapusBel;
        }

        cout<<"Seluruh data pada Linked List telah dibersihkan.";
    } else cout<<"Tidak terdapat data pada Linked List";
}

void clearHT() {
    if (isEmptyHT() == 0) {
        int urutan = 1;

        while (head != NULL) {
            TNode *hapusDep = head;
            cout<<"Penghapusan ke-"<<urutan<<" : \""<<hapusDep->data<<"\" (dari depan)"<<endl;
            urutan++;

            if (head != tail) {
                head       = head->next;
                head->prev = NULL;
            } else {
                delete hapusDep;
                initHT();
                break;
            }
            delete hapusDep;

            if (head == NULL) break;

            TNode *hapusBel = tail;
            cout<<"Penghapusan ke-"<<urutan<<" : \""<<hapusBel->data<<"\" (dari belakang)"<<endl;
            urutan++;

            if (head != tail) {
                tail       = tail->prev;
                tail->next = NULL;
            } else {
                delete hapusBel;
                initHT();
                break;
            }
            delete hapusBel;
        }

        cout<<"Seluruh data pada Linked List telah dibersihkan.";
    } else cout<<"Tidak terdapat data pada Linked List";
}