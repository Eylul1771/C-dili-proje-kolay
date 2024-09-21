#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Rastgele sayı üretme fonksiyonu
void rastgeleSayiUret(char* dizi, int uzunluk) {
    for (int i = 0; i < uzunluk; i++) {
        dizi[i] = '0' + rand() % 10; // 0-9 arası rastgele bir rakam seçer ve diziye ekler
    }
    dizi[uzunluk] = '\0'; // Dizinin sonuna null karakter ekleyerek bitiriyoruz
}

int main() {
    srand(time(NULL)); // Rastgelelik için zaman tabanlı seed, her çalıştırmada farklı sayılar üretir

    int tur = 1;      // Oyunun kaçıncı turda olduğunu tutar
    int dogru = 1;    // Kullanıcının doğru cevabı verip vermediğini kontrol eden değişken
    char dogruSayi[100]; // Rastgele sayı dizisini tutan dizi
    char girilenSayi[100]; // Kullanıcının girdiği sayıyı tutan dizi

    printf("Hafiza Oyununa Hosgeldiniz!\n");

    // Oyun sonsuz bir döngüde çalışır ve kullanıcı yanlış cevap verene kadar devam eder
    while (dogru) {
        printf("\nTur %d\n", tur);

        // Her turda, tur numarasına göre daha uzun bir rastgele sayı üretiriz (örneğin: 1. turda 1 basamak, 2. turda 2 basamak)
        rastgeleSayiUret(dogruSayi, tur);

        // Rastgele üretilen sayıyı kullanıcıya gösteririz
        printf("Hatirlamaniz gereken sayi: %s\n", dogruSayi);

        // Kullanıcıya sayıyı hatırlayıp yazması için bir süre tanıyabiliriz (zaman gecikmesi)
        // Bu işlem sistemden sisteme farklı olabilir; basitçe bekletmek için bir süre ekleyebilirsin.

        // Kullanıcıdan sayıyı girmesini istiyoruz
        printf("Sayiyi tekrar girin: ");
        scanf("%s", girilenSayi); // Kullanıcının girdisini alıyoruz (bir dizi olarak)

        // Kullanıcının girdiği sayı ile rastgele ürettiğimiz sayı aynı mı diye kontrol ediyoruz
        if (strcmp(dogruSayi, girilenSayi) == 0) {
            // Eğer kullanıcı doğru girdiyse, sonraki tura geçeriz
            printf("Dogru! Sonraki tura geciyoruz.\n");
            tur++; // Tur sayısını artırır
        } else {
            // Eğer kullanıcı yanlış girdiyse, oyun biter
            printf("Yanlis! Oyun bitti.\n");
            printf("Toplam %d tur boyunca dogru cevap verdiniz.\n", tur - 1); // Kullanıcının toplam doğru turları
            dogru = 0; // Döngüyü bitirir
        }
    }

    return 0;
}

