#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
system("chcp 65001");
    int n;
    double a;
    printf("Введіть розмір масивів n: ");
    scanf("%d", &n);
    printf("Введіть число A: ");
    scanf("%lf", &a);
    double x[n];
    double y[n];
    printf("Введіть елементи масиву X:\n");
    for (int i = 0; i < n; i += 1) {
        printf("x[%d] = ", i);
        scanf("%lf", &x[i]);
    }
    printf("Введіть елементи масиву Y:\n");
    for (int i = 0; i < n; i += 1) {
        printf("y[%d] = ", i);
        scanf("%lf", &y[i]);
    }
    double z[n];
    int z_count = 0;
    printf("\nЕлементи, для яких |x_i - y_i| < %.2lf:\n", a);

    for (int i = 0; i < n; i += 1) {
        if (fabs(x[i] - y[i]) < a) {
            printf("Елемент з номером %d: |%.2lf - %.2lf| = %.2lf\n", i + 1, x[i], y[i], fabs(x[i] - y[i]));
            z[z_count] = x[i] - y[i];
            z_count++;
        }
    }
    if (z_count > 0) {
        printf("\nМасив Z (різниці елементів): ");
        for (int i = 0; i < z_count; i += 1) {
            printf("%.2lf ", z[i]);
        }
        printf("\n");
    } 
    getchar();
    getchar();
    return 0; 
<<<<<<< HEAD
}
=======
}
>>>>>>> 08709d219dd762d3a88ef1b34c801be34e55447e
