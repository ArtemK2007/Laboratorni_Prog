#include <stdio.h>
#include <stdlib.h>
#define N 5
int main() {
    system("chcp 65001");
    int s[N][N] = {
        {1, 0, 3, 4, 5},
        {6, 7, 8, 0, 10},
        {11, 12, 13, 14, 0},
        {16, 0, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    printf("Початкова матриця:\n");
    for (int i = 0; i < N; i += 1) {
        for (int j = 0; j < N; j += 1) {
            printf("%d\t", s[i][j]);
        }
        printf("\n");
    }
    for (int j = 0; j < N; j += 1) {
        int max_col = s[0][j];
        for (int i = 1; i < N; i += 1) {
            if (s[i][j] > max_col) {
                max_col = s[i][j];
            }
        }
        for (int i = 0; i < N; i += 1) {
            if (s[i][j] == 0) {
                s[i][j] = max_col;
            }
        }
    }
    printf("\nЗмінена матриця:\n");
    for (int i = 0; i < N; i += 1) {
        for (int j = 0; j < N; j += 1) {
            printf("%d\t", s[i][j]);
        }
        printf("\n");
    }
    getchar();
    getchar();
    return 0;
}