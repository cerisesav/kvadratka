#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
// #include <TXLib.h>

enum root_q SolveSquare(double a, double b, double c, double* x1, double* x2);
// int allTests(int nTest, double a, double b, double c, double x1exp, double x2exp, int nRootsExp);
void CheckCon(double* a, double* b, double* c);
void clear_sc();
void Results(enum root_q nRoots, double x1, double x2);
int compare(double a, double b);

enum root_q
{
    NO_ROOTS = 0,
    ONLY_ONE,
    TWO_ROOTS,
    INF_ROOTS = -1
};

int main()
{
    printf("# Square equation solver\n"
    "# (c) Vika, 2024\n\n");

    printf ("Enter a, b, c: ");
    double a = 0, b = 0, c = 0;

    while (scanf("%lf %lf %lf", &a, &b, &c) != 3)
    {
        clear_sc();
    }
    double x1 = 0, x2 = 0;
    enum root_q nRoots = SolveSquare(a, b, c, &x1, &x2);
    Results(nRoots, x1, x2);
}

void Results(enum root_q nRoots, double x1, double x2)
{
    switch (nRoots)
    {
        case NO_ROOTS: printf ("No roots\n");
            break;
        case ONLY_ONE: printf ("x = %lf\n", x1);
            break;
        case TWO_ROOTS: printf ("x1 = %lf, x2 = %lf\n", x1, x2);
            break;
        case INF_ROOTS: printf ("infinity");
            break;
        default: printf ("main(): ERROR: nRoots = %d\n", nRoots);
    }
}


void clear_sc()
{
    while(getchar() != '\n');
}

void CheckCon(double* a, double *b, double *c)
{
    if ((isdigit(*a) != 1) || (isdigit(*b) != 1) || (isdigit(*c) != 1))
    {
        printf("%s", "You must enter numbers. Try again: ");
    }
}

int compare(double a, double b)
{
    const double acc = 0.000001;
    if (abs((a - b)) < acc)
        return 1;
    else
        return 0;
}

enum root_q SolveSquare (double a, double b, double c, double* x1, double* x2)
{
    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);

    if (compare(a, 0))
        {
        if (compare(b, 0))
        {
            return compare(c, 0)? INF_ROOTS : 0;
        }
        else /* if (b != 0) */
        {
            *x1 = -c / b;
            return ONLY_ONE;
        }
    }
    else /* if (a != 0) */
        {
        double d = b*b - 4*a*c;
        if (d == 0)
            {
            *x1 = *x2 = -b / (2*a);
            return ONLY_ONE;
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




// int allTests(int nTest, double a, double b, double c, double x1exp, double x2exp, int nRootsExp)
// {
//     nTest = 1;
//     double x1 = 0, x2 = 0;
//     int nRoots = SolveSquare(a,b,c,&x1,&x2);
//     if (nRoots != nRootsExp || x1 != x1exp || x2 != x2exp)
//     {
//         printf("ERROR Test 1: a = %lf, b = %lf, c = %lf, x1 = %lf, x2 = %lf\n"
//             "Expected nRoot: x1 = %lf, x2 = %lf, nRoot = %d\n",
//             nTest, a, b, c, x1, x2, nRoots,
//             x1exp, x2exp, nRootsExp);
//         return 1;
//     }
//     else
//         return 0;
// }
