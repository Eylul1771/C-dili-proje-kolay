#include <stdio.h>

// Kullanıcı bakiyesi global değişken olarak tanımlandı
double bakiye = 1000.0;  // Başlangıç bakiyesi 1000 TL

// Fonksiyon prototipleri
void bakiyeGoruntule();
void paraYatir();
void paraCek();

int main() {
    int secim;
    
    // ATM menüsü sürekli olarak gösterilir
    do {
        printf("\n--- ATM Menusu ---\n");
        printf("1. Bakiye Goruntule\n");
        printf("2. Para Yatir\n");
        printf("3. Para Cek\n");
        printf("4. Cikis Yap\n");
        printf("Seciminizi girin: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                bakiyeGoruntule();
                break;
            case 2:
                paraYatir();
                break;
            case 3:
                paraCek();
                break;
            case 4:
                printf("Cikis yapiliyor...\n");
                break;
            default:
                printf("Gecersiz secim! Lutfen tekrar deneyin.\n");
        }
    } while (secim != 4);  // Kullanıcı 4'e basana kadar menü devam eder.

    return 0;
}

// Fonksiyon: Bakiye Görüntüleme
void bakiyeGoruntule() {
    printf("\nMevcut Bakiyeniz: %.2f TL\n", bakiye);
}

// Fonksiyon: Para Yatırma
void paraYatir() {
    double miktar;
    printf("\nYatirmak istediginiz miktari girin: ");
    scanf("%lf", &miktar);

    if (miktar > 0) {
        bakiye += miktar;
        printf("%.2f TL basariyla yatirildi.\n", miktar);
    } else {
        printf("Gecersiz miktar! Lutfen tekrar deneyin.\n");
    }
}

// Fonksiyon: Para Çekme
void paraCek() {
    double miktar;
    printf("\nCekmek istediginiz miktari girin: ");
    scanf("%lf", &miktar);

    if (miktar > 0 && miktar <= bakiye) {
        bakiye -= miktar;
        printf("%.2f TL basariyla cekildi.\n", miktar);
    } else if (miktar > bakiye) {
        printf("Yetersiz bakiye! Mevcut bakiyeniz: %.2f TL\n", bakiye);
    } else {
        printf("Gecersiz miktar! Lutfen tekrar deneyin.\n");
    }
}

