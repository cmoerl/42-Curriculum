/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:14:09 by csturm            #+#    #+#             */
/*   Updated: 2023/09/11 16:28:58 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - 32);
	}
	else
		return (c);
}

/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	int	c;

	c = 'A';
	printf("%c\n", ft_toupper(c));
	printf("%c\n", toupper(c));
	return (0);
}
*/
