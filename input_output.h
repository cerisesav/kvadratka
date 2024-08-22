#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

#include "solver.h"

void clear_buf();
void input(double* a, double* b, double* c);
void get_results(enum RootQ nRoots, double x1, double x2);

#endif // INPUT_OUTPUT_H
