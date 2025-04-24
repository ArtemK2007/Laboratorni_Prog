#include <stdio.h>
double recursiveSum(int n) {
    if (n == 0) {
        return 0;
    } else {
        return recursiveSum(n - 1) + (double)(2 * n - 1) / n;
    }
}
int main() {
    system("chcp 65001");
    int n;
    printf("Введіть значення n: ");
    scanf("%d", &n);
    double sum = recursiveSum(n);
    printf("Сума s дорівнює: %lf\n", sum);
    getchar();
    getchar();
    return 0;
}