#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

// #include <TXLib.h>

enum RootQ SolveSquare(double a, double b, double c, double* x1, double* x2);
int testing_scr(int nTest, double a, double b, double c, double x1exp, double x2exp, int nRootsExp);

void clear_buf();
void get_results(enum RootQ nRoots, double x1, double x2);
int compare_num(double a, double b);

enum RootQ
{
    NO_ROOTS = 0,
    ONE_ROOT,
    TWO_ROOTS,
    INF_ROOTS = -1
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
    }
    double x1 = 0, x2 = 0;
    enum RootQ nRoots = SolveSquare(a, b, c, &x1, &x2);
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
    while(getchar() != '\n');
}

int compare_num(double a, double b)
{
    const double acc = 0.000001;
    if (fabs((a - b)) < acc)
        return 1;
    else
        return 0;
}

enum RootQ SolveSquare (double a, double b, double c, double* x1, double* x2)
{
    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);

    if (compare_num(a, 0))
        {
        if (compare_num(b, 0))
        {
            return compare_num(c, 0)? INF_ROOTS : NO_ROOTS;
        }
        else /* if (b != 0) */
        {
            *x1 = -c / b;
            return ONE_ROOT;
        }
    }
    else /* if (a != 0) */
        {
        double d = b*b - 4*a*c;
        if (d == 0)
            {
            *x1 = *x2 = -b / (2*a);
            return ONE_ROOT;
            }

        else if (d < 0)
            return NO_ROOTS;

        else
        {
            double sqrt_d = sqrt(d);
            *x1 = (-b - sqrt_d)/(2*a);
            *x2 = (-b + sqrt_d)/(2*a);
            return TWO_ROOTS;
        }
    }
}




int testing_scr(int nTest, double a, double b, double c, double x1exp, double x2exp, int nRootsExp)
{
    nTest = 1;
    double x1 = 0, x2 = 0;
    int nRoots = SolveSquare(a,b,c,&x1,&x2);
    if (compare_num(nRoots, nRootsExp) != 1 || compare_num(x1,x1exp) != 1 || compare_num(x2,x2exp) != 1)
    {
        printf("ERROR Test 1: a = %lf, b = %lf, c = %lf, x1 = %lf, x2 = %lf\n"
            "Expected nRoots: x1 = %lf, x2 = %lf, nRoots = %d\n",
            nTest, a, b, c, x1, x2, nRoots,
            x1exp, x2exp, nRootsExp);
        return 1;
    }
    else
        return 0;
}
