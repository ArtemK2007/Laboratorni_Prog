#include <stdio.h>
#include <string.h>
#define MAX_FLATS 5
#define MAX_STR_LEN 50
typedef struct {
    char street[MAX_STR_LEN];
    int house_number;
    int flat_number;
    double price;
} Apartment;
void toLowerStr(char *str) {
    for (int i = 0; str[i]; i += 1) {
        if (str[i] >= 'А' && str[i] <= 'Я') {
            str[i] = str[i] + ('а' - 'А');
        }
    }
}
int main() {
    system("chcp 65001");
    Apartment flats[MAX_FLATS] = {
    {"Shevchenka", 12, 34, 500000},
    {"Grushevskogo", 8, 12, 600000},
    {"Shevchenka", 15, 7, 750000},
    {"Kievska", 5, 2, 450000},
    {"Grushevskogo", 10, 5, 550000}
    };
    char street_input[MAX_STR_LEN];
    printf("Введіть назву вулиці: ");
    fgets(street_input, MAX_STR_LEN, stdin);
    street_input[strcspn(street_input, "\n")] = 0;

    int len = strlen(street_input);
    if (len > 0 && street_input[len - 1] == '\r') {
        street_input[len - 1] = 0;
    }
    toLowerStr(street_input);
    FILE *fout = fopen("result.txt", "w");
    if (fout == NULL) {
        printf("Не вдалося відкрити файл для запису.\n");
        return 1;
    }
    int found = 0;
    printf("Квартири на вулиці %s:\n", street_input);
    fprintf(fout, "Квартири на вулиці %s:\n", street_input);
    for (int i = 0; i < MAX_FLATS; i += 1) {
        char street_lower[MAX_STR_LEN];
        strcpy(street_lower, flats[i].street);
        toLowerStr(street_lower);
        if (strcmp(street_lower, street_input) == 0) {
            printf("Будинок %d, Квартира %d, Вартість %.2lf грн\n",
                   flats[i].house_number,
                   flats[i].flat_number,
                   flats[i].price);
            fprintf(fout, "Будинок %d, Квартира %d, Вартість %.2lf грн\n",
                    flats[i].house_number,
                    flats[i].flat_number,
                    flats[i].price);
            found = 1;
        }
    }
    if (!found) {
        printf("Квартир на цій вулиці не знайдено.\n");
        fprintf(fout, "Квартир на цій вулиці не знайдено.\n");
    }
    fclose(fout);
    getchar();
    getchar();
    return 0;
}
