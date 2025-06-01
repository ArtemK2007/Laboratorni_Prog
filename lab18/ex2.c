#include <stdio.h>
#include <math.h>
int main() {
    system("chcp 65001");
    int n, m;
    printf("Введіть кількість елементів масиву z (n): ");
    scanf("%d", &n);
    printf("Введіть кількість елементів масиву β (m): ");
    scanf("%d", &m);
    double z[n], b[m];
    printf("Введіть елементи масиву z:\n");
    for (int i = 0; i < n; i++) scanf("%lf", &z[i]);
    printf("Введіть елементи масиву β:\n");
    for (int i = 0; i < m; i++) scanf("%lf", &b[i]);

    double s = 0, p = 1;
    for (int i = 0; i < n; i++) {
        s += z[i];
        p *= z[i];
    }
    double A = s * s;
    for (int i = 0; i < n; i++) A += exp(z[i]);
    double B = p * p;
    for (int i = 0; i < m; i++) B += z[i] * cos(z[i]);
    double C = p;
    for (int i = 0; i < n; i++) C += sin(z[i]);
    double D = 4 + sin(C);
    double F = 8 + cos(F);
    double omega = A + B * sin(C) / (D + cos(F));
    printf("Результати:\n");
    printf("ω = %.5lf\n", omega);
    printf("s = %.5lf\n", s);
    printf("p = %.5lf\n", p);
    getchar();
    getchar();
    return 0;
}
