#include <stdio.h>
#include <stdlib.h>
int main() {
    system("chcp 65001");
    int arr[10];       
    int *p, *p_max;      
    int i, n;           
    printf("n = ");    
    scanf("%d", &n);  
    printf("Введіть %d елементів:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]); 
    }
    p_max = arr;
    for (p = arr + 1; p < arr + n; p++) {
        if (*p > *p_max) {
            p_max = p;   
        }
    }
    printf("Максимальний елемент = %d\n", *p_max); 
    printf("Його номер = %d\n", (int)(p_max - arr + 1));
    getchar();
    getchar();
    return 0;
}
