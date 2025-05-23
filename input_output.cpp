#include <stdio.h>
#include <assert.h>
#include "input_output.h"
#include <string.h>

/**
 * \brief clears buffer after wrong input
 *
 * This function takes break code if assert is triggered, clears buffer via getchar
 */
void clear_buf()
{
    int symbol = getchar();

    assert (symbol != EOF);

    while(symbol != '\n') {
        if (symbol == EOF)
            break;
        symbol = getchar();
    }
}

/**
 * \brief select mode to run, default = solve
 *
 * This function selects mode entered from command line
 * \param int argc, char *argv
 */
enum Mode select_mode(int argc, const char *argv[])
{
    if (argc == 2)
    {
        if (strcmp(argv[1], "solve") == 0)
        {
            return SOLVE;
        }
        else if (!strcmp(argv[1], "test"))
        {
            return TEST;
        }

        else
        {
            puts("\033[31mERROR\033[0m: choose test or solve ");
            return ERROR;
        }
    }
    else
    {
        puts("\033[31mERROR\033[0m: choose test or solve ");
        return ERROR;
    }

}

/**
 * @brief Solve equation mode.
 *
 * This function solves equation and triggers print function.
 * Takes struct with coefficients and roots
 */
void solve_mode()
{
    puts("Enter a, b, c: ");
    Coeffs equ = {};
    input(&equ.a, &equ.b, &equ.c);
    Roots roots = solve_square(&equ);
    print_results(roots.nRoots, roots.x1, roots.x2);
}

/**
 * @brief Correct input.
 *
 * This function receive coefficients from terminal and checks if they are correct entered.
 * \param a, b, c - *doubles
 */

void input(double* a, double* b, double* c)
{
    while (scanf("%lf %lf %lf", a, b, c) != 3)
    {
        clear_buf();
        puts("Try again: ");
    }
}

/**
 * @brief Print results of equation.
 *
 * This function switches between cases (depends on quatity of roots).
 * \param struct of roots, double, double
 */

void print_results(RootQ nRoots, double x1, double x2)
{
    switch (nRoots)
    {
        case NO_ROOTS: puts("No roots\n");
            break;
        case ONE_ROOT: printf("x = %lf\n", x1);
            break;
        case TWO_ROOTS: printf("x1 = %lf, x2 = %lf\n", x1, x2);
            break;
        case INF_ROOTS: puts("infinity");
            break;
        default: printf("main(): ERROR: nRoots = %d\n", nRoots);
    }
}
