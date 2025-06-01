#include <stdio.h>
int main() {
    system("chcp 65001");
    int n;
    int queue[100];
    int evenQueue[100], oddQueue[100];
    int evenCount = 0, oddCount = 0;
    printf("Введіть кількість елементів: ");
    scanf("%d", &n);
    printf("Введіть елементи:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            evenQueue[evenCount++] = queue[i]; // парна позиція
        } else {
            oddQueue[oddCount++] = queue[i];   // непарна позиція
        }
    }
    printf("Черга з парних позицій:\n");
    for (int i = 0; i < evenCount; i++) {
        printf("%d ", evenQueue[i]);
    }
    printf("\n");
    printf("Черга з непарних позицій:\n");
    for (int i = 0; i < oddCount; i++) {
        printf("%d ", oddQueue[i]);
    }
    printf("\n");
    getchar();
    getchar();
    return 0;
}
