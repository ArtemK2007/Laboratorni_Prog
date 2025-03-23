#include <stdio.h>
void smoothArray(int arr[], int n) {
    int temp[n];
    temp[0] = (arr[0] + arr[1]) / 2;
    temp[n - 1] = (arr[n - 2] + arr[n - 1]) / 2;
    for (int i = 1; i < n - 1; i += 1) {
        temp[i] = (arr[i - 1] + arr[i] + arr[i + 1]) / 3;
    }
    for (int i = 0; i < n; i += 1) {
        arr[i] = temp[i];
    }
}
int main() {
    system("chcp 65001");
    int n;
    printf("Введіть кількість елементів: ");
    scanf("%d", &n);
    int arr[n];
    printf("Введіть %d елементи: ", n);
    for (int i = 0; i < n; i += 1) {
        scanf("%d", &arr[i]);
    }
    smoothArray(arr, n);
    printf("Оновлений масив: ");
    for (int i = 0; i < n; i += 1) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    getchar();
    getchar();
    return 0;
}
