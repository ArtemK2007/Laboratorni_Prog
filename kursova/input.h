#ifndef INPUT_H
#define INPUT_H

typedef struct {
    double T, dt, U0, k0, m, omega0, n, c, tg_delta;
} InputData;

int load_input(InputData* data, int variant);

#endif