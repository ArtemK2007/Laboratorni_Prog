#include <stdio.h>
#define ROWS 3
#define COLS 4
int main() {
    system("chcp 65001");
    FILE *fin, *fout;
    int matrix[ROWS][COLS];
    int result[ROWS] = {0};
    fin = fopen("vhid.txt", "r");
    for (int i = 0; i < ROWS; i += 1) {
        for (int j = 0; j < COLS; j += 1) {
            fscanf(fin, "%d", &matrix[i][j]);
        }
    }
    fclose(fin);
    for (int i = 0; i < ROWS; i += 1) {
        for (int j = 0; j < COLS; j += 1) {
            if (matrix[i][j] < 0) {
                result[i] += matrix[i][j];
            }
        }
    }
    fout = fopen("exit.txt", "w");
    for (int i = 0; i < ROWS; i += 1) {
        fprintf(fout, "%d ", result[i]);
    }
    fclose(fout);
    getchar();
    getchar();
    return 0;
}
