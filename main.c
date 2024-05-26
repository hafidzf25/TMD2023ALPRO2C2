#include "header.h"

int main()
{
    // deklarasi pita
    char pita[201];
    
    // deklarasi indikator awal penentu loop
    int ind = 1;

    // membersihkan tampilan dan memberi judul pemanis
    system("cls");
    judul();

    // perulangan selama variabel ind masih 1
    while (ind == 1)
    {
        printf("dbms Abdul> "); // print biar keren
        scanf(" %200[^\n]s", &pita); // scan pita masukan

        if (strcmp(pita, "jangan lupa bahagia hari ini;") == 0 || strcmp(pita, "quit;") == 0) // apabila inputan pita adalah jangan lupa bahagia hari ini
        {
            printf("\nTerima kasih sudah menggunakan program ini!\nBismillah jadi asprak tahun 2023/2024\n"); // maka print ini (aamiin) dan keluar dari aplikasi
            ind = 0; // set menjadi 0 untuk memberhentikan aplikasi
        }
        else if (search_null(pita) == 1) // kondisi lain, apabila  ada simbol eop dalam pita
        {
            readQuery(pita); // jika ada, maka lanjut membaca query pita
        }
        else // jika tidak ada, error dan input ulang pita
        {
            displayError("1N000", "Tidak ada EOP pada masukan");
        }
    }
    
    return 0;
}