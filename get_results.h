#pragma once

enum RootQ
{
    NO_ROOTS = 0,
    ONE_ROOT,
    TWO_ROOTS,
    INF_ROOTS = -1
};

int compare_doubles(double a, double b)
{
    const double acc = 0.000001;
    if (fabs((a - b)) < acc)
        return 1;
    else
        return 0;
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

enum RootQ lineal_eq(double a, double b, double c, double* x1, double* x2)
{
    if (compare_doubles(b, 0))
    {
        return compare_doubles(c, 0)? INF_ROOTS : NO_ROOTS;
    }
    else /* if (b != 0) */
    {
        *x1 = -c / b;
        return ONE_ROOT;
    }
}

enum RootQ square_eq(double a, double b, double c, double* x1, double* x2)
{
    double diskr = b * b - 4 * a * c;
        if (diskr == 0)
        {
            *x1 = *x2 = -b / (2 * a);
            return ONE_ROOT;
        }

        else if (diskr < 0)
            return NO_ROOTS;

        else
        {
            double sqrt_d = sqrt(diskr);
            *x1 = (-b - sqrt_d) / (2 * a);
            *x2 = (-b + sqrt_d) / ( 2 * a);
            return TWO_ROOTS;
        }
}

enum RootQ solve_quare(double a, double b, double c, double* x1, double* x2)
{
    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);

    if (compare_doubles(a, 0))
        return lineal_eq(a, b, c, x1, x2);

    else /* if (a != 0) */
    {
        return square_eq(a, b, c, x1, x2);
    }
}


