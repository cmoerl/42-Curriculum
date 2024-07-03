/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:02:21 by csturm            #+#    #+#             */
/*   Updated: 2023/12/14 16:24:22 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_type(va_list args, const char spec)
{
	int	count;

	count = 0;
	if (spec == 'c')
		count += ft_print_char(va_arg(args, int));
	else if (spec == 's')
		count += ft_print_str(va_arg(args, char *));
	else if (spec == 'p')
		count += ft_print_ptr(va_arg(args, void *));
	else if (spec == 'd' || spec == 'i')
		count += ft_print_int(va_arg(args, int));
	else if (spec == 'u')
		count += ft_print_unsigned_int(va_arg(args, unsigned int));
	else if (spec == 'x')
		count += ft_print_hex(va_arg(args, int), 0);
	else if (spec == 'X')
		count += ft_print_hex(va_arg(args, int), 1);
	else if (spec == '%')
		count += ft_print_char('%');
	else
		count += ft_print_char('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	size_t	count;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += ft_find_type(args, format[i + 1]);
			i++;
		}
		else
			count += ft_print_char(format[i]);
		if (format[i] != '\0')
			i++;
	}
	va_end(args);
	return (count);
}
