/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:03:11 by csturm            #+#    #+#             */
/*   Updated: 2023/09/28 18:34:47 by csturm           ###   ########.fr       */
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

void	ft_print_ptr(void *ptr)
{
	uintptr_t	p;
	int			i;

	p = (uintptr_t)ptr;
	i = (sizeof(p) << 3) - 4;
	ft_print_str("0x");
	while (i >= 0)
	{
		ft_print_char(ft_digit((p >> i) & 0xf));
		i = i - 4;
	}
}
