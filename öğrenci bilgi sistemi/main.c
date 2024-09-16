#include <stdio.h>

struct Student {
    char name[50];
    int roll;
    float marks;
};

int main() {
    struct Student student;

    printf("Öğrencinin ismini girin: ");
    scanf("%s", student.name);

    printf("Öğrencinin numarasını girin: ");
    scanf("%d", &student.roll);

    printf("Öğrencinin notunu girin: ");
    scanf("%f", &student.marks);

    printf("\nÖğrenci Bilgileri:\n");
    printf("İsim: %s\n", student.name);
    printf("Numara: %d\n", student.roll);
    printf("Not: %.2f\n", student.marks);

    return 0;
}

