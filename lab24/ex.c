#include <stdio.h>
#include <stdlib.h>
#define FILENAME "apartments.dat"
struct Apartment {
    char street[50];
    int houseNumber;
    int flatNumber;
    float price;
};
void writeToFile(struct Apartment *arr, int count) {
    FILE *file = fopen(FILENAME, "wb");
    if (file == NULL) {
        perror("Не вдалося відкрити файл для запису");
        exit(1);
    }
    fwrite(arr, sizeof(struct Apartment), count, file);
    fclose(file);
}
void readFromFile(struct Apartment *arr, int count) {
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL) {
        perror("Не вдалося відкрити файл для читання");
        exit(1);
    }
    fread(arr, sizeof(struct Apartment), count, file);
    fclose(file);
}
void updatePrices(struct Apartment *arr, int count) {
    for (int i = 0; i < count; i += 1) {
        printf("Стара ціна для квартири %d: %.2f\n", i + 1, arr[i].price);
        printf("Введіть нову ціну: ");
        scanf("%f", &arr[i].price);
    }
}
int main() {
    system("chcp 65001");
    int n;
    printf("Введіть кількість квартир: ");
    scanf("%d", &n);

    struct Apartment *apartments = (struct Apartment *)malloc(n * sizeof(struct Apartment));
    if (apartments == NULL) {
        perror("Помилка виділення пам'яті");
        return 1;
    }
    for (int i = 0; i < n; i += 1) {
        printf("Квартира %d:\n", i + 1);
        printf("Вулиця: ");
        scanf(" %[^\n]", apartments[i].street);
        printf("Номер будинку: ");
        scanf("%d", &apartments[i].houseNumber);
        printf("Номер квартири: ");
        scanf("%d", &apartments[i].flatNumber);
        printf("Вартість: ");
        scanf("%f", &apartments[i].price);
    }
    writeToFile(apartments, n);
    printf("Дані записано у файл '%s'.\n", FILENAME);
    // Оновлення цін
    updatePrices(apartments, n);
    // Перезапис у файл з новими цінами
    writeToFile(apartments, n);
    printf("Ціни оновлено у файлі '%s'.\n", FILENAME);
    free(apartments);
    getchar();
    getchar();
    return 0;
}
