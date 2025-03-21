#include <stdio.h>
int main() {
    int N;
    printf("Vvedyt kilkist elementyv masivy: ");
    scanf("%d", &N);
    double arr[N];
    printf("Vvedyt elementy masivy: \n");
    for (int i = 0; i < N; i += 1) {
        scanf("%lf", &arr[i]);
    }
    double max = arr[0];
    for (int i = 1; i < N; i += 1) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    double sum = 0;
    int foundPositive = 0;
    for (int i = 0; i < N; i += 1) {
        if (arr[i] > 0) {
            foundPositive = 1;
        }
        if (!foundPositive) {
            sum += arr[i];
        }
    }
    printf("Maksimalniy element masivy: %.2f\n", max);
    printf("Suma elementiv do ostannogo dodatnogo: %.2f\n", sum);
    getchar();
    getchar();
    return 0;
}
