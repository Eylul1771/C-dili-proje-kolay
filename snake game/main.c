#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define GENISLIK 20
#define YUKSEKLİK 10

int x, y, meyveX, meyveY, skor;
int yilanX[100], yilanY[100];
int uzunluk;
enum yon { STOP = 0, SOL = 1, SAG = 2, YUKARI = 3, ASAGI = 4 };
enum yon yon;

void setup() {
    yon = STOP;
    x = GENISLIK / 2;
    y = YUKSEKLİK / 2;
    meyveX = rand() % GENISLIK;
    meyveY = rand() % YUKSEKLİK;
    skor = 0;
    uzunluk = 0;
}

void draw() {
    system("cls");
    for (int i = 0; i < GENISLIK + 2; i++)
        printf("#");
    printf("\n");

    for (int i = 0; i < YUKSEKLİK; i++) {
        for (int j = 0; j < GENISLIK; j++) {
            if (j == 0)
                printf("#");
            if (i == y && j == x)
                printf("O");
            else if (i == meyveY && j == meyveX)
                printf("F");
            else {
                int yaz = 0;
                for (int k = 0; k < uzunluk; k++) {
                    if (yilanX[k] == j && yilanY[k] == i) {
                        printf("o");
                        yaz = 1;
                    }
                }
                if (yaz == 0)
                    printf(" ");
            }
            if (j == GENISLIK - 1)
                printf("#");
        }
        printf("\n");
    }

    for (int i = 0; i < GENISLIK + 2; i++)
        printf("#");
    printf("\n");
    printf("Skor: %d\n", skor);
}

void input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a':
                yon = SOL;
                break;
            case 'd':
                yon = SAG;
                break;
            case 'w':
                yon = YUKARI;
                break;
            case 's':
                yon = ASAGI;
                break;
            case 'x':
                exit(0);
                break;
        }
    }
}

void logic() {
    int prevX = yilanX[0];
    int prevY = yilanY[0];
    int prev2X, prev2Y;
    yilanX[0] = x;
    yilanY[0] = y;

    for (int i = 1; i < uzunluk; i++) {
        prev2X = yilanX[i];
        prev2Y = yilanY[i];
        yilanX[i] = prevX;
        yilanY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (yon) {
        case SOL:
            x--;
            break;
        case SAG:
            x++;
            break;
        case YUKARI:
            y--;
            break;
        case ASAGI:
            y++;
            break;
        default:
            break;
    }

    if (x >= GENISLIK)
        x = 0;
    else if (x < 0)
        x = GENISLIK - 1;

    if (y >= YUKSEKLİK)
        y = 0;
    else if (y < 0)
        y = YUKSEKLİK - 1;

    for (int i = 0; i < uzunluk; i++) {
        if (yilanX[i] == x && yilanY[i] == y)
            exit(0);
    }

    if (x == meyveX && y == meyveY) {
        skor += 10;
        meyveX = rand() % GENISLIK;
        meyveY = rand() % YUKSEKLİK;
        uzunluk++;
    }
}

int main() {
    setup();
    while (1) {
        draw();
        input();
        logic();
        Sleep(0.01 * 1000);
    }
    return 0;
}

