#include "input_output.h"
#include "solver.h"
#include <stdio.h>
#include "tests.h"

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

    enum Mode mode = select_mode(argc, argv);

    if (mode == SOLVE)
    {
        solve_mode();
    }
    else if (mode == TEST)
    {
        tests();
        run_all_tests();
    }

    return 0;
}

