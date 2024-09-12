#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rastgeleSayi, tahmin, deneme = 0;
    
    // Rastgele sayılar üretmek için kullanılan fonksiyon
    srand(time(0)); // Rastgele sayılar her çalıştırmada farklı olsun diye seed olarak zaman kullanılıyor
    rastgeleSayi = rand() % 100 + 1; // 1 ile 100 arasında bir rastgele sayı üret
    
    printf("Tahmin oyununa hosgeldiniz!\n");
    printf("1 ile 100 arasinda bir sayi tuttum. Bakalim bulabilecek misiniz?\n");

    // Kullanıcı doğru tahmini yapana kadar döngü devam eder
    do {
        printf("Tahmininiz: ");
        scanf("%d", &tahmin); // Kullanıcıdan tahmin al
        
        deneme++; // Her tahminde deneme sayısı arttırılır
        
        if(tahmin > rastgeleSayi) {
            printf("Daha kucuk bir sayi girin.\n");
        } else if(tahmin < rastgeleSayi) {
            printf("Daha buyuk bir sayi girin.\n");
        } else {
            printf("Tebrikler! %d. denemede dogru tahmini yaptiniz!\n", deneme);
        }
    } while(tahmin != rastgeleSayi); // Doğru sayı bulunana kadar döngü devam eder
    
    return 0;
}

