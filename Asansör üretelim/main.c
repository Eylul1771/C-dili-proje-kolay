//
//
//  main.c
//  Asansör üretelim
//
//  Created by Eylül Demirdağ on 23.08.2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum Durum {
    DURUYOR, // 0
    YUKARI,  // 1
    ASAGI    // 2
} Durum; // Enum tipinin ismi Durum olarak belirlendi.

void DurumYazdir(Durum d) {
    switch (d) {
        case DURUYOR:
            printf("Asansör duruyor.\n");
            break;
        case YUKARI:
            printf("Asansör yukarı gidiyor.\n");
            break;
        case ASAGI:
            printf("Asansör aşağı gidiyor.\n");
            break;
        default:
            printf("Bilinmeyen durum.\n");
            break;
    }
}

int main() {
    Durum asansorDurumu = DURUYOR;
    char secim;

    // Başlangıç durumunu ekrana yazdır
    printf("Asansör durumu: ");
    DurumYazdir(asansorDurumu);

    while (1) {
        printf("Yönü değiştirmek ister misiniz? (y/n): ");
        scanf(" %c", &secim); // Kullanıcının seçim yapmasını sağlar

        if (secim == 'y' || secim == 'Y') {
            printf("Yeni durumu seçin:\n");
            printf("1. Yukarı\n");
            printf("2. Aşağı\n");
            printf("3. Duruyor\n");

            int secimDurumu;
            scanf("%d", &secimDurumu);

            switch (secimDurumu) {
                case 1:
                    asansorDurumu = YUKARI;
                    break;
                case 2:
                    asansorDurumu = ASAGI;
                    break;
                case 3:
                    asansorDurumu = DURUYOR;
                    break;
                default:
                    printf("Geçersiz seçim.\n");
                    continue; // Yanlış seçimde döngüyü başa sar
            }

            printf("Yeni durum: ");
            DurumYazdir(asansorDurumu);
        } else if (secim == 'n' || secim == 'N') {
            printf("Program sonlandırılıyor.\n");
            break; // Döngüden çık
        } else {
            printf("Geçersiz seçenek. Lütfen 'y' veya 'n' girin.\n");
        }
    }

    return 0;
}

