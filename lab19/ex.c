#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void inputArray(double arr[], int size, char name) {
    printf("Введіть %d елементів масиву %c:\n", size, name);
    for (int i = 0; i < size; i += 1) {
        printf("%c[%d] = ", name, i + 1);
        scanf("%lf", &arr[i]);
    }
}
void processAlpha(double alpha[], int n, double *A, double *B, double *C, double *s) {
    *s = 0;
    *A = 0;
    *B = 1;
    *C = 0;
    for (int i = 0; i < n; i += 1) {
        *s += alpha[i];
        *A += alpha[i] * tan(alpha[i]);
        *B *= alpha[i];
        *C += alpha[i] * sin(alpha[i]);
    }
    *A = (*s) * (*A);
    *C = (*s) * (*C);
}
void processBeta(double beta[], int m, double *D, double *E, double *F, double *s) {
    *s = 0;
    *D = 0;
    *E = 1;
    *F = 0;
    for (int i = 0; i < m; i += 1) {
        *s += beta[i];
        *D += beta[i] * cos(beta[i]);
        *E *= beta[i];
        *F += beta[i] * fabs(beta[i]);
    }
}
int main() {
    system("chcp 65001");
    int n, m;
    printf("Введіть кількість елементів масиву α (n): ");
    scanf("%d", &n);
    printf("Введіть кількість елементів масиву β (m): ");
    scanf("%d", &m);
    double *alpha = (double *)malloc(n * sizeof(double));
    double *beta = (double *)malloc(m * sizeof(double));
    inputArray(alpha, n, 'α');
    inputArray(beta, m, 'β');
    double A, B, C, s_alpha;
    double D, E, F, s_beta;
    processAlpha(alpha, n, &A, &B, &C, &s_alpha);
    processBeta(beta, m, &D, &E, &F, &s_beta);
    double omega = (A * cos(B) + C) / (D + E * sin(F));
    printf("\nРезультат ω = %.6lf\n", omega);
    free(alpha);
    free(beta);
    getchar();
    getchar();
    return 0;
}
