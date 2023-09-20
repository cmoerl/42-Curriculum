/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:57:15 by csturm            #+#    #+#             */
/*   Updated: 2023/09/20 15:22:21 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*str;
	void		*point;
	size_t		i;

	str = (void *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (char)c)
		{
			point = (void *)&str[i];
			return (point);
		}
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s[] = {0, 1, 2 ,3 ,4 ,5};

	printf("%p\n", ft_memchr(s, 2 + 256, 3));
	printf("%p\n", memchr(s, 2 + 256, 3));
	return (0);
}
*/
