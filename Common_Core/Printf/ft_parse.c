#include "printf.h"
#include "Libft/libft.h"
#include <stdarg.h>

void    ft_parse(const char *format, va_list args)
{
    int     i;
    int     j;
    char    *newstr;

    i = 0;
    va_start(args, format);
    while (format[i])
    {
        if (format[i] == '%')
        {
            while ((format[i] != ) && format[i])
            {
                newstr[j] = format[i];
                i++;
                j++;
            }
            newstr[j] = format[i];
            newstr[j + 1] = '\0';
            ft_assign_val(newstr, args);
        }
        if (format[i] != '\0')
            i++;
    }
    va_end(args);
}