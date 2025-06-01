#include <stdio.h>
#include <math.h>
double g(double x) {
    return x * x + 1;
}
double f(double y) {
    return y + 1;
}
int main() {
    system("chcp 65001");
    int n, m;
    printf("Введіть кількість елементів масиву x (n): ");
    scanf("%d", &n);
    printf("Введіть кількість елементів масиву y (m): ");
    scanf("%d", &m);
    double x[n], y[m];
    printf("Введіть елементи масиву x:\n");
    for (int i = 0; i < n; i++) scanf("%lf", &x[i]);
    printf("Введіть елементи масиву y:\n");
    for (int i = 0; i < m; i++) scanf("%lf", &y[i]);
    double s = 0, p = 1;
    for (int i = 0; i < n; i++) {
        s += x[i];
        p *= x[i];
    }
    double A = s * s;
    for (int i = 0; i < n; i++) A += sin(x[i]);
    double B = p * p;
    for (int i = 0; i < m; i++) B += x[i] * cos(x[i]);
    double C = (s + p);
    for (int i = 0; i < m; i++) C += x[i] * g(x[i]);
    double D = 4 + 8 * cos(C);
    double E = 5 + sin(f(y[0]));
    double gamma = D / (D + E);
    printf("Результати:\n");
    printf("γ = %.5lf\n", gamma);
    printf("s = %.5lf\n", s);
    printf("p = %.5lf\n", p);
    getchar();
    getchar();
    return 0;
}