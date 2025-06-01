#include <stdio.h>
#include <string.h>
#define MAX_SHOES 5
#define MAX_STR_LEN 50
typedef struct {
    char name[MAX_STR_LEN];
    int size;
    char color[MAX_STR_LEN];
    float price;
} Shoe;
void writeFilteredShoesToFile(Shoe shoes[], int n, const char* nameFilter, float maxPrice, const char* filename);
int main() {
    system("chcp 65001");
    Shoe shoes[MAX_SHOES] = {
        {"Nike", 42, "Red", 1200.0},
        {"Adidas", 44, "Black", 1500.0},
        {"Puma", 40, "Blue", 900.0},
        {"New Balance", 43, "White", 1100.0},
        {"Fila", 41, "Brown", 700.0}
    };
    char nameFilter[MAX_STR_LEN];
    float maxPrice;
    printf("Введіть назву взуття для пошуку: ");
    fgets(nameFilter, MAX_STR_LEN, stdin);
    nameFilter[strcspn(nameFilter, "\n")] = 0;
    printf("Введіть максимальну ціну: ");
    scanf("%f", &maxPrice);
    writeFilteredShoesToFile(shoes, MAX_SHOES, nameFilter, maxPrice, "filtered_shoes.txt");
    printf("Дані записано у файл 'filtered_shoes.txt'\n");
    getchar();
    getchar();
    return 0;
}
void writeFilteredShoesToFile(Shoe shoes[], int n, const char* nameFilter, float maxPrice, const char* filename) {
    FILE* f = fopen(filename, "w");
    if (!f) {
        perror("Помилка відкриття файлу");
        return;
    }
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(shoes[i].name, nameFilter) == 0 && shoes[i].price <= maxPrice) {
            fprintf(f, "Назва: %s\n", shoes[i].name);
            fprintf(f, "Розмір: %d\n", shoes[i].size);
            fprintf(f, "Колір: %s\n", shoes[i].color);
            fprintf(f, "Ціна: %.2f\n", shoes[i].price);
            fprintf(f, "-----------------------\n");
            found = 1;
        }
    }
    if (!found) {
        fprintf(f, "Взуття з назвою '%s' та ціною не дорожче %.2f не знайдено.\n", nameFilter, maxPrice);
    }
    fclose(f);
}
