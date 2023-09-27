#include "printf.h"
#include "Libft/libft.h"
#include <stdarg.h>

void    ft_parse(const char *format_new, va_list args)
{
    int     i;
    int     j;
    char    *newstr;

    i = 0;
    va_start(args, format);
    while (format_new[i])
    {
        if (format_new[i] == '%')
        {
            j = 0;
            while (format [i] && (format_new[i] != 'c'
            && format_new[i] != 's' && format_new[i] != 'p'
            && format_new[i] != 'd' && format_new[i] != 'i'
            && format_new[i] != 'u' && format_new[i] != 'x'
            && format_new[i] != 'X' && format_new[i] != '%'))
            {
                newstr[j] = format_new[i];
                i++;
                j++;
            }
            newstr[j] = format_new[i];
            newstr[j + 1] = '\0';
            ft_assign_val(newstr, args);
        }
        if (format_new[i] != '\0')
            i++;
    }
    va_end(args);
}