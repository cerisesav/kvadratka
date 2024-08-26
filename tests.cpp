#include "tests.h"
#include <stdbool.h>
#include <stdio.h>

bool compare_struct(const Roots* test, const Roots* roots);


void run_test(const TestingData* test)
{
    Roots roots_received = solve_square(&test->coeffs);
    if (compare_struct(&test->roots_exp, &roots_received))
        puts("OKAY");
    else
        puts("FAIL");
}

bool compare_struct(const Roots* test, const Roots* roots)
{
    if (compare_doubles(test->x1,roots->x1) && compare_doubles(test->x2, roots->x2))
        return true;
    else
        return false;
}


void run_all_tests() {
    const size_t nTests = 3;
    TestingData tests[nTests] = {
        {{1, 2, 1}, {-1, -1, ONE_ROOT}}, // {a, b, c}, {x1,x2,nRoots)
        {{4, 5, 1}, {-1, -0.25, TWO_ROOTS}},
        {{0, 0, 0}, {-1, -1, INF_ROOTS}}
    };

    for (size_t i = 0; i < nTests; ++i) {
        run_test(&tests[i]);
    }
}



