#ifndef SOLVER_H
#define SOLVER_H

enum RootQ
{
    NO_ROOTS = 0,
    ONE_ROOT,
    TWO_ROOTS,
    INF_ROOTS = -1
};

int compare_doubles(double a, double b);
enum RootQ lineal_eq(double a, double b, double c, double* x1, double* x2);
enum RootQ square_eq(double a, double b, double c, double* x1, double* x2);
enum RootQ solve_quare(double a, double b, double c, double* x1, double* x2);

#endif //SOLVER_H
