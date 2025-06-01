#include <stdio.h>
#include <conio.h>
int main() {
    system("chcp 65001");
    float x, y;
    float *x_ptr, *y_ptr;
    x_ptr = &x;
    *x_ptr = 5;
    y_ptr = x_ptr;
    y = *y_ptr / 2 + *x_ptr;
    y_ptr = &y;
    printf("x = %f, y = %f\n", x, y);
    printf("Адреса x = %p, y = %p\n", &x, &y);
    printf("x_ptr = %p, y_ptr = %p\n", x_ptr, y_ptr);
    printf("*x_ptr = %f, *y_ptr = %f\n", *x_ptr, *y_ptr);
    printf("Адреса x_ptr = %p, y_ptr = %p\n", &x_ptr, &y_ptr);
    getchar();
    getchar();
    return 0;
}