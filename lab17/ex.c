#include <stdio.h>
void findMax(double arr[], int size, double *maxValue, int *maxIndex) {
    *maxValue = arr[0];
    *maxIndex = 0;
    for (int i = 1; i < size; i += 1) {
        if (arr[i] > *maxValue) {
            *maxValue = arr[i];
            *maxIndex = i;
        }
    }
}
int main() {
    system("chcp 65001");
    int n, m;
    printf("Введіть розмір масиву x (менше 80): ");
    scanf("%d", &n);
    if (n <= 0 || n >= 80) {
        printf("Невірний розмір масиву x!\n");
        return 1;
    }
    printf("Введіть розмір масиву y (менше 70): ");
    scanf("%d", &m);
    if (m <= 0 || m >= 70) {
        printf("Невірний розмір масиву y!\n");
        return 1;
    }
    double x[n], y[m];
    printf("Введіть %d елементів масиву x:\n", n);
    for (int i = 0; i < n; i += 1) {
        scanf("%lf", &x[i]);
    }
    printf("Введіть %d елементів масиву y:\n", m);
    for (int i = 0; i < m; i += 1) {
        scanf("%lf", &y[i]);
    }
    double maxX, maxY;
    int indexX, indexY;
    findMax(x, n, &maxX, &indexX);
    findMax(y, m, &maxY, &indexY);
    printf("Найбільший елемент масиву x: %.2lf, індекс: %d\n", maxX, indexX);
    printf("Найбільший елемент масиву y: %.2lf, індекс: %d\n", maxY, indexY);
    getchar();
    getchar();
    return 0;
}
