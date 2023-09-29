/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:02:21 by csturm            #+#    #+#             */
/*   Updated: 2023/09/29 10:46:58 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	size_t	count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				count += ft_print_char(va_arg(args, int));
			else if (format[i] == 's')
				count += ft_print_str(va_arg(args, char *));
			else if (format[i] == 'p')
				count += ft_print_ptr(va_arg(args, void *));
			else if (format[i] == 'd' || format[i] == 'i' || format[i] == 'u')
				count += ft_print_int(va_arg(args, int));
			else if (format[i] == 'x')
				count += ft_print_hex(va_arg(args, int), 0);
			else if (format[i] == 'X')
				count += ft_print_hex(va_arg(args, int), 1);
			else if (format[i] == '%')
				count += ft_print_char('%');
		}
		else
			count += ft_print_char(format[i]);
		if (format[i] != '\0')
			i++;
	}
	va_end(args);
	return (0);
}

/*
#include <stdio.h>

int main(void)
{
    ft_printf("%d\n%c\n", 42, 'a');
    printf("%d\n%c\n", 42, 'a');
    return (0);
}
*/
