/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:57:45 by csturm            #+#    #+#             */
/*   Updated: 2023/09/11 18:05:03 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_whitespace(const char *nptr)
{
	size_t	i;

	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
	{
		i++;
	}
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int	num;
	int	i;
	int	neg;

	num = 0;
	i = ft_whitespace(nptr);
	neg = 0;
	if (nptr[i] == '-' && (nptr[i + 1] >= '0' && nptr[i + 1] <= '9'))
	{
		neg = 1;
		i++;
	}
	else if (nptr[i] == '+' && (nptr[i + 1] >= '0' && nptr[i + 1] <= '9'))
	{
		i++;
	}
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		num = num * 10 + (nptr[i] - 48);
		i++;
	}
	if (neg == 1)
		num = -num;
	return (num);
}

/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	const char	*nptr;

	nptr = "\t\n\r\v\f 469 \n";
	printf("%d\n", ft_atoi(nptr));
	printf("%d\n", atoi(nptr));
	return (0);
}
*/
