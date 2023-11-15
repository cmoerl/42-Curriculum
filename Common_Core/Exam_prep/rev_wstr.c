#include <unistd.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

void    write_str(char *str, int i)
{
    while (str[i] && str[i] != ' ')
    {
        write(1, &str[i], 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    int i;

    if (argc == 2)
    {
        i = ft_strlen(argv[1]) - 1;
        while (i >= 0)
        {
            while (i >= 0 && argv[1][i] != ' ')
                i--;
            write_str(argv[1], i + 1);
            if (i > 0)
            {
                write(1, " ", 1);
                i--;
            }
        }
    }
    write(1, "\n", 1);
}