#include <stdio.h>
#include <string.h>
int countSubstringOccurrences(const char *s1, const char *s2) {
    int count = 0;
    const char *p = s1;
    while ((p = strstr(p, s2)) != NULL) {
        count++;
        p += 1;
    }

    return count;
}
int main() {
    system("chcp 65001");
    char s1[1000], s2[100];
    printf("Введіть рядок S1: ");
    fgets(s1, sizeof(s1), stdin);
    s1[strcspn(s1, "\n")] = '\0'; 
    printf("Введіть підрядок S2: ");
    fgets(s2, sizeof(s2), stdin);
    s2[strcspn(s2, "\n")] = '\0';
    int result = countSubstringOccurrences(s1, s2);
    printf("Кількість входжень підрядка: %d\n", result);
    getchar();
    getchar();
    return 0;
}
