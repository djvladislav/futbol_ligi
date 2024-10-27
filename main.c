// Muhammet Berat Ak lig sistemi

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char ev_sahibi[20];
    char konuk[20];
    int ev_sahibi_gol;
    int konuk_gol;
    char tarih[20];
    int saat;
} Mac;

int main() {
    srand(time(NULL));
    
    printf("Kaç tane takim oluşturmak istiyorsunuz?\n");
    int takim_sayisi;
    scanf("%d", &takim_sayisi);  // girdi alip takim sayisini belirle
    

   
    if (takim_sayisi % 2 != 0) { // eger cift sayi takim olmazsa bay adli bir takim ekliyorum sonrasinda strcmp ile bay takimini gordugumde mac atlaniyor
        takim_sayisi++;
    }
    

    char takimlar[takim_sayisi][20]; // iki boyutlu dizi olusturup takimlarin isimlerini buraya atiyorum
    for (int i = 0; i < takim_sayisi; i++) {
        sprintf(takimlar[i], "%d. Takim", i + 1);
    }
    


    int mac_sayisi = (takim_sayisi - 1) * takim_sayisi;   // toplam mac sayisini hesapliyorum vs.
    Mac maclar[mac_sayisi];
    int mac_sayac = 0;
    int gun = 1;
    int ay = 1;
    int saat = 13;
    

    printf("Haftalik fiksturler\n");


    for (int hafta = 0; hafta < takim_sayisi - 1; hafta++) {

        printf("\n%d. Hafta oynanan maclar :\n", hafta + 1);
        printf("-------------------------\n");
        for (int i = 0; i < takim_sayisi / 2; i++) { // takimlarin kendi aralarinda oynadigi maclari yazdiriyorum fakat iki devreye boldugum icin bu yarisi yani 20 takim varsa 19 haftanın macını burda yazdırıyorum
            if (strcmp(takimlar[i], "Bay") != 0 && strcmp(takimlar[takim_sayisi - 1 - i], "Bay") != 0) { // bay kontrol
                sprintf(maclar[mac_sayac].ev_sahibi, "%s", takimlar[i]);
                sprintf(maclar[mac_sayac].konuk, "%s", takimlar[takim_sayisi - 1 - i]);

                maclar[mac_sayac].ev_sahibi_gol = rand() % 6;
                maclar[mac_sayac].konuk_gol = rand() % 6;
                sprintf(maclar[mac_sayac].tarih, "%02d.%02d.2024", gun, ay);
                maclar[mac_sayac].saat = saat;

                printf("Tarih : %s Saat : %d:00 / %s %d - %d %s /\n",maclar[mac_sayac].tarih, maclar[mac_sayac].saat,maclar[mac_sayac].ev_sahibi, maclar[mac_sayac].ev_sahibi_gol, maclar[mac_sayac].konuk_gol, maclar[mac_sayac].konuk);

                mac_sayac++;

                if (saat < 21) {
                    saat += 3;
                } else {
                    saat = 13;
                    gun++;
                    printf("\n");
                }

                if (gun > 30) {
                    gun = 1;
                    ay++;
                }
            }
        }

        char tut[20]; // Buranin amaci ise her takimin her hafta farkli takimlarla mac yapmasi burada bir bakima dizide kaydirma yapiyorum
        strcpy(tut, takimlar[takim_sayisi - 1]);
        for (int i = takim_sayisi - 1; i > 1; i--) {
            strcpy(takimlar[i], takimlar[i - 1]);
        }
        strcpy(takimlar[1], tut);
        saat = 13;
    }





    // burada ise ev sahibi ve deplasmani yer degistirerek iki takimin kendi aralrinda hem ev hem deplasmanda oynamasini sagliyorum
    for (int hafta = 0; hafta < takim_sayisi - 1; hafta++) {
        printf("\n%d. Hafta oynanan maclar :\n", hafta+takim_sayisi);
        printf("-------------------------\n");
        for (int i = 0; i < takim_sayisi / 2; i++) {
            if (strcmp(takimlar[i], "Bay") != 0 && strcmp(takimlar[takim_sayisi - 1 - i], "Bay") != 0) {
                sprintf(maclar[mac_sayac].ev_sahibi, "%s", takimlar[takim_sayisi - 1 - i]);
                sprintf(maclar[mac_sayac].konuk, "%s", takimlar[i]);

                maclar[mac_sayac].ev_sahibi_gol = rand() % 6;
                maclar[mac_sayac].konuk_gol = rand() % 6;
                sprintf(maclar[mac_sayac].tarih, "%02d.%02d.2024", gun, ay);
                maclar[mac_sayac].saat = saat;

                printf("Tarih : %s Saat : %d:00 / %s %d - %d %s /\n",
                       maclar[mac_sayac].tarih, maclar[mac_sayac].saat,
                       maclar[mac_sayac].ev_sahibi, maclar[mac_sayac].ev_sahibi_gol,
                       maclar[mac_sayac].konuk_gol, maclar[mac_sayac].konuk);

                mac_sayac++;

                if (saat < 21) {
                    saat += 3;
                } else {
                    saat = 13;
                    gun++;
                    printf("\n");
                }

                if (gun > 30) {
                    gun = 1;
                    ay++;
                }
            }
        }

        char tut[20];
        strcpy(tut, takimlar[takim_sayisi - 1]);
        for (int i = takim_sayisi - 1; i > 1; i--) {
            strcpy(takimlar[i], takimlar[i - 1]);
        }
        strcpy(takimlar[1], tut);
        saat = 13;
    }

    return 0;
}
