/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:52:03 by csturm            #+#    #+#             */
/*   Updated: 2023/09/11 16:26:49 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	else
		return (0);
}

/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	int	c;
	int	i;

	c = '\n';
	i = ft_isprint(c);
	printf("%d\n", i);
	i = isprint(c);
	printf("%d\n", i);
	return (0);
}
*/
