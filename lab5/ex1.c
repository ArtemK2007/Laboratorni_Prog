#include <stdio.h>
int main() {
    system("chcp 65001");
    int N = 3;
    double A[3][3] = {
        {1, -1, 3},
        {-2, 4, 1},
        {-1, 1, 2}
    };
    printf("Матриця A:\n");
    for (int i = 0; i < 3; i += 1) {
        for (int j = 0; j < 3; j += 1) {
            printf("%2.f ", A[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < N; i += 1) {
        int positiveCount = 0;
        for (int j = 0; j < N; j += 1) {
            if (A[i][j] > 0) {
                positiveCount++;
            }
        }
        printf("Рядок %d містить %d додатних елементів.\n", i + 1, positiveCount);
    }
    getchar();
    getchar();
    return 0;
}
