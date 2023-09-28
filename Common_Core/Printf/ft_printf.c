#include "printf.h"
#include "Libft/libft.h"
#include <stdarg.h>

int ft_printf(const char *format, ...)
{
    va_list args;
    size_t  i;

    va_start(args, format);
    i = 0;
    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (format[i] == 'c')
                ft_print_char(va_arg(args, char));
            else if (format[i] == 's')
                ft_print_str(va_arg(args, char *));
            else if (format[i] == 'p')
                ft_print_ptr(va_arg(args, void *));
            else if (format[i] == 'd' || format[i] == 'i' || format[i] == 'u')
                ft_print_int(va_arg(args, int));
            else if (format[i] == 'x')
                ft_print_hex(va_arg(args, int), 0);
            else if (format[i] == 'X')
                ft_print_hex(va_arg(args, int), 1);
            else if (format[i] == '%')
                ft_print_char('%');
        }
        else
            ft_print_char(format[i]);
        if (format[i] != '\0')
            i++;
    }
    va_end(args);
}