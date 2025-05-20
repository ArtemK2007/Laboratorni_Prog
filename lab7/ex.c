#include <stdio.h>
#include "distance.h"
int main() {
    system("chcp 65001");
    int N;
    printf("Введіть кількість точок: ");
    scanf("%d", &N);
    if (N < 2) {
        printf("Має бути щонайменше 2 точки.\n");
        return 1;
    }
    Point points[N];
    for (int i = 0; i < N; i += 1) {
        printf("Точка %d (x y): ", i + 1);
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }
    printf("\n Відстань між сусідніми точками:\n");
    for (int i = 0; i < N - 1; i += 1) {
        double d = distance(points[i], points[i + 1]);
        printf("Між точками %d і %d: %.3f\n", i + 1, i + 2, d);
    }
    getchar();
    getchar();
    return 0;
}
