/* Saya Abdullah Hafidz Furqon mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah Algoritma dan Pemrograman II untuk
keberkahanNya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include "header.h"

// Deklarasi variabel global
int idx;     // index dari karakter terakhir pada kata
int wlen;    // panjang kata (word length)
char cw[256]; // kata saat ini (current word)
char table[256]; // untuk menyimpan nama table yang sedang di eksekusi

int kode = 0; // digunakan untuk mencatat kode yang sedang dicari
int query1 = 0; // digunakan untuk mencatat indikator query pertama
int query2 = 0; // digunakan untuk mencatat indikator query kedua
int dataMenu = 0; // digunakan untuk mencatat banyaknya record pada table Menu
int dataPelanggan = 0; // digunakan untuk mencatat banyaknya record pada table Pelanggan
int dataJoin = 0; // digunakan untuk mencatat banyaknya record pada table yang di join

tableBiasa Pelanggan[200]; // array of struct untuk menyimpan record table Pelanggan
tableBiasa Menu[200]; // array of struct untuk menyimpan record table Menu
tableJoin JoinKuy[200]; // array of struct untuk menyimpan record table yang di join

// Prosedur untuk mencari kode dalam table
int BinarySearch(int n, char target[], tableBiasa data[])
{
    int i = 0, j = n - 1, k; // penanda rentang data, dan data yang dicari
    int found = 0; // deklarasi int, digunakan sebagai penentu dalam proses binary search nanti

    while (found == 0 && i <= j) // perulangan dengan syarat found sama dengan 0 DAN i kurang dari sam dengan j
    {
        k = (i + j) / 2; // mengambil index tengah dari rentang data indeks i ke j
        
        if (strcmp(data[k].id, target) == 0) // apabila nim sama dengan target yang dicari
        {
            found = 1; // maka menandakan bahwa data sudah ditemukan
            kode = k;
        }
        else // apabila berbeda
        {
            if (strcmp(data[k].id, target) > 0) // apabila nim mahasiswa lebih besar dari yang dicari
            {
                j = k - 1; // memindahkan rentang data kanan (j) ke sebelah kirinya posisi tengah 
            }
            else // apabila lebih kecil
            {
                i = k + 1; // memindahkan rentang data kiri (i) ke sebelah kanan nya posisi tengah
            }
        }
    }
    
    return found; // mengembalikan nilai found
}

// Prosedur kedua untuk mencari kode dalam table
int BinarySearch2(int n, char target[], tableBiasa data[])
{
    int i = 0, j = n - 1, k; // penanda rentang data, dan data yang dicari
    int found = 0; // deklarasi int, digunakan sebagai penentu dalam proses binary search nanti

    while (found == 0 && i <= j) // perulangan dengan syarat found sama dengan 0 DAN i kurang dari sam dengan j
    {
        k = (i + j) / 2; // mengambil index tengah dari rentang data indeks i ke j
        
        if (strcmp(data[k].col2, target) == 0) // apabila nim sama dengan target yang dicari
        {
            found = 1; // maka menandakan bahwa data sudah ditemukan
            kode = k;
        }
        else // apabila berbeda
        {
            if (strcmp(data[k].col2, target) > 0) // apabila nim mahasiswa lebih besar dari yang dicari
            {
                j = k - 1; // memindahkan rentang data kanan (j) ke sebelah kirinya posisi tengah 
            }
            else // apabila lebih kecil
            {
                i = k + 1; // memindahkan rentang data kiri (i) ke sebelah kanan nya posisi tengah
            }
        }
    }
    
    return found; // mengembalikan nilai found
}

void BikinTable(char kolom1[], char kolom2[], char kolom3[], char kolom4[], tableBiasa sumber[], int banyakData)
{ 
    int kolomid = strlen(kolom1); // Mencatat lebar kolom 1
    int kolomcol1 = strlen(kolom2); // Mencatat lebar kolom ke 2
    int kolomcol2 = strlen(kolom3); // Mencatat lebar kolom ke 3
    int kolomangka = strlen(kolom4); // Mencatat lebar kolom ke 4

    // Perulangan untuk mencari lebar maksimal tiap kolom suatu table
    for (int i = 0; i < banyakData; i++) 
    {
        if (strlen(sumber[i].id) > kolomid) // Max kolom 1
        {
            kolomid = strlen(sumber[i].id); // memgubahnya apabila ada yang lebih panjang
        }
        if (strlen(sumber[i].col1) > kolomcol1) // Max kolom 2
        {
            kolomcol1 = strlen(sumber[i].col1); // memgubahnya apabila ada yang lebih panjang
        }
        if (strlen(sumber[i].col2) > kolomcol2) // Max kolom 3
        {
            kolomcol2 = strlen(sumber[i].col2); // memgubahnya apabila ada yang lebih panjang
        }
        if (strlen(sumber[i].angka) > kolomangka) // Max kolom 4
        {
            kolomangka = strlen(sumber[i].angka); // memgubahnya apabila ada yang lebih panjang
        }
    }
    
    // PRINT TABLE HEADER

    printf("+");
    for (int i = -1; i < kolomid + 1; i++)
    {
        printf("-");
    }
    printf("+");
    for (int i = -1; i < kolomcol1 + 1; i++)
    {
        printf("-");
    }
    printf("+");
    for (int i = -1; i < kolomcol2 + 1; i++)
    {
        printf("-");
    }
    printf("+");
    for (int i = -1; i < kolomangka + 1; i++)
    {
        printf("-");
    }
    printf("+\n");

    printf("| %s", kolom1);
    for (int i = strlen(kolom1); i < kolomid; i++)
    {
        printf(" ");
    }
    printf(" | %s", kolom2);
    for (int i = strlen(kolom2); i < kolomcol1; i++)
    {
        printf(" ");
    }
    printf(" | %s", kolom3);
    for (int i = strlen(kolom3); i < kolomcol2; i++)
    {
        printf(" ");
    }
    printf(" | %s", kolom4);
    for (int i = strlen(kolom4); i < kolomangka; i++)
    {
        printf(" ");
    }
    printf(" |\n");

    printf("+");
    for (int i = -1; i < kolomid + 1; i++)
    {
        printf("-");
    }
    printf("+");
    for (int i = -1; i < kolomcol1 + 1; i++)
    {
        printf("-");
    }
    printf("+");
    for (int i = -1; i < kolomcol2 + 1; i++)
    {
        printf("-");
    }
    printf("+");
    for (int i = -1; i < kolomangka + 1; i++)
    {
        printf("-");
    }
    printf("+\n");

    // PRINT ISI TABLE

    for (int i = 0; i < banyakData; i++) // Perulangan sebanyak record dalam suatu table
    {
        printf("| %s", sumber[i].id); // Print ID
        for (int j = strlen(sumber[i].id); j < kolomid; j++)
        {
            printf(" ");
        }
        printf(" | %s", sumber[i].col1); // Print data Kolom 1
        for (int j = strlen(sumber[i].col1); j < kolomcol1; j++)
        {
            printf(" ");
        }
        printf(" | %s", sumber[i].col2); // Print data Kolom 2
        for (int j = strlen(sumber[i].col2); j < kolomcol2; j++)
        {
            printf(" ");
        }
        printf(" | %s", sumber[i].angka); // Print data kolom 3 berupa angka
        for (int j = strlen(sumber[i].angka); j < kolomangka; j++)
        {
            printf(" ");
        }
        printf(" |\n");
    }
    
    // Print Penutup Table
    printf("+");
    for (int i = -1; i < kolomid + 1; i++)
    {
        printf("-");
    }
    printf("+");
    for (int i = -1; i < kolomcol1 + 1; i++)
    {
        printf("-");
    }
    printf("+");
    for (int i = -1; i < kolomcol2 + 1; i++)
    {
        printf("-");
    }
    printf("+");
    for (int i = -1; i < kolomangka + 1; i++)
    {
        printf("-");
    }
    printf("+\n");
}

void BikinTableJoin(char kolom1[], char kolom2[], char kolom3[], char kolom4[], char kolom5[], char kolom6[], char kolom7[], tableJoin sumber[], int banyakData)
{ 
    int kolomid = strlen(kolom1); // Mencatat lebar kolom ke 1
    int kolomcol1 = strlen(kolom2); // Mencatat lebar kolom ke 2
    int kolomcol2 = strlen(kolom3); // Mencatat lebar kolom ke 3
    int kolomangka = strlen(kolom4); // Mencatat lebar kolom ke 4
    int kolomtipe = strlen(kolom5); // Mencatat lebar kolom ke 5
    int kolomnama = strlen(kolom6); // Mencatat lebar kolom ke 6
    int kolomharga = strlen(kolom7); // Mencatat lebar kolom ke 7

    // Perulangan untuk mencari lebar maksimal di dalam table join

    for (int i = 0; i < banyakData; i++)
    {
        if (strlen(sumber[i].id) > kolomid)
        {
            kolomid = strlen(sumber[i].id);
        }
        if (strlen(sumber[i].col1) > kolomcol1)
        {
            kolomcol1 = strlen(sumber[i].col1);
        }
        if (strlen(sumber[i].kodejoin) > kolomcol2)
        {
            kolomcol2 = strlen(sumber[i].kodejoin);
        }
        if (strlen(sumber[i].angka) > kolomangka)
        {
            kolomangka = strlen(sumber[i].angka);
        }
        if (strlen(sumber[i].tipe_menu) > kolomtipe)
        {
            kolomtipe = strlen(sumber[i].tipe_menu);
        }
        if (strlen(sumber[i].nama_menu) > kolomnama)
        {
            kolomnama = strlen(sumber[i].nama_menu);
        }
        if (strlen(sumber[i].harga_menu) > kolomharga)
        {
            kolomharga = strlen(sumber[i].harga_menu);
        }
    }
    
    // Print Table Header
    printf("+");
    for (int i = -1; i < kolomid + 1; i++)
    {
        printf("-");
    }
    printf("+");
    for (int i = -1; i < kolomcol1 + 1; i++)
    {
        printf("-");
    }
    printf("+");
    for (int i = -1; i < kolomcol2 + 1; i++)
    {
        printf("-");
    }
    printf("+");
    for (int i = -1; i < kolomangka + 1; i++)
    {
        printf("-");
    }
    printf("+");
    for (int i = -1; i < kolomtipe + 1; i++)
    {
        printf("-");
    }
    printf("+");
    for (int i = -1; i < kolomnama + 1; i++)
    {
        printf("-");
    }
    printf("+");
    for (int i = -1; i < kolomharga + 1; i++)
    {
        printf("-");
    }
    printf("+\n");

    printf("| %s", kolom1);
    for (int i = strlen(kolom1); i < kolomid; i++)
    {
        printf(" ");
    }
    printf(" | %s", kolom2);
    for (int i = strlen(kolom2); i < kolomcol1; i++)
    {
        printf(" ");
    }
    printf(" | %s", kolom3);
    for (int i = strlen(kolom3); i < kolomcol2; i++)
    {
        printf(" ");
    }
    printf(" | %s", kolom4);
    for (int i = strlen(kolom4); i < kolomangka; i++)
    {
        printf(" ");
    }
    printf(" | %s", kolom5);
    for (int i = strlen(kolom5); i < kolomtipe; i++)
    {
        printf(" ");
    }
    printf(" | %s", kolom6);
    for (int i = strlen(kolom6); i < kolomnama; i++)
    {
        printf(" ");
    }
    printf(" | %s", kolom7);
    for (int i = strlen(kolom7); i < kolomharga; i++)
    {
        printf(" ");
    }
    printf(" |\n");

    printf("+");
    for (int i = -1; i < kolomid + 1; i++)
    {
        printf("-");
    }
    printf("+");
    for (int i = -1; i < kolomcol1 + 1; i++)
    {
        printf("-");
    }
    printf("+");
    for (int i = -1; i < kolomcol2 + 1; i++)
    {
        printf("-");
    }
    printf("+");
    for (int i = -1; i < kolomangka + 1; i++)
    {
        printf("-");
    }
    printf("+");
    for (int i = -1; i < kolomtipe + 1; i++)
    {
        printf("-");
    }
    printf("+");
    for (int i = -1; i < kolomnama + 1; i++)
    {
        printf("-");
    }
    printf("+");
    for (int i = -1; i < kolomharga + 1; i++)
    {
        printf("-");
    }
    printf("+\n");

    // Print Isi Table Join

    for (int i = 0; i < banyakData; i++) // Perulangan sebanyak data dalam table join
    {
        printf("| %s", sumber[i].id);
        for (int j = strlen(sumber[i].id); j < kolomid; j++)
        {
            printf(" ");
        }
        printf(" | %s", sumber[i].col1);
        for (int j = strlen(sumber[i].col1); j < kolomcol1; j++)
        {
            printf(" ");
        }
        printf(" | %s", sumber[i].kodejoin);
        for (int j = strlen(sumber[i].kodejoin); j < kolomcol2; j++)
        {
            printf(" ");
        }
        printf(" | %s", sumber[i].angka);
        for (int j = strlen(sumber[i].angka); j < kolomangka; j++)
        {
            printf(" ");
        }
        printf(" | %s", sumber[i].tipe_menu);
        for (int j = strlen(sumber[i].tipe_menu); j < kolomtipe; j++)
        {
            printf(" ");
        }
        printf(" | %s", sumber[i].nama_menu);
        for (int j = strlen(sumber[i].nama_menu); j < kolomnama; j++)
        {
            printf(" ");
        }
        printf(" | %s", sumber[i].harga_menu);
        for (int j = strlen(sumber[i].harga_menu); j < kolomharga; j++)
        {
            printf(" ");
        }
        printf(" |\n");
    }

    // Print penutup table
    
    printf("+");
    for (int i = -1; i < kolomid + 1; i++)
    {
        printf("-");
    }
    printf("+");
    for (int i = -1; i < kolomcol1 + 1; i++)
    {
        printf("-");
    }
    printf("+");
    for (int i = -1; i < kolomcol2 + 1; i++)
    {
        printf("-");
    }
    printf("+");
    for (int i = -1; i < kolomangka + 1; i++)
    {
        printf("-");
    }
    printf("+");
    for (int i = -1; i < kolomtipe + 1; i++)
    {
        printf("-");
    }
    printf("+");
    for (int i = -1; i < kolomnama + 1; i++)
    {
        printf("-");
    }
    printf("+");
    for (int i = -1; i < kolomharga + 1; i++)
    {
        printf("-");
    }
    printf("+\n");
}

void joinData()
{
    dataJoin = 0; // Set nilai menjadi 0
    for (int i = 0; i < dataPelanggan; i++) // Perulangan sebanyak record dalam table Pelanggan
    {
        strcpy(JoinKuy[i].id, Pelanggan[i].id); // Mengcopy id pelanggan ke table join
        strcpy(JoinKuy[i].col1, Pelanggan[i].col1); // Mengcopy nama pelanggan ke table join
        strcpy(JoinKuy[i].kodejoin, Pelanggan[i].col2); // Mengcopy kode menu yang dipesan ke table join
        strcpy(JoinKuy[i].angka, Pelanggan[i].angka); // Mengcopy notelp pelanggan ke table join
        int ind = BinarySearch(dataMenu, JoinKuy[i].kodejoin, Menu); // Memanggil fungsi untuk mencari apakah Kode menu terdapat dalam table Menu
        if (ind == 1) // Apabila ada maka copy data nya
        {
            strcpy(JoinKuy[i].tipe_menu, Menu[kode].col1); // Copy tipe menu ke dalam table join
            strcpy(JoinKuy[i].nama_menu, Menu[kode].col2); // Copy nama menu ke dalam table join
            strcpy(JoinKuy[i].harga_menu, Menu[kode].angka); // Copy harga menu ke dalam table join
            dataJoin++; // iterasi untuk menandakan bertambahnya data dalam table join
        }
        else // Apabila tidak ada
        {
            strcpy(JoinKuy[i].tipe_menu, "NULL"); // maka set NULL
            strcpy(JoinKuy[i].nama_menu, "NULL"); // maka set NULL
            strcpy(JoinKuy[i].harga_menu, "NULL"); // maka set NULL
            dataJoin++; // iterasi untuk menandakan bertambahnya data dalam table join
        }
    }
}

void sortData(int n, tableBiasa target[])
{
    int ind; // Variabel untuk syarat dalam proses sorting nanti

    do // perulangan
    {
        ind = 0; // set menjadi 0

        for (int i = 0; i < n - 1; i++) // perulangan sebanyak nilai dalam table yang dibawa dikurangi 1
        {
            if (strcmp(target[i].id, target[i + 1].id) > 0) // apabila id nya lebih besar dari id i + 1
            {
                // Maka melakukan proses penukaran kedua indeks

                char temp[256];
                strcpy(temp, target[i].id);
                strcpy(target[i].id, target[i + 1].id); // Proses penukaran id
                strcpy(target[i + 1].id, temp);

                strcpy(temp, target[i].col1);
                strcpy(target[i].col1, target[i + 1].col1); // Proses penukaran data kolom 1
                strcpy(target[i + 1].col1, temp);

                strcpy(temp, target[i].col2);
                strcpy(target[i].col2, target[i + 1].col2); // Proses penukaran data kolom 2
                strcpy(target[i + 1].col2, temp);

                strcpy(temp, target[i].angka);
                strcpy(target[i].angka, target[i + 1].angka); // Proses penukaran data kolom 3 yang berupa angka
                strcpy(target[i + 1].angka, temp);

                ind = 1; // menandakan bahwa ada proses penukaran
            }
        }
    } while (ind == 1); // dengan syarat ind harus sama dengan 1
}

void readFile(char filename[], tableBiasa sumber[])
{
    int n = 0; // counter untuk jumlah data, khususnya data menu / pelanggan

    FILE *fData; // pointer untuk file yang akan dibuka
    fData = fopen(filename, "r"); // buka file dengan mode read
    
    int returnVal = fscanf(fData, "%s %s %s %s", // scan 4 data pertama (baris 1)
                    sumber[n].id, sumber[n].col1, sumber[n].col2, sumber[n].angka);

    // cek kolom id yang baru discan tadi apakah sama dengan EOF?
    if (strcmp(sumber[n].id, "####") == 0 || returnVal == EOF) 
    {
        // jika ya maka data yang tadi discan merupakan EOF
        printf("File Kosong\n");
    }
    else
    {
        // kalau tidak, berarti bukan EOF
        // ketika kolom nama bukan EOF lakukan:
        while (strcmp(sumber[n].id, "####") != 0)
        {
            n++; // maju ke penampung data berikutnya
            fscanf(fData, "%s %s %s %s", // scan 4 data berikutnya (baris 2 dan seterusnya)
            sumber[n].id, sumber[n].col1, sumber[n].col2, sumber[n].angka);
        }
    }

    // melakukan pencocokkan, apakah data yang dibawa adalah table Menu
    if (strcmp(filename, "data/tMenu.dat") == 0)
    {
        // jika iya, maka catat banyaknya data ke dalam variabel dataMenu
        dataMenu = n;
    }
    // jika yang dibawa adalah table pelanggan
    else if (strcmp(filename, "data/tPelanggan.dat") == 0)
    {
        //maka catat banyaknya data ke dalam variabel dataPelanggan
        dataPelanggan = n;
    }
    // "tutup file"
    fclose(fData);
}

void writeFile(int n, tableBiasa sumber[], char source[])
{
    FILE *fTemp; // pointer ke file
    fTemp = fopen(source, "w"); // buka file dengan mode write
   
    // tulis data ke file
    for (int i = 0; i < n; i++)
    {
        fprintf(fTemp, "%s %s %s %s\n", // tulis 4 kolom lalu beri newline
                sumber[i].id, sumber[i].col1, sumber[i].col2, sumber[i].angka);
    }

    // berikan EOF di akhir file
    fprintf(fTemp, "%s %s %s %s\n", "####", "####", "####", "####");

    // "tutup file"
    fclose(fTemp);
}

// Prosedur untuk memulai mesin kata
void start(char str[])
{
    // inisialisasi index dan panjang kata
    idx = 0;
    wlen = 0;

    // jika karakter dalam index adalah spasi, maka index terus maju
    while (str[idx] == ' ')
    {
        idx++;
    }

    // jika masukan berupa karakter selain spasi dan EOP, kata diatur ke variabel global
    while ((str[idx] != ' ') && (eop(str) == 0))
    {
        cw[wlen] = str[idx];
        wlen++;
        idx++;
    }

    while (str[idx] == ' ')
    {
        idx++;
    }

    // mengatur agar kata saat ini index terakhirnya menjadi NULL
    cw[wlen] = '\0';
}

// Prosedur untuk mengosongkan kata yang dibaca dalam mesin kata
void reset()
{
    // inisialisasi panjang kata dan kata saat ini agar NULL
    wlen = 0;
    cw[wlen] = '\0';
}

// Fungsi untuk memeriksa akhir dari proses
int eop(char str[])
{
    while (str[idx] == ' ') // apabila masih spasi maka mencari karakter selanjutnya
    {
        idx++;
    }
    
    // Memeriksa apakah karakter saat ini merupakan simbol akhir pita
    if (str[idx] == ';')
    {
        return 1; // jika iya maka eof
    }
    else
    {
        return 0; // jika tidak kembalikan false
    }
}

// Prosedur untuk memajukan kata
void inc(char str[])
{
    // inisialisasi ulang panjang kata
    wlen = 0;

    // jika karakter dalam pita adalah spasi, maka index terus maju
    while (str[idx] == ' ')
    {
        idx++;
    }

    // jika masukan berupa karakter selain spasi dan EOP, kata diatur ke variabel global
    while ((str[idx] != ' ') && (eop(str) == 0))
    {
        cw[wlen] = str[idx];
        wlen++;
        idx++;
    }

    // mengatur agar kata saat ini index terakhirnya menjadi NULL
    cw[wlen] = '\0';
}

// Fungsi untuk mencari EOP
int search_null(char str[])
{
    int EOPE = 0; // indikator untuk menentukan apakah ada EOF atau tidak
    idx = 0; // untuk memulai dari index awal

    // jika masukan berupa karakter selain NULL, maka lanjut looping
    while (str[idx] != '\0')
    {
        if (str[idx] == ';') // apabila ditemukan EOF, maka mengembalikan nilai bahwa ada simbol EOF dalam pita
        {
            EOPE = 1; // menandakan bahwa ada simbol EOF
        }
        idx++; // iterasi idx
    }

    return EOPE; // mengembalikan nilai
}

// Fungsi untuk mendapatkan panjang kata saat ini
int getlen()
{
    return wlen;
}

// Fungsi untuk mendapatkan kata saat ini
char *getcw()
{
    return cw;
}

void gotoEOP(char str[])
{
    while (str[idx] != ';')
    {
        idx++;
    }
}

void judul()
{
    printf("+===========================================+\n");
    printf("| Selamat Datang di DBMS Dapur Dayu Cookies |\n"); // Print judul DBMS
    printf("|                Versi 2023.0               |\n");
    printf("+===========================================+\n\n");
}

void displayError(char codeError[], char pesan[])
{
    printf("\nERROR 6666 (%s): %s.\n\n", codeError, pesan); // Print display Error
}

void ListData(char pita[])
{
    if (eop(pita) == 1) // apabila sudah sampai diujung pita
    {
        if (strcmp(table, "pelanggan") == 0) // mencocokkan, apabila yang dibawa adalah table pelanggan, maka print table pelanggan
        {
            BikinTable("Kode Pelanggan", "Nama Pelanggan", "Kode Menu", "Notelp Pelanggan", Pelanggan, dataPelanggan); // print table
            printf("Table %s berhasil di tampilkan.\n\n", table); // print keberhasilan
        }
        else if (strcmp(table, "menu") == 0) // mencocokkan, apabila yang dibawa adalah table menu, maka print table menu
        {
            BikinTable("Kode Menu", "Tipe Menu", "Nama Menu", "Harga Menu", Menu, dataMenu); // print table
            printf("Table %s berhasil di tampilkan.\n\n", table); // print keberhasilan
        }
    }
    else // apabila belum sampai diujung
    {   
        inc(pita); // maka cek kata selanjutnya

        // apabila query nya pelanggan menu ATAU menu pelanggan, maka print join table
        if ((strcmp(getcw(), "pelanggan") == 0 && strcmp(table, "pelanggan") != 0) || (strcmp(getcw(), "menu") == 0 && strcmp(table, "menu") != 0))
        {
            // apabila EOF, maka print join table
            if (eop(pita) == 1)
            {
                joinData(); // melakukan proses join table

                // Melakukan proses untuk menampilkan table join
                BikinTableJoin("Kode Pelanggan", "Nama Pelanggan", "Kode Menu", "Notelp Pelanggan", "Tipe Menu", "Nama Menu", "Harga Menu", JoinKuy, dataJoin);
                printf("Table Join %s %s berhasil di tampilkan.\n\n", table, getcw()); // print keberhasilan 
            }
            else
            {
                displayError("3Q000", "Query yang diberikan melebihi spesifikasi"); // print error, dikarenakan ada query berlebih   
            }
        }
        else
        {
            displayError("1Q000", "Query yang diberikan tidak valid"); // print error, dikarenakan table yang dituju salah
        }
    }
}

void insertData(char pita[], int banyakData, tableBiasa data[])
{
    char kodeBaru[256], kolom1[256], kolom2[256], angka[256]; // temp untuk mencatat id kode, data kolom 1, kolom 2, dan kolom 3 berupa angka
    strcpy(kodeBaru, getcw()); // mengcopy kata sekarang ke dalam string kodeBaru
    inc(pita); // maju ke kata berikutnya

    if (eop(pita) == 0) // apabila bukan EOP
    {
        // maka lanjut, dan copy string sekarang (data kolom 1) ke dalam string kolom1
        strcpy(kolom1, getcw());
        inc(pita); // maju ke kata berikutnya

        if (eop(pita) == 0)// apabila bukan EOP
        {
            if (strcmp(table, "pelanggan") == 0) // apabila table yang dituju adalah table pelanggan
            {
                int ind = BinarySearch(dataMenu, getcw(), Menu); // mengecek apakah kode menu yang dimasukkan ada dalam table menu

                if (ind == 1) // apabila ada
                {
                    // maka lanjut, copy cw (data kolom 2) ke dalam string kolom2
                    strcpy(kolom2, getcw());
                    inc(pita); // maju ke kata berikutnya

                    if (eop(pita) == 1) // apabila bukan EOP
                    {
                        strcpy(angka, getcw()); // copy cw (angka) ke dalam string angka
                        
                        strcpy(Pelanggan[dataPelanggan].id, kodeBaru);
                        strcpy(Pelanggan[dataPelanggan].col1, kolom1); // Melakukan copy 4 variabel temp tadi ke dalam
                        strcpy(Pelanggan[dataPelanggan].col2, kolom2); // Struct table pelanggan
                        strcpy(Pelanggan[dataPelanggan].angka, angka);

                        dataPelanggan++; // Iterasi untuk menandakan bahwa terdapat penambahan data Pelanggan

                        printf("\nBerhasil menambahkan record dengan kode %s ke dalam table %s.\n\n", kodeBaru, table);
                    }
                    else
                    {
                        displayError("3I000", "Mohon maaf, data yang ingin di input melebihi spesifikasi table");
                        // Print error apabila terdapat query lanjutan di dalam pita
                    }
                }
                else
                {
                    displayError("4I000", "Mohon maaf, kode menu yang di input tidak ada dalam tabel Menu"); 
                    // Print error apabila tidak ada kode menu yang diinput dalam table Menu
                }
            }
            else // apabila table yang dituju adalah table Menu
            {
                strcpy(kolom2, getcw()); // maka lanjut, copy cw (data kolom 2) ke dalam string kolom2
                inc(pita); // maju ke kata berikutnya

                if (eop(pita) == 1) // apabila bukan EOP
                {
                    strcpy(angka, getcw()); // copy cw (angka) ke dalam string angka

                    strcpy(Menu[dataMenu].id, kodeBaru);
                    strcpy(Menu[dataMenu].col1, kolom1); // Melakukan copy 4 variabel temp tadi ke dalam
                    strcpy(Menu[dataMenu].col2, kolom2); // Struct table menu
                    strcpy(Menu[dataMenu].angka, angka);

                    dataMenu++; // Iterasi untuk menandakan bahwa terdapat penambahan data menu

                    printf("\nBerhasil menambahkan record dengan kode %s ke dalam table %s.\n\n", kodeBaru, table);
                }
                else
                {
                    displayError("3I000", "Mohon maaf, data yang ingin di input melebihi spesifikasi table");
                    // Print error apabila query yang dinput dalam pita kelebihan
                }
            }
        }
        else
        {
            displayError("2I000", "Mohon maaf, data yang ingin di input kurang");
            // Print error apabila data yang di input masih kurang dari jumlah kolom tabel
        }
    }
    else
    {
        displayError("1I000", "Mohon maaf, data yang ingin di input kurang"); 
        // Print error apabila data yang di input masih kurang dari jumlah kolom tabel  
    }
}

void deleteData(char pita[], int banyakData, tableBiasa data[])
{
    for (int i = kode; i < banyakData - 1; i++) // Perulangan yang di inisialisasi dari kode yang ingin dihapus
                                                // sampai banyaknya data yang dikurangi 1
    {
        strcpy(data[i].id, data[i + 1].id);
        strcpy(data[i].col1, data[i + 1].col1); // Copy data indeks i + 1 ke dalam i
        strcpy(data[i].col2, data[i + 1].col2); // (alurnya saling menimpa)
        strcpy(data[i].angka, data[i + 1].angka);
    }
    strcpy(data[banyakData - 1].id, "####");
    strcpy(data[banyakData - 1].col1, "####"); // Menaruh null atau EOP
    strcpy(data[banyakData - 1].col2, "####");
    strcpy(data[banyakData - 1].angka, "####");

    printf("\nRecord dengan Kode %s pada table %s telah terhapus\n\n", getcw(), table);
    
    // Apabila table yang dituju adalah table menu
    if (strcmp(table, "menu") == 0)
    {
        dataMenu--; // maka mengurangi jumlah data pada table Menu
    }
    else // Apabila table yang dituju adalah table pelanggan
    {
        dataPelanggan--; // maka mengurangi jumlah data pada table Pelanggan
    }
}

void updateData(char pita[], tableBiasa data[])
{
    int tujuanUpdate = kode;
    char kodeBaru[256], kolom1[256], kolom2[256], angka[256]; // temp untuk mencatat id kode, data kolom 1, kolom 2, dan kolom 3 berupa angka
    strcpy(kodeBaru, getcw());  // mengcopy kata sekarang ke dalam string kodeBaru
    inc(pita); // maju ke kata berikutnya

    if (eop(pita) == 0) // apabila belum berada di ujung pita
    {
        strcpy(kolom1, getcw()); // copy cw ke dalam temp data kolom ke 1
        inc(pita); // maju ke kata berikutnya

        if (eop(pita) == 0) // apabila belum berada di ujung pita
        {
            if (strcmp(table, "pelanggan") == 0) // apabila yang dituju adalah table pelanggan
            {
                int indikatorUpdate = 0; // indikator penentu untuk mencari kode menu

                indikatorUpdate = BinarySearch(dataMenu, getcw(), Menu); // mencari kode menu di dalam table menu

                if (indikatorUpdate == 1) // apabila ada
                {
                    // maka melanjutkan proses
                    strcpy(kolom2, getcw()); // copy cw ke dalam data kolom ke 2
                    inc(pita); // maju ke kata berikutnya

                    if (eop(pita) == 1) // apabila sudah di ujung pita
                    {
                        strcpy(angka, getcw()); // maka copy cw ke dalam string angka

                        strcpy(Pelanggan[tujuanUpdate].id, kodeBaru);
                        strcpy(Pelanggan[tujuanUpdate].col1, kolom1); // proses mengupdate record di dalam table pelanggan
                        strcpy(Pelanggan[tujuanUpdate].col2, kolom2);
                        strcpy(Pelanggan[tujuanUpdate].angka, angka);
                        
                        printf("\nBerhasil mengubah record dengan kode %s di dalam table %s.\n\n", kodeBaru, table);
                    }
                    else
                    {
                        displayError("3U000", "Mohon maaf, data yang ingin di input melebihi spesifikasi table");   
                        // error yang terjadi dikarenakan query yang berlebih
                    }
                }
                else
                {
                    displayError("4I000", "Mohon maaf, kode menu yang di input tidak ada dalam tabel Menu"); 
                    // error yang terjadi dikarenakan kode menu yang diinput tidak ada dalam tabel menu
                }
            }
            else // apabila yang dituju adalah tabel menu
            { 
                // maka melanjutkan proses
                strcpy(kolom2, getcw()); // copy cw ke dalam data kolom ke 2
                inc(pita); // maju ke kata berikutnya

                if (eop(pita) == 1) // apabila sudah di ujung pita
                {
                    strcpy(angka, getcw()); // maka copy cw ke dalam string angka

                    strcpy(Menu[tujuanUpdate].id, kodeBaru);
                    strcpy(Menu[tujuanUpdate].col1, kolom1); // proses mengupdate record di dalam table menu
                    strcpy(Menu[tujuanUpdate].col2, kolom2);
                    strcpy(Menu[tujuanUpdate].angka, angka);

                    printf("\nBerhasil mengubah record dengan kode %s di dalam table %s.\n\n", kodeBaru, table);
                }
                else
                {
                    displayError("3U000", "Mohon maaf, data yang ingin di input melebihi spesifikasi table");   
                    // error yang terjadi apabila query dalam pita yang berlebih
                }
            }
        }
        else
        {
            displayError("2U000", "Mohon maaf, data yang ingin di input kurang");   
            // querya yang terjadi apabila query update yang diinput kurang
        }
    }
    else
    {
        displayError("1U000", "Mohon maaf, data yang ingin di input kurang");
        // querya yang terjadi apabila query update yang diinput kurang
    }
}

void IsiQuery(char pita[])
{
    inc(pita); // maju ke kata berikutnya

    if (strcmp(getcw(), "menu") == 0 || strcmp(getcw(), "pelanggan") == 0) // apabila kata berikutnya adalah menu / pelanggan
    {
        strcpy(table, getcw()); // maka dicopy cw ke dalam string table
        if (eop(pita) == 1) // apabila eop
        {
            displayError("1I000", "Mohon maaf, query untuk mengisi record baru kurang");
            // error yang dikarenakan kurangnya query untuk melakukan input record
        }
        else
        {
            int indikatorIsi = 0; // indikator yang digunakan untuk syarat dalam proses ISI data nanti, apakah kode yang diinput sudah ada dalam table / belum
            inc(pita); // maju ke kata berikutnya

            if (eop(pita) == 0) // apabila belum EOP
            {    
                if (strcmp(table, "menu") == 0) // apabila table yang dituju adalah table menu
                {
                    indikatorIsi = BinarySearch(dataMenu, getcw(), Menu); // mencari kode menu di dalam table menu, apakah sudah ada atau belum

                    if (indikatorIsi == 0) // jika belum ada
                    {
                        insertData(pita, dataMenu, Menu); // maka lakukan ISI data
                    }
                    else
                    {
                        displayError("2I000", "Kode yang dituju sudah ada di dalam database");
                        // error dikarenakan kode sudah ada dalam table menu
                    }
                }
                else // apabila table yang dituju adalah pelanggan
                {
                    indikatorIsi = BinarySearch(dataPelanggan, getcw(), Pelanggan); // mencari kode dalam table pelanggan, apakah sudah ada atau belum

                    if (indikatorIsi == 0) // apabila belum ada
                    {
                        // maka lakukan input data pelanggan
                        insertData(pita, dataPelanggan, Pelanggan);
                    }
                    else
                    {
                        displayError("2I000", "Kode yang dituju sudah ada di dalam database");
                        // error dikarenakan kode yang di input sudah ada dalam table pelanggan
                    }
                }
            }
            else
            {
                displayError("1I000", "Mohon maaf, query untuk mengisi record baru kurang");
                // apabila nilai yang ingin dimasukkan ke dalam table masih kurang
            }
        }
    }
    else if (strcmp(getcw(), "UBAH") == 0) // apabila query selanjutnya adalah UBAH (maka menjadi ISI UBAH)
    {
        if (eop(pita) == 1) // apabila sudah EOP
        {
            displayError("1I000", "Mohon maaf, query untuk mengisi/mengubah record kurang");
            // print error dikarenakan query masih belum cukup untuk melakukan perintah ISI / UBAH
        }
        else // apabila bukan EOP
        {
            inc(pita); // maju ke kata berikutnya

            if (strcmp(getcw(), "menu") == 0 || strcmp(getcw(), "pelanggan") == 0) // apabila cw adalah table menu / pelanggan
            {
                strcpy(table, getcw()); // mengcopy cw ke dalam string table

                if (eop(pita) == 1) // apabila sudah eop
                {
                    displayError("1I000", "Mohon maaf, query untuk mengisi/mengubah record kurang");
                    // print error dikarenakan query masih belum cukup untuk melakukan perintah ISI / UBAH
                }
                else // apabila bukan EOP
                {
                    inc(pita); // maju ke kata berikutnya

                    if (eop(pita) == 1) // apabila EOP
                    {
                        displayError("1I000", "Mohon maaf, query untuk mengisi/mengubah record kurang");
                        // print error dikarenakan query masih belum cukup untuk melakukan perintah ISI / UBAH
                    }
                    else // apabila bukan EOP
                    {
                        int indikatorIsi = 0; // indikator penentu untuk melakukan ISI data
                        
                        if (strcmp(table, "menu") == 0) // apabila table yang dituju adalah tabel menu
                        {
                            indikatorIsi = BinarySearch(dataMenu, getcw(), Menu); // mencari kode yang diinput apakah sudah ada dalam tabel menu
                        }
                        else // apabila tabel yang dituju adalah tabel pelanggan
                        {
                            indikatorIsi = BinarySearch(dataPelanggan, getcw(), Pelanggan); // mencari kode yang diinput apakah sudah ada dalm tabel pelanggan
                        }

                        if (indikatorIsi == 1) // apabila sudah ada
                        {
                            if (strcmp(table, "menu") == 0) // apabila tabel yg dituju adalah menu
                            {
                                updateData(pita, Menu); // melakukan update record dalam table menu
                            }
                            else // apabila table yang dituju adalah pelanggan
                            {
                                updateData(pita, Pelanggan); // melakukan update record dalam tabel pelanggan
                            }
                        }
                        else // apabila belum ada
                        {
                            if (strcmp(table, "menu") == 0) // apabila tabel yg dituju adalah menu
                            {
                                insertData(pita, dataMenu, Menu); // melakukan isi record dalam table menu
                            }
                            else // apabila table yang dituju adalah pelanggan
                            {
                                insertData(pita, dataPelanggan, Pelanggan); // melakukan isi record dalam tabel pelanggan
                            }
                        }
                    }
                }
            }
            else
            {
                displayError("2I000", "Mohon maaf, table tujuan tidak ada");
                // print error dikarenakan query ketiga / table tujuan tidak ada atau TYPO
            }
        }
    }
    else if (strcmp(getcw(), "HAPUS") == 0) // apabila query selanjutnya adalah HAPUS (maka menjadi ISI HAPUS)
    {
        if (eop(pita) == 1) // apabila EOP
        {
            // print error dikarenakan querry masih belum cukup untuk melakukan perintah ISI / HAPUS
            displayError("1I000", "Mohon maaf, query untuk mengisi/menghapus record kurang");
        }
        else // jika bukan EOP
        {
            // maju ke kata berikutnya
            inc(pita);

            // apabila cw adalah table menu / pelanggan
            if (strcmp(getcw(), "menu") == 0 || strcmp(getcw(), "pelanggan") == 0)
            {
                // maka mencatat nya ke dalam table
                strcpy(table, getcw());

                if (eop(pita) == 1) // apabila eop
                {
                    // print error dikarenakan querry masih belum cukup
                    displayError("1I000", "Mohon maaf, query untuk mengisi/menghapus record kurang");
                }
                else // apabila bukan EOP
                {
                    inc(pita); // maju ke kata berikutnya

                    int indikatorIsi = 0; // indikator untuk melakukan perintah ISI
                    if (strcmp(table, "menu") == 0) // apabila table yang dituju adalah menu
                    {
                        indikatorIsi = BinarySearch(dataMenu, getcw(), Menu); // mencari kode yang diinput di dalam table menu

                        if (indikatorIsi == 1) // apabila ada didalam table menu
                        {
                            int indikatorHapus = 0; // indikator untuk menentukan apakah bisa dihapus atau tidak
                            indikatorHapus = BinarySearch2(dataPelanggan, getcw(), Pelanggan); // mencari di table pelanggan apakah ada record yang membawa kode dari table menu

                            if (indikatorHapus == 1) // apabila ada
                            {
                                // print error, dikarenakan kode masih berada di table pelanggan
                                displayError("1J000", "RESTRICT, Tidak dapat menghapus, dikarenakan masih tersangkut di table lain");
                            }
                            else // apabila tidak ada
                            {
                                // maka hapus record di dalam tabel menu
                                deleteData(pita, dataMenu, Menu);
                            }
                        }
                        else // apabila kode tidak ada dalam table menu
                        {
                            // maka lakukan ISI data table menu
                            insertData(pita, dataMenu, Menu);
                        }
                    }
                    else // apabila yang dituju adalah table pelanggan
                    {
                        indikatorIsi = BinarySearch(dataPelanggan, getcw(), Pelanggan); // mencari kode di dalam tabel pelanggan, apakah sudah ada atau belum
                        if (indikatorIsi == 1) // apabila sudah ada
                        {
                            if (eop(pita) == 1) // apabila sudah di ujung pita
                            {
                                deleteData(pita, dataPelanggan, Pelanggan); // maka lakukan delete record dalam table pelanggan
                            }
                            else // apabila belum eop
                            {
                                // print error, dikarenakan query untuk melakukan hapus berlebih
                                displayError("1U000", "Mohon maaf, query untuk menghapus tidak memenuhi spesifikasi");
                            }
                        }
                        else // apabila belum ada
                        {
                            if (eop(pita) == 1) // apabila sudah di ujung pita
                            {
                                // print error, dikarenakan untuk melakukan ISI data masih butuh nilai yang dibutuhkan
                                displayError("1I000", "Mohon maaf, query untuk mengISI record kurang dari spesifikasi");
                            }
                            else // apabila belum EOP
                            {
                                // lakukan ISI record data dalam tabel pelanggan
                                insertData(pita, dataPelanggan, Pelanggan);
                            }
                        }
                    }
                }
            }
            else
            {
                // print error, dikarenakan table yang dituju tidak ada
                displayError("2I000", "Mohon maaf, table tujuan tidak ada");
            }
        }
    }
    else if (strcmp(getcw(), "TAMPIL") == 0) // apabila query selanjutnya adalah TAMPIL (maka menjadi ISI TAMPIL)
    {
        if (eop(pita) == 1) // apabila sudah di ujung pita
        {
            // print error, dikarenakan masih belum cukup query untuk melakukan ISI / HAPUS
            displayError("1I000", "Mohon maaf, query untuk mengisi/menghapus record kurang");
        }
        else // apabila belum
        {
            inc(pita); // maju ke kata berikutnya

            // apabila cw adalah table menu / pelanggan
            if (strcmp(getcw(), "menu") == 0 ||  strcmp(getcw(), "pelanggan") == 0)
            {
                strcpy(table, getcw()); // copy cw ke dalam string table

                if (eop(pita) == 1) // apabila sudah di EOP
                {
                    ListData(pita); // maka tampilkan data table pelanggan / menu
                }
                else // apabila belum EOP
                {
                    inc(pita); // maju ke kata berikutnya
                    
                    // apabila query berikutnya adalah table pelanggan / menu dan melakukan join
                    if ( (strcmp(getcw(), "menu") == 0 && strcmp(table, "pelanggan") == 0) || (strcmp(getcw(), "pelanggan") == 0 && strcmp(table, "menu") == 0))
                    {
                        if (eop(pita) == 1) // apabila sudah di EOP
                        {    
                            joinData(); // maka lakukan join Table
                            // dan membuat table untuk Join 
                            BikinTableJoin("Kode Pelanggan", "Nama Pelanggan", "Kode Menu", "Notelp Pelanggan", "Tipe Menu", "Nama Menu", "Harga Menu", JoinKuy, dataJoin);
                            printf("Table Join %s %s berhasil di tampilkan.\n\n", table, getcw()); 
                        }
                        else // apabila belum di EOP
                        {
                            // print error dikarenakan query yang diinput berlebih
                            displayError("11I000", "Query melebihi batas");
                        }
                    }
                    else // apabila query berikutnya adalah selain table pelanggan / menu
                    {
                        int indikatorIsi = 0; // indikator untuk menentukan apakah data sudah ada dalam table atau belum
                        if (strcmp(table, "menu") == 0) // apabila table yang dituju adalah menu
                        {
                            indikatorIsi = BinarySearch(dataMenu, getcw(), Menu); // mencari kode di dalam table menu

                            if (indikatorIsi == 1) // apabila ada
                            {
                                gotoEOP(pita);
                                ListData(pita); // maka lakukan perintah TAMPIL
                            }
                            else // jika tidak
                            {
                                if (eop(pita) == 1) // apabila sudah diujung pita
                                {
                                    // print error dikarenakan query kurang untuk melakukan perintah ISI data
                                    displayError("1I000", "Mohon maaf, query untuk mengisi kurang dari spesifikasi");
                                }
                                else // apabila belum EOP
                                {
                                    displayError("7I000", "Query yang diberikan tidak valid, pastikan tidak ada 2 Perintah yang bisa dilaksanakan");
                                }
                            }
                        }
                        else // apabila tabel yang dituju adalah pelanggan
                        {
                            // mencari kode didalam table pelanggan, apakah sudah ada atau belum
                            indikatorIsi = BinarySearch(dataPelanggan, getcw(), Pelanggan);

                            if (indikatorIsi == 1) // jika sudah ada, maka lakukan TAMPIL data
                            {
                                gotoEOP(pita);
                                ListData(pita);
                            }
                            else // jika belum
                            {
                                if (eop(pita) == 1) // dan sudah ada di ujung pita
                                {
                                    // print error dikarenakan query kurang untuk melakukan ISI data
                                    displayError("1I000", "Mohon maaf, query untuk mengisi kurang dari spesifikasi");
                                }
                                else // apabila belum di ujung pita
                                {
                                    // lakukan ISI data table pelanggan
                                    displayError("7I000", "Query yang diberikan tidak valid, pastikan tidak ada 2 Perintah yang bisa dilaksanakan");
                                }
                            }
                        }
                    }
                }
            }
            else // apabila query / table yang dituju tidak ada
            {
                // print error dikarenakan table yg dituju tidak ada
                displayError("2I000", "Mohon maaf, table tujuan tidak ada");
            }
        }
        
    }
    else if (strcmp(getcw(), "ISI") == 0) // apabila query selanjutnya adalah ISI, maka menjadi ISI ISI
    {
        inc(pita); // maju ke kata berikutnya

        // apabila cw adalah menu / pelanggan
        if (strcmp(getcw(), "menu") == 0 || strcmp(getcw(), "pelanggan") == 0)
        {
            strcpy(table, getcw()); // maka copy cw ke dalam string tabel
            if (eop(pita) == 1) // apabila sudah di ujung pita
            {
                // print error dikarenakan query masih belum cukup
                displayError("1I000", "Mohon maaf, query untuk mengisi record baru kurang");
            }
            else // apabila belum
            {
                // indikator untuk menentukan apakah bisa input data atau tidak
                int indikatorIsi = 0;
                inc(pita); // maju ke kata berikutnya

                if (eop(pita) == 0) // apabila belum EOP
                {    
                    if (strcmp(table, "menu") == 0) // apabila tabel yang dituju adalah menu
                    {
                        indikatorIsi = BinarySearch(dataMenu, getcw(), Menu); // mencar kode di dalam tabel menu

                        if (indikatorIsi == 0) // apabila tidak ada
                        {
                            insertData(pita, dataMenu, Menu); // lakukan isi data tabel MENU
                        }
                        else // apabila ada
                        {
                            // print error dikarenakan kode sudah ada dalam tabel
                            displayError("2I000", "Kode yang dituju sudah ada di dalam database");
                        }
                    }
                    else // apabila tabel yang dituju adalah pelanggan
                    {
                        // mencari kode didalam table pelanggan
                        indikatorIsi = BinarySearch(dataPelanggan, getcw(), Pelanggan);

                        if (indikatorIsi == 0) // apabila belum ada
                        {
                            // maka ISI data record dalam table pelanggan
                            insertData(pita, dataPelanggan, Pelanggan);
                        }
                        else // apabila sudah ada
                        {
                            // maka print error kode sudah ada dalam table pelanggan
                            displayError("2I000", "Kode yang dituju sudah ada di dalam database");
                        }
                    }
                }
                else // apabila EOP
                {
                    // print error dikarenakan query masih kurang untuk melakukan perintah
                    displayError("1I000", "Mohon maaf, query untuk mengisi record baru kurang");
                }
            }
        }
    }
    else // query kedua yang diinput tidak valid
    {
        // print error dikarenakan query kedua tidak masuk ke dalam spesifikasi manapun
        displayError("10I000", "Query kedua yang diberikan tidak valid");
    }
}

void UbahQuery(char pita[])
{
    inc(pita); // maju ke kata berikutnya

    // apabila cw adalah table menu/pelanggan
    if (strcmp(getcw(), "pelanggan") == 0 || strcmp(getcw(), "menu") == 0) 
    {
        // apabila eop
        if (eop(pita) == 1)
        {
            // print error dikarenakan query masih kurang untuk melakukan perintah UBAH
            displayError("1U000", "Query yang diberikan tidak valid, tidak ada kode yang dituju");   
        }
        else // apabila belum EOP
        {
            // copy cw ke dalam string table
            strcpy(table, getcw());
            inc(pita); // maju ke kata berikutnya

            if (eop(pita) == 1) // apabila EOP
            {
                // print error, dikarenakan query kurang untuk melakukan perintah ISI data
                displayError("2U000", "Query yang diberikan tidak valid, data yang dibutuhkan kurang untuk ubah");
            }
            else // apabila belum
            {
                // indikator untuk menentukan apakah bisa melanjutkan proses UBAH data
                int indikatorUbah = 0;
                
                if (strcmp(table, "menu") == 0) // apabila table yang dituju adalah table menu
                {
                    indikatorUbah = BinarySearch(dataMenu, getcw(), Menu); // mencari kode nya di dalam table menu
                    
                    if (indikatorUbah == 1) // apabila ada
                    {
                        updateData(pita, Menu); // maka lakukan update data
                    }
                    else // apabila tidak ada
                    {
                        // print error, dikarenakan kode tidak ada untuk di UBAH
                        displayError("2U000", "Kode yang dituju tidak ada di database");
                    }
                }
                else // apabila table yang dituju adala htable pelanggan
                {
                    // mencari kode nya di dalam table pelanggan
                    indikatorUbah = BinarySearch(dataPelanggan, getcw(), Pelanggan);
                    
                    if (indikatorUbah == 1) // apabila ada
                    {
                        updateData(pita, Pelanggan); // maka lakukan UBAH data pelanggan
                    }
                    else // apabila tidak ada
                    {
                        // print error dikarenakan kode tidak ada
                        displayError("2U000", "Kode yang dituju tidak ada di database");
                    }
                }
            }
        }
    }
    else if (strcmp(getcw(), "ISI") == 0) // apabila query kedua adalah ISI, maka menjadi UBAH ISI
    {
        inc(pita); // maju ke kata berikutnya

        if (strcmp(getcw(), "pelanggan") == 0 || strcmp(getcw(), "menu") == 0)
        {
            if (eop(pita) == 1) // apabila sudah di ujung pita / EOP
            {
                // print error dikarenakan query yang diberikan masih kurang untuk melakukan perintah
                displayError("1U000", "Query yang diberikan tidak valid, tidak ada kode yang dituju");   
            }
            else // apabila belum di EOP
            {
                strcpy(table, getcw()); // copy cw ke dalam table
                inc(pita); // maju ke kata berikutnya

                if (eop(pita) == 1) // apabila sudah di ujung pita / EOP
                {
                    // print error dikarenakan query masih kurang untuk melakukan perintah
                    displayError("2U000", "Query yang diberikan tidak valid, data yang dibutuhkan kurang untuk ubah");
                }
                else // apabila belum di ujung EOP
                {
                    int indikatorUbah = 0; // indikator apakah akan dilakukan UBAH data
                    
                    if (strcmp(table, "menu") == 0) // apabila table yang dituju adalah menu
                    {
                        indikatorUbah = BinarySearch(dataMenu, getcw(), Menu); // mencari kode di dalam tabel menu
                        
                        if (indikatorUbah == 1) // apabila ada
                        {
                            updateData(pita, Menu); // maka lakukan UBAH data
                        }
                        else // apabila tidak ada
                        {
                            insertData(pita, dataMenu, Menu); // maka lakukan ISI data
                        }
                    }
                    else // apabila table yang dituju adalah pelanggan
                    {
                        indikatorUbah = BinarySearch(dataPelanggan, getcw(), Pelanggan); // mencari kode di dalam tabel pelanggan
                         
                        if (indikatorUbah == 1) // apabila ada
                        {
                            updateData(pita, Pelanggan); // maka lakuka UBAH data
                        }
                        else // apabila tidak ada
                        {
                            insertData(pita, dataPelanggan, Pelanggan); // maka lakukan ISI data
                        }
                    }
                }
            }
        }
        else // apabila Query kedua / tabel yang dituju tidak ada
        {
            // print error dikarenakan query tidak valid
            displayError("4U000", "Query yang diberikan tidak valid, tabel yang dituju tidak valid");
        }
    }
    else if (strcmp(getcw(), "TAMPIL") == 0) // apabila query kedua TAMPIL, maka menjadi UBAH TAMPIL
    {
        if (eop(pita) == 1) // apabila sudah di ujung pita / EOP
        {
            // print error dikarenakan query yang diinput kurang
            displayError("5U000", "Query yang diberikan tidak valid, masukkan query kurang");
        }
        else
        {
            inc(pita); // maju ke kata berikutnya

            if (eop(pita) == 1) // apabila sudah di ujung pita / EOP
            {
                // apabila tabel yang dituju adalah pelanggan / menu
                if (strcmp(getcw(), "menu") == 0 || strcmp(getcw(), "pelanggan") == 0)
                {
                    strcpy(table, getcw()); // copy string cw ke dalam table
                    if (eop(pita) == 1) // apabila sudah di ujung pita / EOP
                    {
                        ListData(pita); // TAMPIL data table menu / pelanggan
                    }
                }
                else // apabila tabel yang dituju tidak valid
                {
                    // print error dikarenakan table tidak ada
                    displayError("6U000", "Mohon maaf, tabel yang dituju tidak ada");
                }
            }
            else // apabila belum EOP
            {
                // apabila tabel yang dituju adalah pelanggan / menu
                if (strcmp(getcw(), "menu") == 0 || strcmp(getcw(), "pelanggan") == 0)
                {
                    strcpy(table, getcw()); // copy cw ke dalam string table
                    inc(pita); // maju ke kata berikutnya

                        // apabila query adalah mengjoin pelanggan menu
                        if ( (strcmp(getcw(), "pelanggan") == 0 && (strcmp(table, "menu") == 0) ) || (strcmp(getcw(), "menu") == 0 && (strcmp(table, "pelanggan") == 0) ))
                        {
                            joinData(); // melakukan join table
                            // print table untuk menampilkan table join menu dan pelanggan
                            BikinTableJoin("Kode Pelanggan", "Nama Pelanggan", "Kode Menu", "Notelp Pelanggan", "Tipe Menu", "Nama Menu", "Harga Menu", JoinKuy, dataJoin);
                            printf("Table Join %s %s berhasil di tampilkan.\n\n", table, getcw());  
                        }
                        else // apabila selain join
                        {
                            query2 = 1; // menandakan bahwa query kedua bisa laksanakan
                            int indikatorUbah = 0; // indikator untuk menentukan apakah UBAH bisa diproses atau tidak
                        
                            if (strcmp(table, "menu") == 0) // apabila table yang dituju adalah table menu
                            {
                                indikatorUbah = BinarySearch(dataMenu, getcw(), Menu); // mencari kode didalam table menu
                                
                                if (indikatorUbah == 1) // apabila ada
                                {
                                    // print error, dikarenakan dua perintah bisa dilaksanakan
                                    displayError("7U000", "Query yang diberikan tidak valid, pastikan tidak ada 2 Perintah yang bisa dilaksanakan");
                                }
                                else // apabila tidak ada
                                {
                                    gotoEOP(pita); // pergi ke EOP
                                    ListData(pita); // menampilkan data table Menu
                                }
                            }
                            else // apabila table yang dituju adalah table pelanggan
                            {
                                indikatorUbah = BinarySearch(dataPelanggan, getcw(), Pelanggan); //mencari kode didalam table pelanggan
                                
                                if (indikatorUbah == 1) // apabila ada
                                {
                                    // print error, dikarenakan dua perintah bisa dilaksanakan
                                    displayError("7U000", "Query yang diberikan tidak valid, pastikan tidak ada 2 Perintah yang bisa dilaksanakan");
                                }
                                else // apabila tidak ada
                                {
                                    gotoEOP(pita); // pergi ke EOP
                                    ListData(pita); // menampilkan data table Pelanggan
                                }
                            }
                        }
                }
                else // apabila table yang dituju tidak ada / tidak valid
                {
                    // print error, dikarenakan table yang dituju tidak ada
                    displayError("6H000", "Query yang diberikan tidak valid, table yang dituju tidak ada");
                }
            }
        }
    }
    else if (strcmp(getcw(), "HAPUS") == 0)
    {
        if (eop(pita) == 1) // apabila sudah di ujung pita / EOP
        {
            // print error dikarenakan query masih kurang untuk melakukan perintah
            displayError("1U000", "Query yang diberikan tidak valid, masukkan query kurang");
        }
        else
        {
            inc(pita); // maju ke kata berikutnya

            if (eop(pita) == 1) // apabila sudah di ujung pita / EOP
            {
                // print error dikarenakan query kurang untuk melakukan perintah
                displayError("2U000", "Query yang diberikan tidak valid, masukkan query kurang");
            }
            else
            {
                // apabila tabel yang dituju adalah pelanggan / menu
                if (strcmp(getcw(), "menu") == 0 || strcmp(getcw(), "pelanggan") == 0)
                {
                    strcpy(table, getcw()); // copy cw ke dalam string table
                    inc(pita); // maju ke kata berikutnya

                    int indikatorUbah = 0; // indikator untuk menentukan apakah akan di proses UBAH atau tidak
                
                    if (strcmp(table, "menu") == 0) // apabila tabel yang dituju adalah table menu
                    {
                        indikatorUbah = BinarySearch(dataMenu, getcw(), Menu); // mencari kode di dalam table menu
                        
                        if (indikatorUbah == 1) // apabila data ada di dalam table
                        {
                            // print error. dikarenakan tidak bisa melakukan dua perintah sekaligus
                            displayError("3U000", "Query yang diberikan tidak valid, pastikan tidak ada 2 Perintah yang bisa dilaksanakan");
                        }
                        else // apabila tidak ada
                        {
                            // print error dikarenakan data tidak ada dalam table menu
                            displayError("4U000", "Kode yang dituju tidak ada di dalam database");
                        }
                    }
                    else // apabila tabel yang dituju adalah table pelanggan
                    {
                        indikatorUbah = BinarySearch(dataPelanggan, getcw(), Pelanggan); // mencari kode dalam table pelanggan
                        
                        if (indikatorUbah == 1) // apabila data ada dalam table
                        {
                            // print error dikarenakan tidak bisa melakukan 2 perintah sekaligus
                            displayError("3U000", "Query yang diberikan tidak valid, pastikan tidak ada 2 Perintah yang bisa dilaksanakan");
                        }
                        else // apabila tidak ada
                        {
                            // print error dikarenakan kode tidak ada dalam table
                            displayError("4U000", "Kode yang dituju tidak ada di dalam database");
                        }
                    }
                }
                else // apabila query selanjutnya / table yang dituju tidak ada
                {
                    // print error dikarenakan table yg dituju tidak ada
                    displayError("5U000", "Query yang diberikan tidak valid, table yang dituju tidak ada");
                }
            }
        }
    }
    else if (strcmp(getcw(), "UBAH") == 0) // apabila query kedua adalah UBAH, maka menjadi UBAH UBAH
    {
        inc(pita); // maju ke kata berikutnya

        // apabila tabel yang dituju adalah pelanggan / menu
        if (strcmp(getcw(), "pelanggan") == 0 || strcmp(getcw(), "menu") == 0)
        {
            if (eop(pita) == 1) // apabila sudah di ujung pita / EOP
            {
                // print error dikarenakan query masih kurang untuk melakukan perintah
                displayError("1U000", "Query yang diberikan tidak valid, tidak ada kode yang dituju");   
            }
            else // apabila belum EOP
            {
                strcpy(table, getcw());  // copy cw ke dalam string table
                inc(pita); // maju ke kata berikutnya

                if (eop(pita) == 1) // apabila sudah di ujung pita / EOP
                {
                    // pritn error dikarenakan query masih kurang untuk melakukan perintah UBAH UBAH
                    displayError("2U000", "Query yang diberikan tidak valid, data yang dibutuhkan kurang untuk ubah");
                }
                else // apabila belum EOP
                {
                    int indikatorUbah = 0; // indikator sebagai penentu apakah akan melanjutkan perintah atau tidak
                    
                    if (strcmp(table, "menu") == 0) // apabila tabel yang dituju adalah table menu
                    {
                        indikatorUbah = BinarySearch(dataMenu, getcw(), Menu); // mencari kode ke dalam table menu
                        
                        if (indikatorUbah == 1) // apabila ada dalam table menu
                        {
                            updateData(pita, Menu); // maka lakukan proses UBAH data di table menu
                        }
                        else // apabila tidak ada
                        {
                            // print error dikarenakan kode yang dituju tidak ada dalam table
                            displayError("2U000", "Kode yang dituju tidak ada di database");
                        }
                    }
                    else // apabila tabel yang dituju adalah table pelanggan
                    {
                        // mencari kode dalam table pelanggan
                        indikatorUbah = BinarySearch(dataPelanggan, getcw(), Pelanggan);
                        
                        if (indikatorUbah == 1) // apabila ada
                        {
                            updateData(pita, Pelanggan); // maka lakukan proses UBAH data di table pelanggan
                        }
                        else // apabila tidak ada
                        {
                            // print error dikarenakan kode yang ingin diuba tidak ada dalam table pelanggan
                            displayError("2U000", "Kode yang dituju tidak ada di database");
                        }
                    }
                }
            }
        }
    }
    else // apabila query kedua yang dimasukkan tidak valid
    {
        // print error dikarenakan query kedua tidak valid
        displayError("4Q000", "Query kedua yang diberikan tidak valid");
    }
}

void HapusQuery(char pita[])
{
    inc(pita); // maju ke kata berikutnya

    if (strcmp(getcw(), "pelanggan") == 0 || strcmp(getcw(), "menu") == 0)
    {
        // apabila cw adalah table pelanggan / menu
        if (eop(pita) == 1) // apabila sudah di ujung pita / EOP
        {
            // print error dikarenakan query masih kurang untuk melakukan perintah
            displayError("1H000", "Query yang diberikan tidak valid, tidak ada kode yang dituju");   
        }
        else // apabila belum EOP
        {
            strcpy(table, getcw()); // copy cw ke dalam string table
            inc(pita); // maju ke kata berikutnya

            if (eop(pita) == 1) // apabila sudah di ujung pita / EOP
            {
                int indikatorDelete = 0; // indikator sebagai penentu apakah akan melanjutkan proses deletee atau tidak
                
                if (strcmp(table, "menu") == 0) // apabila tabel yang dituju adalah table menu
                {
                    indikatorDelete = BinarySearch(dataMenu, getcw(), Menu); // mencari kodenya di dalam table Menu
                    
                    if (indikatorDelete == 1) // apabila ada di dala mtable Menu
                    {
                        int indikatorDelete2 = 0; // maka cek lagi, apakah kode tersebut menyangkut di table pelanggan

                        indikatorDelete2 = BinarySearch2(dataPelanggan, getcw(), Pelanggan); // cek kode di table pelanggan

                        if (indikatorDelete2 == 1) // apabila ada
                        {
                            // print error dikarenakan kode tersebut berada di table pelanggan
                            displayError("1J000", "RESTRICT, Tidak dapat menghapus, dikarenakan masih tersangkut di table lain");
                        }
                        else // apabila tidak ada
                        {
                            // maka lakukan HAPUS data
                            deleteData(pita, dataMenu, Menu);
                        }
                    }
                    else // apabila tidak ada
                    {
                        // print error dikarenakan kode yang ingin di HAPUS tidak ada
                        displayError("3H000", "Kode yang dituju tidak ada di database");
                    }
                }
                else // apabila tabel yang dituju adalah table pelanggan
                {
                    // mencari kode di dalam tabel pelanggan
                    indikatorDelete = BinarySearch(dataPelanggan, getcw(), Pelanggan);
                    
                    if (indikatorDelete == 1) // apabila ada
                    {
                        // maka lakukan HAPUS data dalam tabel pelanggan
                        deleteData(pita, dataPelanggan, Pelanggan);
                    }
                    else // apabila tidak ada
                    {
                        // print error dikarenakan kode yang ingin di HAPUS tidak ada
                        displayError("3H000", "Kode yang dituju tidak ada di database");
                    }
                }
            }
            else // apabila belum EOP
            {
                // print error dikarenakan query yang dimasukkan melebihi batas
                displayError("2H000", "Query yang diberikan tidak valid, lewat dari batas Query");   
            }
        }
    }
    else if (strcmp(getcw(), "ISI") == 0)
    {
        if (eop(pita) == 1) // apabila sudah di ujung pita / EOP
        {
            // print error dikarenakan query masih kurang untuk melanjutkan perintah
            displayError("4H000", "Query yang diberikan tidak valid, masukkan query kurang");
        }
        else
        {
            inc(pita); // maju ke kata berikutnya

            if (eop(pita) == 1) // apabila sudah di ujung pita / EOP
            {
                // print error dikarenakan query masih kurang untuk melanjutkan perintah
                displayError("5H000", "Query yang diberikan tidak valid, masukkan query kurang");
            }
            else
            {
                // apabila cw adalah table pelanggan / menu
                if (strcmp(getcw(), "menu") == 0 || strcmp(getcw(), "pelanggan") == 0)
                {
                    strcpy(table, getcw()); // copy cw ke dalam string table
                    inc(pita); // maju ke kata berikutnya

                    int indikatorDelete = 0; // indikator sebagai penentu apakah perintah akan tetap dilanjutkan atau tidak
                
                    if (strcmp(table, "menu") == 0) // apabila tabel yang dituju adalah table menu
                    {
                        indikatorDelete = BinarySearch(dataMenu, getcw(), Menu);
                        // mencari kode tersebut di dalam table menu
                        
                        if (indikatorDelete == 1) // apabila ada
                        {
                            int indikatorDelete2 = 0; // maka cek kembali, apakah kode tersebut dipakai/sangkut di table pelanggan

                            indikatorDelete2 = BinarySearch2(dataPelanggan, getcw(), Pelanggan); // mencari kode tersebut di dalam table pelanggan

                            if (indikatorDelete2 == 1) // apabila ada
                            {
                                // print error dikarenakan kode tersebut menyangkut di table pelanggan
                                displayError("1J000", "RESTRICT, Tidak dapat menghapus dan isi, dikarenakan data ada dan masih tersangkut di table lain");
                            }
                            else // apabila tidak ada
                            {
                                // maka HAPUS data dalam table menu
                                deleteData(pita, dataMenu, Menu);
                            }
                        }
                        else // apabila tidak ada
                        {
                            if (eop(pita) == 1) // apabila sudah di ujung pita / EOP
                            {
                                // print error dikarenakan query masih kurang untuk melanjutkan perintah
                                displayError("7H000", "Query yang diberikan tidak valid, data yang ingin di isi kurang, atau kode yang dituju tidak ada di database");
                            }
                            else // apabila belum EOP
                            {
                                // maka lanjutkan proses ISI data
                                insertData(pita, dataMenu, Menu);
                            }
                        }
                    }
                    else // apabila tabel yang dituju adalah table pelanggan
                    {
                        // mencari kode didalam table pelanggan
                        indikatorDelete = BinarySearch(dataPelanggan, getcw(), Pelanggan);
                        
                        if (indikatorDelete == 1) // apabila ada
                        {
                            // melakukan proses HAPUS data dalam tabel pelanggan
                            deleteData(pita, dataPelanggan, Pelanggan);
                        }
                        else // apabila tidak ada
                        {
                            if (eop(pita) == 1) // apabila sudah di ujung pita / EOP
                            {
                                // print error dikarenakan query masih kurang untuk melanjutkan perintah
                                displayError("7H000", "Query yang diberikan tidak valid, data yang ingin di isi kurang, atau kode yang dituju tidak ada di database");
                            }
                            else // apabila belum EOP
                            {
                                // melanjutkan proses ISI data
                                insertData(pita, dataPelanggan, Pelanggan);
                            }
                        }
                    }
                }
                else // apabila query berikut nya / table yang dituju tidak ada / valid
                {
                    // print error dikarenakan query error dan table tidak valid
                    displayError("6H000", "Query yang diberikan tidak valid, table yang dituju tidak ada");
                }
            }
        }
    }
    else if (strcmp(getcw(), "UBAH") == 0) // apabila query berikutnya UBAH, maka perintah menjadi HAPUS UBAH
    {
        if (eop(pita) == 1) // apabila sudah di EOP
        {
            // print error dikarenakan query masih kurang untuk melanjutkan perintah
            displayError("4H000", "Query yang diberikan tidak valid, masukkan query kurang");
        }
        else // apabila belum EOP
        {
            inc(pita); // maju ke kata berikutnya

            if (eop(pita) == 1) // apabila sudah di ujung pita / EOP
            {
                // print error dikarenakan query masih kurang untuk melanjutkan perintah
                displayError("5H000", "Query yang diberikan tidak valid, masukkan query kurang");
            }
            else
            {
                if (strcmp(getcw(), "menu") == 0 || strcmp(getcw(), "pelanggan") == 0)
                {
                    // apabila cw adalah table pelanggan / menu
                    strcpy(table, getcw()); // copy cw ke dalam string table
                    inc(pita); // maju ke kata berikutnya

                    int indikatorDelete = 0; // indikator sebagai penentu apakah perintah akan tetap dilanjutkan atau tidak
                
                    if (strcmp(table, "menu") == 0) // apabila tabel yang dituju adalah table menu
                    {
                        indikatorDelete = BinarySearch(dataMenu, getcw(), Menu);
                        // mencari kode tersebut di dalam tabel Menu
                        
                        if (indikatorDelete == 1) // apabila ada
                        {
                            // print error dikarenakan 2 perintah bisa dijalankan sekaligus
                            displayError("3D000", "Query yang diberikan tidak valid, pastikan tidak ada 2 Perintah yang bisa dilaksanakan");
                        }
                        else // apabila tidak ada
                        {
                            // print error dikarenakan kode tersebut tidak ada dalam table menu
                            displayError("8H000", "Kode yang dituju tidak ada di dalam database");
                        }
                    }
                    else // apabila tabel yang dituju adalah table pelanggan
                    {
                        // mencari kode tersebut di dalam tabel pelanggan
                        indikatorDelete = BinarySearch(dataPelanggan, getcw(), Pelanggan);
                        
                        if (indikatorDelete == 1) // apabila ada
                        {
                            // print error dikarenakan 2 perintah tersebut bisa dilaksanakan sekaligus
                            displayError("3D000", "Query yang diberikan tidak valid, pastikan tidak ada 2 Perintah yang bisa dilaksanakan");
                        }
                        else // apabila tidak ada
                        { 
                            // print error dikarenakan kode tersebut tidak ada dalam tabel pelanggan
                            displayError("8H000", "Kode yang dituju tidak ada di dalam database");
                        }
                    }
                }
                else // apabila query selanjutnya tidak valid, atau table yang dituju tidak ada
                {
                    // print error dikarenakan query tidak valid
                    displayError("6H000", "Query yang diberikan tidak valid, table yang dituju tidak ada");
                }
            }
        }
    }
    else if (strcmp(getcw(), "TAMPIL") == 0) // apabila query selanjutnya adalah TAMPIL, maka menjadi HAPUS TAMPIL
    {
        if (eop(pita) == 1) // apabila sudah di ujung pita / EOP
        {
            // print error dikarenakan query masih kurang untuk melanjutkan perintah
            displayError("4H000", "Query yang diberikan tidak valid, masukkan query kurang");
        }
        else
        {
            inc(pita); // maju ke kata berikutnya

            if (eop(pita) == 1) // apabila sudah di ujung pita / EOP
            {
                // apabila cw adalah table pelanggan / menu
                if (strcmp(getcw(), "menu") == 0 || strcmp(getcw(), "pelanggan") == 0)
                {
                    strcpy(table, getcw()); // copy cw ke dalam string table
                    if (eop(pita) == 1) // apabila EOP
                    {
                        ListData(pita); // maka TAMPILkan table
                    }
                }
                else // apabila table yang dituju tidak ada
                {
                    // print error dikarenakan table yang dituju tidak valid
                    displayError("5H000", "Mohon maaf, tabel yang dituju tidak ada");
                }
            }
            else // apabila belum EOP
            {
                // apabila cw adalah table pelanggan / menu
                if (strcmp(getcw(), "menu") == 0 || strcmp(getcw(), "pelanggan") == 0)
                {
                    strcpy(table, getcw()); // copy cw ke dalam string table
                    inc(pita); // maju ke kata berikutnya

                    if (eop(pita) == 1) // apabila sudah di ujung pita / EOP
                    {
                        // apabila query berikutnya adalah table lagi, maka lakukan join
                        if ( (strcmp(getcw(), "pelanggan") == 0 && (strcmp(table, "menu") == 0) ) || (strcmp(getcw(), "menu") == 0 && (strcmp(table, "pelanggan") == 0) ))
                        {
                            // melakukan join table
                            joinData();
                            // memunculkan table join
                            BikinTableJoin("Kode Pelanggan", "Nama Pelanggan", "Kode Menu", "Notelp Pelanggan", "Tipe Menu", "Nama Menu", "Harga Menu", JoinKuy, dataJoin);
                            printf("Table Join %s %s berhasil di tampilkan.\n\n", table, getcw());  
                        }
                        else // apabila query berikutnya selain nama table
                        {
                            query2 = 1; // menandakan bahwa query perintah ke 2 bisa dilaksanakan
                            int indikatorDelete = 0; // indikator sebagai penentu apakah perintah akan tetap dilanjutkan atau tidak
                        
                            if (strcmp(table, "menu") == 0) // apabila tabel yang dituju adalah table menu
                            {
                                indikatorDelete = BinarySearch(dataMenu, getcw(), Menu); // mencari kode tersebut di dalam table menu
                                
                                if (indikatorDelete == 1) // apabila ada
                                {
                                    // print error, dikarenakan 2 perintah bisa dilaksanakan
                                    displayError("3D000", "Query yang diberikan tidak valid, pastikan tidak ada 2 Perintah yang bisa dilaksanakan");
                                }
                                else // apabila tidak ada
                                {
                                    // lakukan TAMPIL data table
                                    ListData(pita);
                                }
                            }
                            else // apabila tabel yang dituju adalah table pelanggan
                            {
                                // mencari kode di dalam table pelanggan
                                indikatorDelete = BinarySearch(dataPelanggan, getcw(), Pelanggan);
                                
                                if (indikatorDelete == 1) // apabila ada
                                {
                                    // print error dikarenakan 2 perintah bisa dilaksanakan
                                    displayError("3D000", "Query yang diberikan tidak valid, pastikan tidak ada 2 Perintah yang bisa dilaksanakan");
                                }
                                else // apabila tidak ada
                                {
                                    // lakukan TAMPIL data table
                                    ListData(pita);
                                }
                            }
                        }
                    }
                    else // apabila query yang diberikan kelebihan
                    {
                        // print error dikarenakan pita yang dimasukkan berlebih
                        displayError("9H000", "Mohon maaf, query yang diberikan melebihi spesifikasi");
                    }
                }
                else // apabila query selanjutnya tidak valid atau tableyang dituju tidak ada
                {
                    // print error
                    displayError("6H000", "Query yang diberikan tidak valid, table yang dituju tidak ada");
                }
            }
        }
    }
    else if (strcmp(getcw(), "HAPUS") == 0)
    {
        inc(pita); // maju ke kata berikutnya

        // apabila cw adalah table pelanggan / menu
        if (strcmp(getcw(), "pelanggan") == 0 || strcmp(getcw(), "menu") == 0)
        {
            if (eop(pita) == 1) // apabila sudah di ujung pita / EOP
            {
                // print error dikarenakan query masih kurang untuk melanjutkan perintah
                displayError("1H000", "Query yang diberikan tidak valid, tidak ada kode yang dituju");   
            }
            else
            {
                strcpy(table, getcw()); // copy cw ke dalam string table
                inc(pita); // maju ke kata berikutnya

                if (eop(pita) == 1) // apabila sudah di ujung pita / EOP
                {
                    int indikatorDelete = 0; // indikator sebagai penentu apakah perintah akan tetap dilanjutkan atau tidak
                    
                    if (strcmp(table, "menu") == 0) // apabila tabel yang dituju adalah table menu
                    {
                        indikatorDelete = BinarySearch(dataMenu, getcw(), Menu);
                        // mencari kode didalam table Menu
                    
                        if (indikatorDelete == 1) // apabila ada
                        {
                            int indikatorDelete2 = 0; // maka cek kemabli, apakah kode tersebut berada di table pelanggan

                            indikatorDelete2 = BinarySearch2(dataPelanggan, getcw(), Pelanggan); // mencari kode tersebut di dalam table pelanggan

                            if (indikatorDelete2 == 1) // apabila ada
                            {
                                // print error, dikarenakan kode tersebut berada di table pelanggan
                                displayError("1J000", "RESTRICT, Tidak dapat menghapus, dikarenakan masih tersangkut di table lain");
                            }
                            else // apabila tidak ada
                            {
                                // maka lakukan HAPUS record dalam table menu
                                deleteData(pita, dataMenu, Menu);
                            }
                        }
                        else // apabila tidak ada
                        {
                            // print error dikarenakan kode yang dituju tidak ada dalam table menu
                            displayError("3H000", "Kode yang dituju tidak ada di database");
                        }
                    }
                    else // apabila table yang dituju adalah pelanggan
                    {
                        // mencari kode tersebut di table pelanggan
                        indikatorDelete = BinarySearch(dataPelanggan, getcw(), Pelanggan);
                        if (indikatorDelete == 1) // apabila ada
                        {
                            // maka lakukan HAPUS record dalam table pelanggan
                            deleteData(pita, dataPelanggan, Pelanggan);
                        }
                        else // apabila tidak ada
                        {
                            // print error dikarenakan kode tidak ada dalam table menu
                            displayError("3H000", "Kode yang dituju tidak ada di database");
                        }
                    }
                }
                else // apabila belum eop
                {
                    // print error dikarenakan query yang di berikan kelebihan
                    displayError("2H000", "Query yang diberikan tidak valid, lewat dari batas Query");   
                }
            }
        }
    }
    else // apabila query kedua tidak valid
    {
        // print error dikarenakan query kedua tidak valid
        displayError("4Q000", "Query kedua yang diberikan tidak valid");
    }
}

void TampilQuery(char pita[])
{
    inc(pita); // maju ke kata berikutnya
    
    // apabila cw adalah table pelanggan / menu
    if (strcmp(getcw(), "pelanggan") == 0 || strcmp(getcw(), "menu") == 0)
    {
        strcpy(table, getcw()); // copy cw ke dalam string table
        ListData(pita); // maka lakukan TAMPIL data
    }

    else if (strcmp(getcw(), "ISI") == 0)
    {
        inc(pita); // maju ke kata berikutnya
        // apabila cw adalah table pelanggan / menu
        if (strcmp(getcw(), "pelanggan") == 0 || strcmp(getcw(), "menu") == 0)
        {
            if (eop(pita) == 1) // apabila sudah di ujung pita / EOP
            {
                strcpy(table, getcw()); // copy cw ke dalam string table
                ListData(pita); // maka lakukan TAMPIL data
            }
            else // apabila belum EOP
            {
                strcpy(table, getcw()); // copy cw ke dalam string table
                query1 = 1; // maka menandai bahwa query pertama bisa dilaksanakan
                inc(pita); // maju ke kata berikutnya

                // apabila cw adalah nama table menu/pelanggan, maka di join
                if ( (strcmp(getcw(), "pelanggan") == 0 && (strcmp(table, "menu") == 0) ) || (strcmp(getcw(), "menu") == 0 && (strcmp(table, "pelanggan") == 0) ))
                {
                    if (eop(pita) == 1) // apabila sudah di ujung pita / EOP
                    {
                        // melakukan join table
                        joinData();
                        // memunculkan table yang sudah di join
                        BikinTableJoin("Kode Pelanggan", "Nama Pelanggan", "Kode Menu", "Notelp Pelanggan", "Tipe Menu", "Nama Menu", "Harga Menu", JoinKuy, dataJoin);
                        printf("Table Join %s %s berhasil di tampilkan.\n\n", table, getcw());    
                    }
                    else // apabila belum EOP
                    {
                        // print error dikarenakan query masih berlebihan
                        displayError("7Q000", "Mohon maaf, Query yang diberikan tidak valid");   
                    }
                }
                else // apabila query berikutnya bukan nama tabel
                {   
                    if (strcmp(table, "pelanggan") == 0) // apabila tabel yang dituju adalah table pelanggan
                    {
                        query2 = BinarySearch(dataPelanggan, getcw(), Pelanggan); // mencari kode tersebut di dalam table
                    }
                    else if (strcmp(table, "menu") == 0) // apabila tabel yang dituju adalah table menu
                    {
                        query2 = BinarySearch(dataMenu, getcw(), Menu); // mencari kode tersebut di dalam table
                    }
                
                    if (query1 == 1 && query2 == 1) // apabila perintah 1 (TAMPIL) bisa dilaksanakan
                                                    // dan perintah 2 (ISI) tidak bisa dilaksanakan 
                    {
                        gotoEOP(pita);
                        ListData(pita); // maka lakukan TAMPIL data
                    }
                    else
                    {
                        // print error dikarenakan kedua perintah bisa dilaksanakan
                        displayError("1D000", "Query yang diberikan tidak valid, pastikan tidak ada 2 Perintah yang bisa dilaksanakan atau nama tabel kedua salah");
                    }
                }
            }
        }
        else // apabila table yang dituju tidak ada
        {
            // print error dikarenakan table yang dituju tidak valid
            displayError("1T000", "Table yang dituju tidak tersedia di database");
        }
    }
    else if (strcmp(getcw(), "UBAH") == 0 || strcmp(getcw(), "HAPUS") == 0)
    {
        inc(pita); // maju ke kata berikutnya
        // apabila cw adalah table pelanggan / menu
        if (strcmp(getcw(), "pelanggan") == 0 || strcmp(getcw(), "menu") == 0)
        {
            if (eop(pita) == 1) // apabila sudah di ujung pita / EOP
            {
                strcpy(table, getcw()); // copy cw ke dalam string table
                ListData(pita); // maka lakukan TAMPIL data
            }
            else
            {
                strcpy(table, getcw()); // copy cw ke dalam string table
                query1 = 1; // menandakan bahwa perintah 1 bisa dilaksanakan
                inc(pita); // maju ke kata berikutnya

                // apabila cw adalah nama table menu/pelanggan, maka di join
                if ( (strcmp(getcw(), "pelanggan") == 0 && (strcmp(table, "menu") == 0) ) || (strcmp(getcw(), "menu") == 0 && (strcmp(table, "pelanggan") == 0) ))
                {
                    if (eop(pita) == 1) // apabila sudah di ujung pita / EOP
                    {
                        // melakukan join table
                        joinData();
                        // menampilkan table yang sudah di join
                        BikinTableJoin("Kode Pelanggan", "Nama Pelanggan", "Kode Menu", "Notelp Pelanggan", "Tipe Menu", "Nama Menu", "Harga Menu", JoinKuy, dataJoin);
                        printf("Table Join %s %s berhasil di tampilkan.\n\n", table, getcw());    
                    }
                    else // apabila belum EOP
                    {
                        // print error dikarenakan query yang di input berlebihan
                        displayError("8Q000", "Mohon maaf, Query yang diberikan tidak valid");   
                    }
                }
                else // apabila cw selain nama table
                {   
                    if (strcmp(table, "pelanggan") == 0) // apabila tabel yang dituju adalah table pelanggan
                    {
                        query2 = BinarySearch(dataPelanggan, getcw(), Pelanggan); // mencari kode tersebut di dalam table
                    }
                    else if (strcmp(table, "menu") == 0) // apabila tabel yang dituju adalah table menu
                    {
                        query2 = BinarySearch(dataMenu, getcw(), Menu); // mencari kode tersebut di dalam table
                    }
                
                    if (query1 == 1 && query2 == 0) // apabila perintah 1 bisa dilaksanakan dan perintah 2 tidak bisa
                    {
                        ListData(pita); // maka lakukan TAMPIL data
                    }
                    else // apabila keduanya bisa
                    {
                        // print error dikarenakan kedua perintah bisa dilakukan
                        displayError("2D000", "Query yang diberikan tidak valid, pastikan tidak ada 2 Perintah yang bisa dilaksanakan atau nama tabel kedua salah");
                    }
                }
            }
        }
        else // apabila table yang dituju selain menu pelanggan
        {
            // print error dikarenakan table yang dituju tidak ada
            displayError("2T000", "Table yang dituju tidak tersedia di database");
        }
    }
    else if (strcmp(getcw(), "TAMPIL") == 0) // apabila query berikutnya adalah TAMPIL, maka menjadi TAMPIL TAMPIL
    {
        if (eop(pita) == 1) // apabila sudah di ujung pita / EOP
        {
            // print error dikarenakan query belum cukup untuk melakukan perintah
            displayError("9Q000", "Query yang diberikan tidak valid");
        }
        else
        {
            inc(pita); // maju ke kata berikutnya

            // apabila cw adalah table menu / pelanggan
            if (strcmp(getcw(), "pelanggan") == 0 || strcmp(getcw(), "menu") == 0)
            {
                strcpy(table, getcw()); // copy cw ke dalam string table
                ListData(pita); // maka lakukan TAMPIL data
            }
        }
    }
    else // apabila query kedua tidak valid
    {
        // print error dikarenakan query berikutnya tidak valid
        displayError("2Q000", "Query yang diberikan tidak valid");
    }
}

void readQuery(char pita[])
{
    query1 = 0; // reset menjadi 0
    query2 = 0; // reset menjadi 0
    kode = 0; // reset menjadi 0
    strcpy(table, "\0"); // reset menjadi null
    
    // memulai mesin kata
    start(pita);

    readFile("data/tMenu.dat", Menu); // membaca file Menu lalu dipindahkan ke array of struct Menu
    readFile("data/tPelanggan.dat", Pelanggan); // membaca file Pelanggan lalu dipindahkan ke array of struct Pelanggan
    sortData(dataPelanggan, Pelanggan); // melakukan sorting data Pelanggan
    sortData(dataMenu, Menu); // melakukan sorting data Menu

    if (eop(pita) == 1) // apabila sudah di ujung pita / EOP
    {
        // print error dikarenakan query yang dibutuhkan masih kurang untuk melakukan perintah
        displayError("0Q000", "Query masih kurang untuk melakukan perintah");
    }
    else // apabila bukan EOP
    {
        if (strcmp(getcw(), "ISI") == 0) // apabila query pertama adalah ISI
        {
            IsiQuery(pita); // maka melanjutkan ke proses ISI
        }
        else if (strcmp(getcw(), "UBAH") == 0) // apabila query pertama adalah UBAH
        {
            UbahQuery(pita); // maka melanjutkan ke proses UBAH
        }
        else if (strcmp(getcw(), "HAPUS") == 0) // apabila query pertama adalah HAPUS
        {
            HapusQuery(pita); // maka melanjutkan ke proses HAPUS
        }
        else if (strcmp(getcw(), "TAMPIL") == 0) // apabila query pertama adalah TAMPIL
        {
            TampilQuery(pita); // maka melanjutkan ke proses TAMPIL
        }
        else // apabila query pertama selain UBAH HAPUS TAMPIL ISI
        {
            // print error dikarenakan tidak valid
            displayError("1Q000", "Query awal yang diberikan tidak valid");
        }
    }
    
    writeFile(dataPelanggan, Pelanggan, "data/tPelanggan.dat"); // mencatat hasil dari proses query ke dalam file kembali
    writeFile(dataMenu, Menu, "data/tMenu.dat"); // mencatat hasil dari proses query ke dalam file kembali
}