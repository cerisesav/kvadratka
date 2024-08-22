#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#include "input_output.h"
#include "solver.h"

// #include <TXLib.h>

// int testing_scr(struct TestingData);

void clear_buf();
int compare_doubles(double a, double b);
void input(double* a, double* b, double* c);

enum RootQ solve_quare(double a, double b, double c, double* x1, double* x2);
void get_results(enum RootQ nRoots, double x1, double x2);
enum RootQ lineal_eq(double a, double b, double c, double* x1, double* x2);
enum RootQ square_eq(double a, double b, double c, double* x1, double* x2);

struct TestingData
{
    double a, b, c;
    double x1exp, x2exp;
    int nTest, nRootsExp;
};

int main()
{
    puts("# Square equation solver\n"
    "# (c) Vika, 2024\n\n");

    puts("Enter a, b, c: ");
    double a = 0, b = 0, c = 0;

    input(&a, &b, &c);
    double x1 = 0, x2 = 0;

    enum RootQ nRoots = solve_quare(a, b, c, &x1, &x2);
    get_results(nRoots, x1, x2);

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
