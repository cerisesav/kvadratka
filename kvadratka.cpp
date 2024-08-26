#include "input_output.h"
#include "solver.h"
#include <stdio.h>
#include "tests.h"

int main()
{
    puts("# Square equation solver\n"
    "# (c) Vika, 2024\n\n");

    puts("Enter a, b, c: ");
    Coeffs equ = {};

    input(&equ.a, &equ.b, &equ.c);

    Roots roots = solve_square(&equ);
    print_results(roots.nRoots, roots.x1, roots.x2);
    printf("%d %d", roots.x1, roots.x2);
    run_all_tests();

    return 0;
}

