#include <stdio.h>
#include <math.h>
double g(double x) {
    return x + 1;
}
int main() {
    system("chcp 65001");
    int n, m;
    printf("Введіть кількість елементів масиву α (n): ");
    scanf("%d", &n);
    printf("Введіть кількість елементів масиву β (m): ");
    scanf("%d", &m);
    double a[n], b[m];
    printf("Введіть елементи масиву α:\n");
    for (int i = 0; i < n; i++) scanf("%lf", &a[i]);
    printf("Введіть елементи масиву β:\n");
    for (int i = 0; i < m; i++) scanf("%lf", &b[i]);
    double s = 0, p = 1;
    for (int i = 0; i < m; i++) {
        s += b[i];
        p *= b[i];
    }
    double A = s * s;
    for (int i = 0; i < n; i++) {
        A += a[i] * g(a[i]);
    }
    double B = 1;
    for (int i = 0; i < m; i++) {
        B *= a[i];
    }
    double C = s * s;
    for (int i = 0; i < n; i++) {
        C += sin(a[i]);
    }
    double F = 0;
    for (int i = 0; i < m; i++) {
        F += b[i] * fabs(b[i]);
    }
    double D = cos(B) + C;
    double E = D + sin(F);
    double alpha = D / E;
    printf("\nРезультати:\n");
    printf("α = %.5lf\n", alpha);
    printf("s = %.5lf\n", s);
    printf("p = %.5lf\n", p);
    getchar();
    getchar();
    return 0;
}
