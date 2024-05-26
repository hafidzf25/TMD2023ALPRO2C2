/* Saya Abdullah Hafidz Furqon mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah Algoritma dan Pemrograman II untuk
keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include <string.h> // library
#include <stdio.h> // library
#include <stdlib.h> // library

typedef struct // deklarasi struct untuk menyimpan table biasa (seperti Pelanggan dan Menu)
{
    char id[256], col1[256], col2[256], angka[256];
    // berisikan id, lalu kolom pertama pada table, lalu kolom kedua, dan kolom terakhir yang berbentuk angka
}tableBiasa;

typedef struct // deklarasi struct untuk menyimpan table join 
{
    char id[256], col1[256], kodejoin[256], angka[256], tipe_menu[256], nama_menu[256], harga_menu[256];
    // berisikan id pelanggan, lalu nama, menu yang dipesan, notelp pelanggan, lalu tipe menu, nama menu, dan harga menu
}tableJoin;

// Deklarasi variabel global

// variabel mesin kata
extern int idx;     // index dari karakter terakhir pada kata
extern int wlen;    // panjang kata (word length)
extern char cw[256]; // kata saat ini (current word)

// variabel untuk db
extern char table[256]; // untuk menyimpan nama table yang sedang di eksekusi
extern int kode; // digunakan untuk mencatat kode yang sedang dicari
extern int query1; // digunakan untuk mencatat indikator query pertama
extern int query2;  // digunakan untuk mencatat indikator query kedua
extern int dataMenu; // digunakan untuk mencatat banyaknya record pada table Menu
extern int dataPelanggan; // digunakan untuk mencatat banyaknya record pada table Pelanggan
extern int dataJoin; // digunakan untuk mencatat banyaknya record pada table yang di join

// array of struct untuk table pelanggan, menu, dan join
extern tableBiasa Pelanggan[200]; // array of struct untuk menyimpan record table Pelanggan
extern tableBiasa Menu[200]; // array of struct untuk menyimpan record table Menu
extern tableJoin JoinKuy[200]; // array of struct untuk menyimpan record table yang di join

// Fungsi untuk mencari primary key dalam table (bisa menu, bisa pelanggan)
int BinarySearch(int n, char target[], tableBiasa data[]);

// Fungsi untuk mencari primary key khusus dalam table pelanggan
int BinarySearch2(int n, char target[], tableBiasa data[]);

// Prosedur untuk membuat table biasa (seperti menu, dan pelanggan)
void BikinTable(char kolom1[], char kolom2[], char kolom3[], char kolom4[], tableBiasa sumber[], int banyakData);

// Prosedur untuk membuat table yang join
void BikinTableJoin(char kolom1[], char kolom2[], char kolom3[], char kolom4[], char kolom5[], char kolom6[], char kolom7[], tableJoin sumber[], int banyakData);

// Prosedur untuk menjoin kedua table
void joinData();

// Prosedur untuk menyorting data dalam table
void sortData(int n, tableBiasa target[]);

// Prosedur untuk membaca record dalam file yang dimasukkan ke dalam array of struct
void readFile(char filename[], tableBiasa sumber[]);

// Prosedur untuk menuliskan record yang ada di array of struct ke dalam file
void writeFile(int n, tableBiasa sumber[], char source[]);

// Prosedur untuk memulai mesin kata
void start(char str[]);

// Fungsi untuk memeriksa akhir dari proses
int eop(char str[]);

// Prosedur untuk memajukan kata
void inc(char str[]);

// Fungsi untuk mencari simbol eop
int search_null(char str[]);

// Fungsi untuk mendapatkan kata saat ini
char *getcw();

// Prosedur untuk pergi ke EOP
void gotoEOP(char str[]);

// Prosedur untuk print judul hehe
void judul();

// Prosedur untuk menampilkan pesan error
void displayError(char codeError[], char pesan[]);

// Prosedur untuk menampilkan list table
void ListData(char pita[]);

// Prosedur yang merupakan suatu proses dari perintah ISI
void insertData(char pita[], int banyakData, tableBiasa data[]);

// Prosedur yang merupakan suatu proses dari perintah HAPUS
void deleteData(char pita[], int banyakData, tableBiasa data[]);

// Prosedur yang merupakan suatu proses dari perintah UBAH
void updateData(char pita[], tableBiasa data[]);

// Prosedur untuk melakukan insert data ke dalam table
void IsiQuery(char pita[]);

// Prosedur untuk melakukan update data di dalam table
void UbahQuery(char pita[]);

// Prosedur untuk melakukan hapus data yang ada di dalam table
void HapusQuery(char pita[]);

// Prosedur untuk menampilkan data dalam table
void TampilQuery(char pita[]);

// Prosedur utama yang akan membacakan Query awal dalam pita
void readQuery(char pita[]);