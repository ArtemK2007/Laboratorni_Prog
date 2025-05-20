#include <stdio.h>
#define SIZE 14
int main() {
    system("chcp 65001");
    int stack[SIZE];
    int top = -1; 
    printf("Введіть 14 чисел:\n");
    for (int i = 0; i < SIZE; i++) {
        int num;
        scanf("%d", &num);
        stack[++top] = num;
    }
    while (top >= 0 && stack[top] >= 0) {
        top--;
    }
    if (top >= 0 && stack[top] < 0) {
        top--;
    }
    printf("Стек після видалення елементів до першого від’ємного:\n");
    if (top == -1) {
        printf("Стек порожній\n");
    } else {
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
    getchar();
    getchar();
    return 0;
}
