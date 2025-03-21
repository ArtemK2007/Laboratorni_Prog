#include <stdio.h>
#include <limits.h>
int main() {
    int N;
    printf("Vvedyt kilkist zilych chisel: ");
    scanf("%d", &N);
    int MAS[N], sum = 0;
    long long prodOdd = 1;
    int countOdd = 0;
    int max = INT_MIN, maxIndex = -1;
    printf("Vvedit %d zilych chisel: ", N);
    for (int i = 0; i < N; i += 1) {
        scanf("%d", &MAS[i]);
    }
    for (int i = 0; i < N; i += 1) {
        if (MAS[i] % 2 == 0) {
            sum += MAS[i];
        } else {
            prodOdd *= MAS[i];
            countOdd++;
        }
        if (MAS[i] > max) {
            max = MAS[i];
            maxIndex = i;
        }
    }
    printf("Suma parnih chisel: %d\n", sum);
    if (countOdd > 0) {
        printf("Dobutok neparnykh chisel: %lld\n", prodOdd);
        printf("Maksymal'ne znachennya: %d, Yoho nomer: %d\n", max, maxIndex + 1);
    }
    getchar();
    getchar();
    return 0;
}
