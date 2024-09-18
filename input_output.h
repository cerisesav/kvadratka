#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

#include "solver.h"

enum Mode {
    SOLVE = 1,
    TEST  = 2,
    ERROR = -1
};

void clear_buf();
void input(double* a, double* b, double* c);
void print_results(RootQ nRoots, double x1, double x2);
void solve_mode();
enum Mode select_mode(int argc, const char *argv[]);

#endif // INPUT_OUTPUT_H
