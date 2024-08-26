#include "tests.h"
#include <stdbool.h>
#include <stdio.h>

bool compare_struct(const Roots* test, const Roots* roots);


void run_test(const TestingData* test, size_t i_test)
{

    Roots roots_received = solve_square(&test->coeffs);
    if (compare_struct(&test->roots_exp, &roots_received))
    {
        printf("%lu%s", i_test, ". ");
        puts("\033[32mOKAY\033[0m");
    }
    else
    {
        printf("%lu", i_test);
        puts("\033[31mFAIL\033[0m");
    }
}

bool compare_struct(const Roots* test, const Roots* roots)
{
    if (compare_doubles(test->x1,roots->x1) && compare_doubles(test->x2, roots->x2))
        return true;
    else
        return false;
}


void run_all_tests() {
    const size_t nTests = 7;

    // {a, b, c}, {x1,x2,nRoots)
    TestingData tests[nTests] = {
        {{1, 2, 1}, {-1, -1, ONE_ROOT}},
        {{4, 5, 1}, {-1, -0.25, TWO_ROOTS}},
        {{0, 0, 0}, {0, 0, INF_ROOTS}},
        {{0.9, 0.101, -0.205}, {-0.536659, 0.424437, TWO_ROOTS}},
        {{4, 5, 6}, {0, 0, NO_ROOTS}},
        {{0.47, -0.5, 2}, {0, 0, NO_ROOTS}},
        {{1, 0, 4}, {0,0, NO_ROOTS}}
    };

    for (size_t i = 0; i < nTests; ++i) {
        run_test(&tests[i], i+1);
    }
}



