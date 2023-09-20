/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:21:49 by csturm            #+#    #+#             */
/*   Updated: 2023/09/11 18:02:41 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	int		i;

	d = dest;
	s = (void *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
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
	printf("%p\n", ft_memcpy(dest, src, 10));
	printf("%s\n", dest);
	printf("%p\n", memcpy(dest, src, 10));
	printf("%s\n", dest);
	return (0);
}
*/
