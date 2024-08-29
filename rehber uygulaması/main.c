#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAKS_AD_UZUNLUK 100
#define MAKS_TEL_UZUNLUK 15

typedef struct Kisi {
    char ad[MAKS_AD_UZUNLUK];
    char telefon[MAKS_TEL_UZUNLUK];
    struct Kisi* sonraki; // Bağlantı için işaretçi
} Kisi;

Kisi* kisiEkle(Kisi* bas, const char* ad, const char* telefon) {
    Kisi* yeniKisi = (Kisi*)malloc(sizeof(Kisi));
    strncpy(yeniKisi->ad, ad, MAKS_AD_UZUNLUK);
    strncpy(yeniKisi->telefon, telefon, MAKS_TEL_UZUNLUK);
    yeniKisi->sonraki = bas;
    return yeniKisi;
}

Kisi* kisiSil(Kisi* bas, const char* ad) {
    Kisi* mevcut = bas;
    Kisi* onceki = NULL;
    
    while (mevcut != NULL && strcmp(mevcut->ad, ad) != 0) {
        onceki = mevcut;
        mevcut = mevcut->sonraki;
    }

    if (mevcut == NULL) {
        printf("Kişi bulunamadı.\n");
        return bas;
    }

    if (onceki == NULL) {
        Kisi* temp = bas;
        bas = bas->sonraki;
        free(temp);
    } else {
        onceki->sonraki = mevcut->sonraki;
        free(mevcut);
    }

    return bas;
}

void kisiGuncelle(Kisi* bas, const char* ad, const char* yeniTelefon) {
    Kisi* mevcut = bas;
    
    while (mevcut != NULL && strcmp(mevcut->ad, ad) != 0) {
        mevcut = mevcut->sonraki;
    }

    if (mevcut == NULL) {
        printf("Kişi bulunamadı.\n");
        return;
    }

    strncpy(mevcut->telefon, yeniTelefon, MAKS_TEL_UZUNLUK);
}

void kisiListele(Kisi* bas) {
    Kisi* mevcut = bas;
    
    while (mevcut != NULL) {
        printf("Ad: %s, Telefon: %s\n", mevcut->ad, mevcut->telefon);
        mevcut = mevcut->sonraki;
    }
}

int main() {
    Kisi* bas = NULL;
    int secim;
    char ad[MAKS_AD_UZUNLUK];
    char telefon[MAKS_TEL_UZUNLUK];
    
    while (1) {
        printf("1. Kişi Ekle\n");
        printf("2. Kişi Sil\n");
        printf("3. Kişi Güncelle\n");
        printf("4. Kişileri Listele\n");
        printf("5. Çıkış\n");
        printf("Seçiminizi yapın: ");
        scanf("%d", &secim);
        getchar(); // Yeni satırı temizle

        switch (secim) {
            case 1:
                printf("Ad: ");
                fgets(ad, MAKS_AD_UZUNLUK, stdin);
                ad[strcspn(ad, "\n")] = '\0'; // Yeni satırı temizle

                printf("Telefon: ");
                fgets(telefon, MAKS_TEL_UZUNLUK, stdin);
                telefon[strcspn(telefon, "\n")] = '\0'; // Yeni satırı temizle

                bas = kisiEkle(bas, ad, telefon);
                break;
            case 2:
                printf("Silinecek kişinin adı: ");
                fgets(ad, MAKS_AD_UZUNLUK, stdin);
                ad[strcspn(ad, "\n")] = '\0'; // Yeni satırı temizle

                bas = kisiSil(bas, ad);
                break;
            case 3:
                printf("Güncellenecek kişinin adı: ");
                fgets(ad, MAKS_AD_UZUNLUK, stdin);
                ad[strcspn(ad, "\n")] = '\0'; // Yeni satırı temizle

                printf("Yeni telefon numarası: ");
                fgets(telefon, MAKS_TEL_UZUNLUK, stdin);
                telefon[strcspn(telefon, "\n")] = '\0'; // Yeni satırı temizle

                kisiGuncelle(bas, ad, telefon);
                break;
            case 4:
                kisiListele(bas);
                break;
            case 5:
                while (bas != NULL) {
                    Kisi* temp = bas;
                    bas = bas->sonraki;
                    free(temp);
                }
                exit(0);
            default:
                printf("Geçersiz seçim, lütfen tekrar deneyin.\n");
                break;
        }
    }
    return 0;
}

