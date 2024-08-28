

#include "input_output.h"
#include "solver.h"
#include <stdio.h>
#include <string.h>
#include "tests.h"

#define SOLVE 1
#define TEST  2

/**
 * @brief Main function
 *
 * This function call other functions (depending on mode), person chooses from command line which mode to use.
 * \param int (mode) and char
 */
int main(int argc, const char *argv[])

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
        {
            run_all_tests();
        }

        else
            puts("\033[31mERROR\033[0m: choose test or solve ");
    }
    else
            puts("\033[31mERROR\033[0m: choose test or solve ");

    tests();

    return 0;
}

