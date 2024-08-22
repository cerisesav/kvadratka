void clear_buf()
{
    char symbol = getchar();
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


