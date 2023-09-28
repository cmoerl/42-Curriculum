#include "printf.h"
#include "Libft/libft.h"
#include <unistd.h>

void    ft_print_char(int c)
{
    write(1, &c, 1);
}