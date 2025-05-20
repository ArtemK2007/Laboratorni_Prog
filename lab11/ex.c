#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 15
#define M 10
//Генерація випадкових значень для матриці
void fillMatrix(int rows, int cols, int matrix[rows][cols], int min, int max) {
    for (int i = 0; i < rows; i += 1)
        for (int j = 0; j < cols; j += 1)
            matrix[i][j] = rand() % (max - min + 1) + min;
}
// Генерація випадкових значень для масиву
void fillArray(int size, int array[], int min, int max) {
    for (int i = 0; i < size; i += 1)
        array[i] = rand() % (max - min + 1) + min;
}
//Сума додатних елементів кожного рядка
void sumPositiveByRow(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i += 1) {
        int sum = 0;
        for (int j = 0; j < cols; j += 1) {
            if (matrix[i][j] > 0)
                sum += matrix[i][j];
        }
        printf("Сума додатніх елементів у рядку %d: %d\n", i, sum);
    }
}
//Кількість ненульових елементів
int countNonZero(int rows, int cols, int matrix[rows][cols]) {
    int count = 0;
    for (int i = 0; i < rows; i += 1)
        for (int j = 0; j < cols; j += 1)
            if (matrix[i][j] != 0)
                count += 1;
    return count;
}
//Сума елементів вище головної діагоналі
int sumAboveMainDiagonal(int size, int matrix[size][size]) {
    int sum = 0;
    for (int i = 0; i < size; i += 1)
        for (int j = i + 1; j < size; j += 1)
            sum += matrix[i][j];
    return sum;
}
//Сума елементів нижче головної діагоналі
int sumBelowMainDiagonal(int size, int matrix[size][size]) {
    int sum = 0;
    for (int i = 1; i < size; i += 1)
        for (int j = 0; j < i; j += 1)
            sum += matrix[i][j];
    return sum;
}
//Кількість від’ємних елементів до першого додатного
int countNegBeforeFirstPos(int array[], int size) {
    int count = 0;
    for (int i = 0; i < size; i += 1) {
        if (array[i] > 0)
            break;
        if (array[i] < 0)
            count += 1;
    }
    return count;
}
int main() {
    system("chcp 65001");
    srand(time(NULL));
    //Сума додатніх по рядках
    int a1[10][12], b1[15][10];
    fillMatrix(10, 12, a1, -10, 10);
    fillMatrix(15, 10, b1, -10, 10);
    printf("Матриця A(10x12):\n");
    sumPositiveByRow(10, 12, a1);
    printf("\nМатриця B(15x10):\n");
    sumPositiveByRow(15, 10, b1);
    //Кількість ненульових
    int a2[N][M], b2[M][N];
    fillMatrix(N, M, a2, -5, 5);
    fillMatrix(M, N, b2, -5, 5);
    int nonZeroA = countNonZero(N, M, a2);
    int nonZeroB = countNonZero(M, N, b2);
    printf("\nНенульові елементи в A(%dx%d): %d\n", N, M, nonZeroA);
    printf("Ненульові елементи в B(%dx%d): %d\n", M, N, nonZeroB);
    //Сума елементів над/під головною діагоналлю
    int a3[15][15], b3[20][20];
    fillMatrix(15, 15, a3, -10, 10);
    fillMatrix(20, 20, b3, -10, 10);
    int sumAboveA = sumAboveMainDiagonal(15, a3);
    int sumAboveB = sumAboveMainDiagonal(20, b3);
    int sumBelowA = sumBelowMainDiagonal(15, a3);
    int sumBelowB = sumBelowMainDiagonal(20, b3);
    printf("\nСума над головною діагоналлю A(15x15): %d\n", sumAboveA);
    printf("Сума під головною діагоналлю A(15x15): %d\n", sumBelowA);
    printf("Сума над головною діагоналлю B(20x20): %d\n", sumAboveB);
    printf("Сума під головною діагоналлю B(20x20): %d\n", sumBelowB);
    //Від’ємні до першого додатного
    int x[40], y[50], z[30];
    fillArray(40, x, -10, 10);
    fillArray(50, y, -10, 10);
    fillArray(30, z, -10, 10);
    int countX = countNegBeforeFirstPos(x, 40);
    int countY = countNegBeforeFirstPos(y, 50);
    int countZ = countNegBeforeFirstPos(z, 30);
    printf("\nВід’ємних до першого додатного в x: %d\n", countX);
    printf("Від’ємних до першого додатного в y: %d\n", countY);
    printf("Від’ємних до першого додатного в z: %d\n", countZ);
    getchar();
    getchar();
    return 0;
}
