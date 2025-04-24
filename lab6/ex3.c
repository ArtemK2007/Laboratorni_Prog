#include <stdio.h>
#define M 3
#define N 3
int main() {
    system("chcp 65001");
    int A[M][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int B[M][N] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    int C[M][N];
    for (int i = 0; i < M; i += 1) {
        for (int j = 0; j < N; j += 1) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    printf("Матриця A:\n");
    for (int i = 0; i < M; i += 1) {
        for (int j = 0; j < N; j += 1) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("Матриця B:\n");
    for (int i = 0; i < M; i += 1) {
        for (int j = 0; j < N; j += 1) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
    printf("Матриця C:\n");
    for (int i = 0; i < M; i += 1) {
        for (int j = 0; j < N; j += 1) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    int rowSums[M];
    for (int i = 0; i < M; i += 1) {
        rowSums[i] = 0;
        for (int j = 0; j < N; j += 1) {
            rowSums[i] += C[i][j];
        }
    }
    int minRowIndex = 0;
    for (int i = 1; i < M; i += 1) {
        if (rowSums[i] < rowSums[minRowIndex]) {
            minRowIndex = i;
        }
    }
    printf("Рядок з мінімальною сумою: %d\n", minRowIndex + 1);
    printf("Сума цього рядка: %d\n", rowSums[minRowIndex]);
    printf("Елементи цього рядка: ");
    for (int j = 0; j < N; j += 1) {
        printf("%d ", C[minRowIndex][j]);
    }
    getchar();
    getchar();
    return 0;
}
