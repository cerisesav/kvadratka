#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "tests.h"


bool compare_struct(const Roots* test, const Roots* roots);

/**
 * @brief run tests from struct.
 *
 * This function runs tests which are described in struct and prints if test was passed
 * \param struct of test, size_t counter of test
 *
 */
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
        printf("%lu%s", i_test, ". ");
        puts("\033[31mFAIL\033[0m");
    }
}
/**
 * @brief Compare structures.
 *
 * This function compares structures (results of test and expected roots)
 * \param struct, struct - roots from unit-test, roots from person
 * \return bool (equal or not)
 */
bool compare_struct(const Roots* test, const Roots* roots)
{
    if (compare_doubles(test->x1,roots->x1) && compare_doubles(test->x2, roots->x2))
        return true;
    else
        return false;
}

/**
 * @brief list tests.
 *
 * This function includes tests within 2 structures: struct of coefficients and struct with expected roots and numbers of roots
 * example: // {a, b, c}, {x1,x2,nRoots), quantity of tests is already known in the first line
 */
void run_all_tests() {
    const size_t nTests = 7;
    TestingData tests[nTests] = {
        {{1, 2, 1}, {-1, -1, ONE_ROOT}}, //
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

void tests()
{
    FILE *file;

    file = fopen("tests.txt", "r");

    int len_arr = 0;

    int successful_read = fscanf(file, "%d", &len_arr);

    struct TestingData* tests = (struct TestingData*)calloc(len_arr, sizeof(*tests));

    if (tests == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
    }

    while (fscanf() != 6)

    printf("%d", successful_read);

    fclose(file);
}


