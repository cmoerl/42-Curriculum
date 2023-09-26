#include "printf.h"
#include "Libft/libft.h"
#include <unistd.h>

void    ft_print_str(char *str)
{
    write(1, &str, ft_strlen(str));
}