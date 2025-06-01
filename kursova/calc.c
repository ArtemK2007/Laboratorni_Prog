#include <stdio.h>
#include <math.h>
#include "calc.h"
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
static double k_func(double t, const InputData* d) {
    if (t <= 3.0 * d->T / 4.0)
        return d->k0 * exp(t * M_PI / d->T);
    else
        return d->k0 * exp(M_PI * d->T / 4.0) * exp(-M_PI * (t - 3.0 * d->T / 4.0) / d->T);
}
static double omega_func(double t, const InputData* d) {
    if (t <= d->T / 4.0)
        return d->omega0 * (1 + d->n * t);
    else if (t <= 37.0 * d->T / 44.0)
        return d->omega0 * (1 + d->n * (d->T / 4.0));
    else
        return d->omega0 * (1 + d->n * (d->T / 4.0 - d->n * (t - 37.0 * d->T / 44.0)));
}
static double U_func(double t, const InputData* d) {
    double k = k_func(t, d);
    if (t <= d->T / 2.0)
        return d->U0 * (1 - exp(-k * t));
    else
        return d->U0 * (1 - exp(-k * d->T / 2.0)) * exp(-k * (t - d->T / 2.0));
}
void calculate_and_save(const InputData* d) {
    FILE* fout = fopen("output.csv", "w");
    if (!fout) return;
    fprintf(fout, "t,Ia\n");
    for (double t = 0; t <= d->T; t += d->dt) {
        double U = U_func(t, d);
        double omega = omega_func(t, d);
        double Ia = U * omega * d->c * d->tg_delta;
        fprintf(fout, "%.2f,%.8e\n", t, Ia);
    }
    fclose(fout);
}