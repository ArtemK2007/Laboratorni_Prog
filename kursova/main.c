#include <stdio.h>
#include "input.h"
#include "calc.h"

int main() {
    system("chcp 65001");
    InputData data;
    int variant;
    printf("Введіть номер варіанту (1-3): ");
    scanf("%d", &variant);
    if (!load_input(&data, variant)) {
        printf("Помилка: невірний номер варіанту!\n");
        return 1;
    }
    calculate_and_save(&data);
    printf("Розрахунок завершено. Результати збережені в output.csv\n");
    getchar();
    getchar();
    return 0;
}