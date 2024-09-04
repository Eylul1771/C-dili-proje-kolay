#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_TAS 106
#define PLAYER_TAS 14
#define TOTAL_PLAYERS 4

int taslar[TOTAL_TAS];
int oyuncular[TOTAL_PLAYERS][PLAYER_TAS];

void taslariOlustur();
void taslariDagit();
void eldekiTaslariGoster(int oyuncu);

int main() {
    srand(time(NULL));

    taslariOlustur();
    taslariDagit();

    for(int i = 0; i < TOTAL_PLAYERS; i++) {
        printf("Oyuncu %d'nin taslari:\n", i + 1);
        eldekiTaslariGoster(i);
        printf("\n");
    }

    return 0;
}

void taslariOlustur() {
    for(int i = 0; i < TOTAL_TAS; i++) {
        taslar[i] = i % 53;  // 53 sahte okeyi temsil eder
    }
}

void taslariDagit() {
    for(int i = 0; i < TOTAL_PLAYERS; i++) {
        for(int j = 0; j < PLAYER_TAS; j++) {
            int tasIndex = rand() % TOTAL_TAS;
            while(taslar[tasIndex] == -1) {
                tasIndex = rand() % TOTAL_TAS;
            }
            oyuncular[i][j] = taslar[tasIndex];
            taslar[tasIndex] = -1;
        }
    }
}

void eldekiTaslariGoster(int oyuncu) {
    for(int i = 0; i < PLAYER_TAS; i++) {
        printf("%d ", oyuncular[oyuncu][i]);
    }
    printf("\n");
}

