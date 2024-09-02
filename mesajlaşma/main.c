#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESAJ_UZUNLUK 256

void mesaj_gonder();
void mesaj_al();

int main() {
    int secim;
    printf("Chat Uygulaması\n");
    printf("1. Mesaj Gönder\n");
    printf("2. Mesaj Al\n");
    printf("3. Çıkış\n");

    while (1) {
        printf("Bir seçenek girin (1/2/3): ");
        scanf("%d", &secim);
        getchar(); // Enter karakterini temizle

        switch (secim) {
            case 1:
                mesaj_gonder();
                break;
            case 2:
                mesaj_al();
                break;
            case 3:
                printf("Çıkılıyor...\n");
                exit(0);
            default:
                printf("Geçersiz seçenek. Lütfen tekrar deneyin.\n");
        }
    }

    return 0;
}

void mesaj_gonder() {
    char mesaj[MAX_MESAJ_UZUNLUK];
    FILE *dosya = fopen("mesaj.txt", "w");

    if (dosya == NULL) {
        printf("Mesaj dosyası açılamadı.\n");
        return;
    }

    printf("Göndermek istediğiniz mesajı girin:\n");
    fgets(mesaj, MAX_MESAJ_UZUNLUK, stdin);

    // Mesajı dosyaya yaz
    fprintf(dosya, "%s", mesaj);
    fclose(dosya);

    printf("Mesaj başarıyla gönderildi.\n");
}

void mesaj_al() {
    char mesaj[MAX_MESAJ_UZUNLUK];
    FILE *dosya = fopen("mesaj.txt", "r");

    if (dosya == NULL) {
        printf("Mesaj dosyası açılamadı.\n");
        return;
    }

    // Dosyadan mesajı oku
    if (fgets(mesaj, MAX_MESAJ_UZUNLUK, dosya) != NULL) {
        printf("Alınan mesaj:\n%s", mesaj);
    } else {
        printf("Mesaj bulunamadı.\n");
    }

    fclose(dosya);
}

