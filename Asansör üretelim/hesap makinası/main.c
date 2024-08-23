//
//  main.c
//  hesap makinası
//
//  Created by Eylül Demirdağ on 23.08.2024.
#include <stdio.h>

int main() {
    int num1, num2;
    char operator;
    
    printf("İlk sayıyı girin: ");
    scanf("%d", &num1);
    
    printf("İkinci sayıyı girin: ");
    scanf("%d", &num2);
    
    printf("İşlem türünü girin (+, -, *, /): ");
    scanf(" %c", &operator);
    
    switch (operator) {
        case '+':
            printf("Sonuç: %d\n", num1 + num2);
            break;
        case '-':
            printf("Sonuç: %d\n", num1 - num2);
            break;
        case '*':
            printf("Sonuç: %d\n", num1 * num2);
            break;
        case '/':
            if (num2 != 0)
                printf("Sonuç: %f\n", (float)num1 / num2);
            else
                printf("Bölme hatası: Sıfıra bölme\n");
            break;
        default:
            printf("Geçersiz işlem türü\n");
    }
    
    return 0;
}
