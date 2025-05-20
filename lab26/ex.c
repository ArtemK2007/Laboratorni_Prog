#include <stdio.h>
#include <stdlib.h>
void printMatrix(int **matrix, int n) {
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < n; j += 1) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}
int main() {
    system("chcp 65001");
    int n = 4;
    int k = 1;
    int **A = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i += 1) {
        A[i] = (int *)malloc(n * sizeof(int));
    }
    int data[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    for (int i = 0; i < n; i += 1)
        for (int j = 0; j < n; j += 1)
            A[i][j] = data[i][j];
    printf("Початкова матриця:\n");
    printMatrix(A, n);
    int sum = 0;
    for (int i = 0; i < n; i += 1)
        for (int j = 0; j < n; j += 1)
            if (i + j < n - 1)
                sum += A[i][j];
    printf("\nСума елементів над побічною діагоналлю: %d\n", sum);
    for (int i = 0; i < n; i += 1) {
        int temp = A[k][i];
        A[k][i] = A[i][k];
        A[i][k] = temp;
    }
    printf("\nПісля обміну рядка і стовпця з номером %d:\n", k);
    printMatrix(A, n);
    for (int i = 0; i < n; i += 1) {
        free(A[i]);
    }
    free(A);
    getchar();
    getchar();
    return 0;
}
