#include <stdio.h>
#define M 3
#define N 3
int main() {
    system("chcp 65001");
    int A[M][N] = {
        {1, -2, 3},
        {-4, 5, -6},
        {7, -8, 9}
    };
    int B[M][N] = {
        {-9, 8, -7},
        {6, -5, 4},
        {-3, 2, -1}
    };
    int C[M][N];
    for (int i = 0; i < M; i += 1) {
        for (int j = 0; j < N; j += 1) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    printf("Результат складання матриць A і B:\n");
    for (int i = 0; i < M; i += 1) {
        for (int j = 0; j < N; j += 1) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    int maxNegative = -100;
    int maxNegativeRow = -1;
    int maxNegativeCol = -1;
    for (int i = 0; i < M; i += 1) {
        for (int j = 0; j < N; j += 1) {
            if (C[i][j] < 0 && C[i][j] > maxNegative) {
                maxNegative = C[i][j];
                maxNegativeRow = i;
                maxNegativeCol = j;
            }
        }
    }
    if (maxNegative < 0) {
        printf("\nНайбільший від’ємний елемент: %d\n", maxNegative);
        printf("Індекс: (%d, %d)\n", maxNegativeRow + 1, maxNegativeCol + 1);
    }
    getchar();
    getchar();
    return 0;
}