#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

// #include <TXLib.h>


// int testing_scr(struct TestingData);

void clear_buf();
int compare_doubles(double a, double b);

enum RootQ
{
    NO_ROOTS = 0,
    ONE_ROOT,
    TWO_ROOTS,
    INF_ROOTS = -1
};

enum RootQ solve_quare(double a, double b, double c, double* x1, double* x2);
void get_results(enum RootQ nRoots, double x1, double x2);
enum RootQ lineal_square(double a, double b, double c, double* x1, double* x2);

struct TestingData
{
    double a,b,c;
    double x1exp,x2exp;
    int nTest, nRootsExp;
};

int main()
{
    puts("# Square equation solver\n"
    "# (c) Vika, 2024\n\n");

    puts("Enter a, b, c: ");
    double a = 0, b = 0, c = 0;

    while (scanf("%lf %lf %lf", &a, &b, &c) != 3)
    {
        clear_buf();
        puts("Try again: ");
    }
    double x1 = 0, x2 = 0;
    enum RootQ nRoots = solve_quare(a, b, c, &x1, &x2);
    get_results(nRoots, x1, x2);
}

void get_results(enum RootQ nRoots, double x1, double x2)
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


void clear_buf()
{
    char simbol = getchar();
    while(simbol != '\n') {
        if (simbol == EOF)
            break;
        simbol = getchar();
    }
}

int compare_doubles(double a, double b)
{
    const double acc = 0.000001;
    if (fabs((a - b)) < acc)
        return 1;
    else
        return 0;
}

enum RootQ lineal_square(double a, double b, double c, double* x1, double* x2)
{
    if (compare_doubles(b, 0))
    {
        return compare_doubles(c, 0)? INF_ROOTS : NO_ROOTS; // разбить на отдельные функции
    }
    else /* if (b != 0) */
    {
        *x1 = -c / b;
        return ONE_ROOT;
    }
}

enum RootQ solve_quare(double a, double b, double c, double* x1, double* x2)
{
    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);

    if (compare_doubles(a, 0))
        lineal_square(a,b,c, *x1, *x2);

    else /* if (a != 0) */
        {
        double diskr = b*b - 4*a*c;
        if (diskr == 0)
        {
            *x1 = *x2 = -b / (2*a);
            return ONE_ROOT;
        }

        else if (diskr < 0)
            return NO_ROOTS;

        else
        {
            double sqrt_d = sqrt(diskr);
            *x1 = (-b - sqrt_d)/(2*a);
            *x2 = (-b + sqrt_d)/(2*a);
            return TWO_ROOTS;
        }
    }
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
