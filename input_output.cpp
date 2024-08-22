void clear_buf()
{
    char symbol = getchar();
    assert (symbol != EOF);
    while(symbol != '\n') {
        if (symbol == EOF)
            break;
        symbol = getchar();
    }
}

void input(double* a, double* b, double* c)
{
    while (scanf("%lf %lf %lf", a, b, c) != 3)
    {
        clear_buf();
        puts("Try again: ");
    }
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
