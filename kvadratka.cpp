#include "input_output.h"
#include "solver.h"
#include <stdio.h>

// int testing_scr(struct TestingData);

int main()
{
    puts("# Square equation solver\n"
    "# (c) Vika, 2024\n\n");

    puts("Enter a, b, c: ");
    Coeffs equ = {};

    input(&equ.a, &equ.b, &equ.c);

    Roots roots = solve_square(&equ);
    print_results(roots.nRoots, roots.x1, roots.x2);
    return 0;
}




// int testing_scr(struct TestingData data)
// {
//     struct TestingData data = {.a = 1, .b = 0, .c = -4, .x1exp = -2, .x2exp = 2, .nTest = 1, .nRootsExp = 2}
//     int nRoots = solve_quare(data .a,data .b,data .c, &x1, &x2);
//     if (compare_doubles(nRoots, data .nRootsExp) != 1 || compare_doubles(x1,x1exp) != 1 || compare_doubles(x2,x2exp) != 1)
//     {
//         printf("ERROR Test 1: a = %lf, b = %lf, c = %lf, x1 = %lf, x2 = %lf\n"
//             "Expected nRoots: x1 = %lf, x2 = %lf, nRoots = %d\n",
//             nTest, a, b, c, x1, x2, nRoots,
//             x1exp, x2exp, nRootsExp);
//         return 1;
//     }
//     else
//         return 0;
// }

// struct TestingData
// {
//     double a, b, c;
//     double x1exp, x2exp;
//     int nTest, nRootsExp;
// };
