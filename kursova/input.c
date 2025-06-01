#include "input.h"
int load_input(InputData* data, int variant) {
    switch (variant) {
        case 1:
            *data = (InputData){600, 30, 200, 0.001, 0.001, 6.28e6, 0.001, 100e-12, 1e-3};
            return 1;
        case 2:
            *data = (InputData){600, 30, 300, 0.0015, 0.001, 3.14e6, 0.001, 200e-12, 1e-3};
            return 1;
        case 3:
            *data = (InputData){600, 30, 250, 0.0012, 0.001, 12.106e6, 0.001, 400e-12, 1e-3};
            return 1;
        default:
            return 0;
    }
}