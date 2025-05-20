#include <stdio.h>
#include <stdlib.h>
void inputArray(int *arr, int n, char name) {
    printf("Введіть елементи масиву %c:\n", name);
    for (int i = 0; i < n; i++) {
        printf("%c[%d] = ", name, i);
        scanf("%d", &arr[i]);
    }
}
int countNegatives(int *arr, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0)
            count++;
    }
    return count;
}
void printArray(int *arr, int n, char name) {
    printf("Масив %c: ", name);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    system("chcp 65001");
    int n;
    printf("Введіть розмір масивів: ");
    scanf("%d", &n);
    int *A = (int *)malloc(n * sizeof(int));
    int *B = (int *)malloc(n * sizeof(int));
    if (A == NULL || B == NULL) {
        perror("Помилка виділення пам’яті");
        return 1;
    }
    inputArray(A, n, 'A');
    inputArray(B, n, 'B');
    int negA = countNegatives(A, n);
    int negB = countNegatives(B, n);
    printf("Негативних у A: %d, у B: %d\n", negA, negB);
    free(A);
    free(B);
    getchar();
    getchar();
    return 0;
}
