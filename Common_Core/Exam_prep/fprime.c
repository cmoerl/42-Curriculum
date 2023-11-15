#include <stdio.h>
#include <stdlib.h>

int is_prime(int n)
{
    int i;

    i = 2;
    while (i <= n / i)
    {
        if (n % i == 0)
            return (0);
        i++;
    }
    return (1);
}

int find_next_prime(int n)
{
    if (n < 2)
        return (2);
    n++;
    while (!is_prime(n))
        n++;
    return (n);
}

int main(int argc, char **argv)
{
    int nb;
    int factor;

    if (argc == 2)
    {
        nb = atoi(argv[1]);
        if (nb == 1)
            printf("1");
        factor = 2;
        while (nb > 1)
        {
            while (nb % factor == 0)
            {
                nb = nb / factor;
                printf("%d", factor);
                if (nb > 1)
                    printf("*");
            }
            factor = find_next_prime(factor);
        }
    }
    printf("\n");
    return (0);
}

