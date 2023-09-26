#include "printf.h"
#include "Libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

void    ft_print_int(int n)
{
    char    *str;

    str = ft_itoa(n);
    ft_print_str(str);
    free(str);
}