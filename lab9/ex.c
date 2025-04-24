#include <stdio.h>
#include <math.h>
#define N 5
int main() {
    system("chcp 65001");
    printf("Задані масиви P[N] і Q[N] (%d елементів).\n", N);
    printf("Потрібно побудувати масив Z[N], де:\n");
    printf("- Якщо дискримінант D = P[i]^2 - 4*Q[i] >= 0, то Z[i] дорівнює меншому кореню рівняння Z^2 + P[i]*Z + Q[i] = 0\n");
    printf("P[N] = {2, 4, -3, 1, 0}\n");
    printf("Q[N] = {1, 5, 2, -6, 1}\n");
    float P[N] = {2, 4, -3, 1, 0};
    float Q[N] = {1, 5, 2, -6, 1};
    float Z[N];
    for (int i = 0; i < N; i += 1) {
        float D = P[i]*P[i] - 4*Q[i];
        if (D >= 0) {
            Z[i] = (-P[i] - sqrt(D)) / 2;
        } else {
            Z[i] = 1e38;
        }
    }
    printf("Масив Z:\n");
    for (int i = 0; i < N; i += 1) {
        printf("Z[%d] = %.2e\n", i, Z[i]);
    }
    getchar();
    getchar();
    return 0;
}
