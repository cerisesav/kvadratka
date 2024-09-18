#ifndef SOLVER_H
#define SOLVER_H

enum RootQ
{
    NO_ROOTS = 0,
    ONE_ROOT,
    TWO_ROOTS,
    INF_ROOTS = -1
};

struct Coeffs
{
   double a, b, c;
};

struct Roots
{
    double x1, x2;
    RootQ nRoots;
};

enum DoublesEquality
{
    NOT_EQUAL,
    EQUAL
};

Roots solve_square(const Coeffs* equ);

DoublesEquality compare_doubles(double a, double b);

#endif //SOLVER_H
