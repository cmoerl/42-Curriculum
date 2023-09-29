/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:03:11 by csturm            #+#    #+#             */
/*   Updated: 2023/09/29 10:56:17 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "Libft/libft.h"

static char	ft_digit(int d)
{
	if (d >= 0 && d < 10)
		return ('0' + d);
	else
		return ('a' + d - 10);
}

int	ft_print_ptr(void *ptr)
{
	uintptr_t	p;
	int			i;
	size_t		count;

	p = (uintptr_t)ptr;
	i = (sizeof(p) << 3) - 4;
	ft_print_str("0x");
	count = 2;
	while (i >= 0)
	{
		ft_print_char(ft_digit((p >> i) & 0xf));
		i = i - 4;
		count++;
	}
	return (count);
}
