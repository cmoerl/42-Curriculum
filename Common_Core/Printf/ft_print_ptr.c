/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:03:11 by csturm            #+#    #+#             */
/*   Updated: 2023/10/02 16:50:02 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

static int	ft_digit(uintptr_t p)
{
	int	digit;

	digit = 1;
	while (p >>= 4)
		digit++;
	return (digit);
}

int	ft_print_ptr(void *ptr)
{
	uintptr_t	p;
	int			i;
	size_t		count;
	int			digit;
	
	if (ptr == NULL)
	{
		ft_print_str("(nil)");
		return (5);
	}
	p = (uintptr_t)ptr;
	digit = ft_digit(p);
	ft_print_str("0x");
	count = 2;
	i = digit -1;
	while (i >= 0)
	{
		ft_print_char("0123456789abcdef"[(p >> (i * 4)) & 0xf]);
		i--;
		count++;
	}
	return (count);
}