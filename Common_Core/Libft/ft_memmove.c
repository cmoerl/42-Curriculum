/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:11:43 by csturm            #+#    #+#             */
/*   Updated: 2023/09/15 13:27:19 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	int		i;

	d = dest;
	s = (void *)src;
	i = 0;
	if (d > s)
	{
		while (n > 0)
		{
			n--;
			d[n] = s[n];
		}
	}
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	dest[10];
	char	*src;

	src = "";
	printf("%p\n", ft_memmove(dest, src, 4));
	printf("%s\n", dest);
	printf("%p\n", memmove(dest, src, 4));
	printf("%s\n", dest);
	return (0);
}
*/
