#include "tests.h"

void run_test(const TestingData* test)
{
    Roots roots_received = solve_square(&test->coeffs);
    if (compare_struct(&test->roots_exp, &roots_received)
        puts("OKAY");
}

bool compare_struct(const Roots* test, const Roots* roots)
{
    if (test->x1 == roots->x1 && test->x2 == roots->x2)
        return true;
    else
        return false;
}


void run_all_tests()
{
    const int nTests = 10;
    TestingData tests[nTests] = {
    {{1,2,1},{-1,-1,1}},
    {{4,5,1},{-1,-0.25,2}}
    }
}
