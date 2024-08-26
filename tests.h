#ifndef TESTS_H
#define TESTS_H

#include "solver.h"

struct TestingData
{
    Coeffs coeffs;
    Roots roots_exp;
};

void run_all_tests();

#endif // TESTS_H
