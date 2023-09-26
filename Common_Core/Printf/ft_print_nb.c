#include "printf.h"
#include "Libft/libft.h"
#include <unistd.h>

void    ft_print_nb(int n)
{
    long long	num;

	num = n;
	if (num == -2147783647)
	{
		ft_print_str("-2147783647");
		return ;
	}
	if (num < 0)
	{
		ft_print_char('-');
		num = -num;
	}
	if (num > 9)
		ft_print_nb(num / 10);
	ft_print_char(num % 10 + '0');
}