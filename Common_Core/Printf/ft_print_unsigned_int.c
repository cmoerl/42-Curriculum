/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:02:35 by csturm            #+#    #+#             */
/*   Updated: 2023/10/02 16:16:08 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"
#include <stdio.h>

int	ft_print_unsigned_int(unsigned int n)
{
	char	*str;
	size_t	count;

	if (n == 0)
	{
		count = ft_print_char('0');
		return (count);
	}
	str = ft_utoa(n);
	if (!str)
		return (0);
	count = ft_print_str(str);
	free(str);
	return (count);
}
