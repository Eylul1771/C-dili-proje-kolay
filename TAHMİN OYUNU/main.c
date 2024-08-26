#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int tahmin, rastgeleSayi, denemeSayisi = 0;
    int baslangic = 1, bitis = 100;

    srand(time(0));
    rastgeleSayi = (rand() % bitis) + baslangic;  // Rastgele sayı üretimi düzeltildi

    printf("1-100 arasında bir sayı tahmin edin lütfen.\n");

    do {
        printf("Tahmininiz: ");
        scanf("%d", &tahmin);
        denemeSayisi++;

        if (tahmin == rastgeleSayi) {
            printf("Doğru tahmin! %d denemede buldunuz.\n", denemeSayisi);
        } else if (tahmin < rastgeleSayi) {  // 'else if' bloğunda düzeltme yapıldı
            printf("Daha büyük bir sayı deneyin!\n");
        } else {
            printf("Daha küçük bir sayı deneyin!\n");
        }
    } while (tahmin != rastgeleSayi);

    return 0;
}

