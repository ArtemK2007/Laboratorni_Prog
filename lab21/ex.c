#include <stdio.h>
int main() {
    system("chcp 65001");
    float a[3], b[3], dot_product = 0;
    printf("Введіть координати першого вектора (через пробіл): ");
    for (int i = 0; i < 3; i += 1) {
        scanf("%f", &a[i]);
    }
    printf("Введіть координати другого вектора (через пробіл): ");
    for (int i = 0; i < 3; i += 1) {
        scanf("%f", &b[i]);
    }
    for (int i = 0; i < 3;  i += 1) {
        dot_product += a[i] * b[i];
    }
    printf("Скалярний добуток векторів: %.2f\n", dot_product);
    getchar();
    getchar();
    return 0;
}
