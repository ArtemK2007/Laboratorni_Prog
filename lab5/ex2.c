#include <stdio.h>
int main() {
    system("chcp 65001");
    int M = 3, N = 4;
    int C[3][4] = {
        {1, 7, 3, 2},
        {9, 4, 6, 0},
        {5, 8, 1, 3}
    };
    int B[3];
    printf("Матриця C:\n");
    for (int i = 0; i < M; i += 1) {
        for (int j = 0; j < N; j += 1) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < M; i += 1) {
        int max = C[i][0];
        for (int j = 1; j < N; j += 1) {
            if (C[i][j] > max) {
                max = C[i][j];
            }
        }
        B[i] = max;
    }
    printf("\nМасив B (максимальні елементи з кожного рядка):\n");
    for (int i = 0; i < M; i += 1) {
        printf("%d ", B[i]);
    }
    printf("\n");
    getchar();
    getchar();
    return 0;
}
