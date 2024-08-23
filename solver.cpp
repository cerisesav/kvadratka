#include <math.h>
#include <assert.h>

#include "solver.h"

DoublesEquality compare_doubles(double a, double b);
static Roots lineal_eq(const Coeffs* equ);
static Roots square_eq(const Coeffs* equ);

Roots solve_square(const Coeffs* equ)
{
    assert (equ != nullptr);

    if (compare_doubles(equ->a, 0))
        return lineal_eq(equ);

    else /* if (a != 0) */
    {
        return square_eq(equ);
    }
}

DoublesEquality compare_doubles(double a, double b)
{
    const double ACC = 0.000001;
    if (fabs((a - b)) < ACC)
        return EQUAL;
    else
        return NOT_EQUAL;
}


static Roots lineal_eq(const Coeffs* equ)
{
    Roots roots = {};

    assert (equ != nullptr);

    if (compare_doubles(equ->b, 0))
    {
        roots.nRoots = compare_doubles(equ->c, 0)? INF_ROOTS : NO_ROOTS;
    }
    else /* if (b != 0) */
    {
        roots.x1 = -equ->c / equ->b;
        roots.nRoots = ONE_ROOT;
    }
    return roots;
}

static Roots square_eq(const Coeffs* equ)
{
    Roots roots = {};
    assert (equ != nullptr);

    double diskr = equ->b * equ->b - 4 * equ->a * equ->c;
    if (diskr == 0)
    {
        roots.x1 = roots.x2 = -equ->b / (2 * equ->a);
        roots.nRoots = ONE_ROOT;
    }

    else if (diskr < 0)
        roots.nRoots = NO_ROOTS;

    else
    {
        double sqrt_d = sqrt(diskr);
        roots.x1 = (-equ->b - sqrt_d) / (2 * equ->a);
        roots.x2 = (-equ->b + sqrt_d) / (2 * equ->a);
        roots.nRoots = TWO_ROOTS;
    }
    return roots;
}

