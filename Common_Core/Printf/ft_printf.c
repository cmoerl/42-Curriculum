#include "printf.h"
#include "Libft/libft.h"
#include <stdarg.h>

int ft_printf(const char *format, ...)
{
    va_list args;
    int     i;
    char    *str;
    int     j;

    va_start(args, format);
    i = 0;
    ft_parse(format, args);
    while (format[i])
    {
        if (format[i] != '%')
            ft_print_char(format[i]);
        else
        {
            i++;
            while (format[i])
            {
                if (format[i] == 'c')
                {
                    ft_print_char(va_arg(args, int));
                    break ;
                }
                else if (format[i] == 's')
                {
                    ft_print_str(va_arg(args, char *));
                    break ;
                }
                else if (format[i] == 'p')
                {
                    ft_print_ptr(va_arg(args, void *));
                    break ;
                }
                else if (format[i] == 'd' || format[i] == 'u' || format[i] == 'i')
                {
                    ft_print_nb(va_arg(args, int));
                    break ;
                }
                else if (format[i] == 'i')
                {
                    ft_print_int(va_arg(args, int));
                    break ;
                }
                else if (format[i] == 'x')
                {
                    ft_print_hex(va_arg(args, unsigned int), 0);
                    break ;
                }
                else if (format[i] == 'X')
                {
                    ft_print_hex(va_arg(args, unsigned int), 1);
                }
                else if (format[i] == '%')
                {
                    ft_print_char('%');
                    break ;
                }
                i++;
            }
        }
        i++;
    }
    va_end(args);
}