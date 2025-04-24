#include <stdio.h>
void inputArray(int arr[], int *size) {
    printf("Введіть кількість елементів масиву: ");
    scanf("%d", size);
    printf("Введіть елементи масиву:\n");
    for (int i = 0; i < *size; i += 1) {
        scanf("%d", &arr[i]);
    }
}
void analyzeArray(int arr[], int size, int lower, int upper) {
    int sum = 0;
    int count = 0;
    for (int i = 0; i < size; i += 1) {
        if (arr[i] >= lower && arr[i] <= upper) {
            sum += arr[i];
            count++;
        }
    }
    if (count > 0) {
        printf("Сума елементів в інтервалі [%d, %d]: %d\n", lower, upper, sum);
        printf("Середнє арифметичне: %.2f\n", (float)sum / count);
    } else {
        printf("Немає елементів в заданому інтервалі [%d, %d].\n", lower, upper);
    }
}
int main() {
    system("chcp 65001");
    int arr1[100], arr2[100], arr3[100];
    int size1, size2, size3;
    int lower, upper;
    printf("Для першого масиву:\n");
    inputArray(arr1, &size1);
    printf("Для другого масиву:\n");
    inputArray(arr2, &size2);
    printf("Для третього масиву:\n");
    inputArray(arr3, &size3);
    printf("Введіть межі інтервалу (нижня і верхня): ");
    scanf("%d %d", &lower, &upper);
    printf("\nАналіз першого масиву:\n");
    analyzeArray(arr1, size1, lower, upper);
    printf("\nАналіз другого масиву:\n");
    analyzeArray(arr2, size2, lower, upper);
    printf("\nАналіз третього масиву:\n");
    analyzeArray(arr3, size3, lower, upper);
    getchar();
    getchar();
    return 0;
}
