////  main.c
//  not defteri
//
//  Created by Eylül Demirdağ on 23.08.2024.

#include <stdio.h>

int main() {
    FILE *file;
    char content[256];

    // Dosyaya yazma
    file = fopen("not_defteri.txt", "w");
    if (file == NULL) {
        printf("Dosya açılamadı!\n");
        return 1;
    }

    printf("Metni girin (Çıkmak için CTRL+D):\n");
    while (fgets(content, sizeof(content), stdin) != NULL) {
        fputs(content, file);
    }
    fclose(file);

    // Dosyayı okuma
    file = fopen("not_defteri.txt", "r");
    if (file == NULL) {
        printf("Dosya açılamadı!\n");
        return 1;
    }

    printf("\nDosya İçeriği:\n");
    while (fgets(content, sizeof(content), file) != NULL) {
        printf("%s", content);
    }
    fclose(file);

    return 0;
}
