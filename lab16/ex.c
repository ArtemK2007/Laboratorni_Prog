#include <stdio.h>
#include <stdlib.h>
void reverseArray(double *arr, int n) {
    double *start = arr;
    double *end = arr + n - 1;
    while (start < end) {
        double temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}
void printArray(double *arr, int n) {
    for (int i = 0; i < n; i += 1) {
        printf("%.2lf ", *(arr + i));
    }
    printf("\n");
}
int main() {
    system("chcp 65001");
    int n;
    printf("Введіть кількість елементів масиву: ");
    scanf("%d", &n);
    double *array = (double *)malloc(n * sizeof(double));
    printf("Введіть %d елементів:\n", n);
    for (int i = 0; i < n; i += 1) {
        scanf("%lf", array + i);
    }
    printf("Оригінальний масив:\n");
    printArray(array, n);
    reverseArray(array, n);
    printf("Масив у зворотному порядку:\n");
    printArray(array, n);
    free(array);
    getchar();
    getchar();
    return 0;
}
