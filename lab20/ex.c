#include <stdio.h>
#include <string.h>
#define SIZE 5
struct Student {
    char surname[50];
    char name[50];
    char group[20];
    float stipend;
};
void printStudents(struct Student students[], int count) {
    printf("\nОновлена база студентів:\n");
    for (int i = 0; i < count; i += 1) {
        printf("%s %s | Група: %s | Стипендія: %.2f грн\n",
               students[i].surname, students[i].name,
               students[i].group, students[i].stipend);
    }
}
int main() {
    system("chcp 65001");
    struct Student students[SIZE] = {
    {"Kriachko", "Artem", "KN-41", 1500},
    {"Horovyi", "Kyryl", "KN-41", 1700},
    {"Zelenskyi", "Volodymyr", "KN-42", 130000},
    {"Dzhо", "Baiden", "KN-43", 18000}
    };
    char searchSurname[50];
    int found = 0;
    printf("Введіть прізвище студента, якому хочете змінити стипендію: ");
    fgets(searchSurname, sizeof(searchSurname), stdin);
    searchSurname[strcspn(searchSurname, "\n")] = 0;
    for (int i = 0; i < SIZE; i += 1) {
        if (strcmp(students[i].surname, searchSurname) == 0) {
            printf("Поточна стипендія: %.2f грн\n", students[i].stipend);
            printf("Введіть нову стипендію: ");
            scanf("%f", &students[i].stipend);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Студента з прізвищем \"%s\" не знайдено.\n", searchSurname);
    }
    printStudents(students, SIZE);
    getchar();
    getchar();
    return 0;
}
