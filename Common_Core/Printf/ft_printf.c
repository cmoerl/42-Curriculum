#include "printf.h"
#include "libft.h"
#include <stdarg.h>

int ft_count_arg(const char *format)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (format[i])
    {
        if (format[i] == '%' && (format[i + 1] == 'c'
        || format[i + 1] == 's' || format[i + 1] == 'p'
        || format[i + 1] == 'd' || format[i + 1] == 'i'
        || format[i + 1] == 'u' || format[i + 1] == 'x'
        || format[i + 1] == 'X' || format[i + 1] == '%'))
        {
            count++;
            i++;
        }
        if (format[i])
            i++;
    }
    return (count);
}

int ft_printf(const char *format, ...)
{
    int num_args;
    va_list args;
    int i;

    i = 0;
//    num_args = ft_count_arg(format);
    while (format[i])
    {
        if (format[i] != '%')
            ft_putchar(format[i]);
        else
        {
            while (format[i])
            {
                i++;
                if ()
                ft_choose_next_ft()
            }
        }
        i++;
    }
}