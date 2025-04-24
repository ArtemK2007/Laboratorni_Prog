#include <stdio.h>
#include <locale.h>
#define SIZE 15
int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i += 1) {
        if (arr[i] == x) {
            return i + 1;
        }
    }
    return -1;
}
void sortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; i += 1) {
        for (int j = 0; j < n - i - 1; j += 1) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int binarySearchDesc(int arr[], int left, int right, int x) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == x) {
            return mid + 1;
        }
        if (arr[mid] < x) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}
int main() {
    system("chcp 65001");
    int X[SIZE] = {1, 5, 7, 12, 4, 6, 18, 11, 13, 10, 14, 9, 20, 17, 10};
    int A = 9;
    printf("Початковий масив X:\n");
    for (int i = 0; i < SIZE; i += 1) {
        printf("%d ", X[i]);
    }
    printf("\n");
    int resLinear = linearSearch(X, SIZE, A);
    if (resLinear != -1) {
        printf("Лінійний пошук: елемент %d знайдено на позиції %d\n", A, resLinear);
    } else {
        printf("Лінійний пошук: елемент %d не знайдено\n", A);
    }
    sortDescending(X, SIZE);
    printf("\nВідсортований масив (за спаданням):\n");
    for (int i = 0; i < SIZE; i += 1) {
        printf("%d ", X[i]);
    }
    printf("\n");
    int resBinary = binarySearchDesc(X, 0, SIZE - 1, A);
    if (resBinary != -1) {
        printf("Бінарний пошук: елемент %d знайдено на позиції %d\n", A, resBinary);
    } else {
        printf("Бінарний пошук: елемент %d не знайдено\n", A);
    }
    getchar();
    getchar();
    return 0;
}
