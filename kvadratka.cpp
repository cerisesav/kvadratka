

#include "input_output.h"
#include "solver.h"
#include <stdio.h>
#include <string.h>
#include "tests.h"

#define SOLVE 1
#define TEST  2

int main(int argc, char *argv[])

{
    puts("# Square equation solver\n"
    "# (c) Vika, 2024\n\n");

    if (argc == 2)
    {
        if (strcmp(argv[1], "solve") == 0)
        {
            solve_mode();
        }
        else if (!strcmp(argv[1], "test"))
            run_all_tests();

        else
            puts("\033[31mERROR\033[0m: choose test or solve ");
    }
    else
            puts("\033[31mERROR\033[0m: choose test or solve ");

    return 0;
}

