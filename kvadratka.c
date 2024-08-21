#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

#define INF_ROOTS -1

int SolveSquare(double a, double b, double c, double* x1, double* x2);
int allTests(int nTest, double a, double b, double c, double x1exp, double x2exp, int nRootsExp);
int CheckCon(double* a, double* b, double* c);
void clear_sc();

int main()
{
    printf("# Square equation solver\n"
    "# (c) Vika, 2024\n\n");

    printf ("Enter a, b, c: ");
    double a = 0, b = 0, c = 0;

    while (scanf("%lg %lg %lg", &a, &b, &c) != 3)
    {
        clear_sc();
        CheckCon(&a,&b,&c);
    }
    double x1 = 0, x2 = 0;
    int nRoots = SolveSquare(a, b, c, &x1, &x2);
    switch (nRoots)
    {
        case 0: printf ("No roots\n");
            break;
        case 1: printf ("x = %lg\n", x1);
            break;
        case 2: printf ("x1 = %lg, x2 = %lg\n", x1, x2);
            break;
        case INF_ROOTS: printf ("infinity");
            break;
        default: printf ("main(): ERROR: nRoots = %d\n", nRoots);
            return 1;
    }
    return 0;
}

void clear_sc()
{
    while(getchar() != '\n')
    ;
}

int CheckCon(double* a, double *b, double *c)
{
    if ((isdigit(a) != 1) || (isdigit(b) != 1) || (isdigit(c) != 1))
    {
        printf("%s", "You must enter numbers. Try again: ");
    }
}

int SolveSquare (double a, double b, double c, double* x1, double* x2)
{
    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);
    if (a == 0)
        {
        if (b == 0)
            {
            return (c == 0)? INF_ROOTS : 0;
            }
    else /* if (b != 0) */
        {
        *x1 = -c / b;
        return 1;
        }
    }
    else /* if (a != 0) */
        {
        double d = b*b - 4*a*c;
        if (d == 0)
            {
            *x1 = *x2 = -b / (2*a);
            return 1;
            }
        else
        {
            double sqrt_d = sqrt(d);
            *x1 = (-b - sqrt_d)/(2*a);
            *x2 = (-b - sqrt_d)/(2*a);
            return 2;
        }
    }
}

int allTests(int nTest, double a, double b, double c, double x1exp, double x2exp, int nRootsExp)
{
    nTest = 1;
    double x1 = 0, x2 = 0;
    int nRoots = SolveSquare(a,b,c,&x1,&x2);
    if (nRoots != nRootsExp || x1 != x1exp || x2 != x2exp)
    {
        printf("ERROR Test 1: a = %lg, b = %lg, c = %lg, x1 = %lg, x2 = %lg\n"
            "Expected nRoot: x1 = %lg, x2 = %lg, nRoot = %d\n",
            nTest, a, b, c, x1, x2, nRoots,
            x1exp, x2exp, nRootsExp);
        return 1;
    }
    else
        return 0;
}
