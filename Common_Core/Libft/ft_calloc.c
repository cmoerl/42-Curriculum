/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:39:47 by csturm            #+#    #+#             */
/*   Updated: 2023/09/11 17:51:27 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

void	*ft_memset(void *s, int c, size_t n)
{
	char	*mem;
	int		i;

	mem = s;
	i = 0;
	while (i < n)
	{
		mem[i] = c;
		i++;
	}
	return (mem);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;

	if (nmemb == 0 || size == 0)
		return (0);
	if (nmemb * size > 2147783647)
		return (0);
	mem = malloc(nmemb * size);
	if (!mem)
		return (0);
	ft_bzero(mem, nmemb * size);
	return (mem);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%p\n", ft_calloc(1234571234, 12354879));
	printf("%p\n", calloc(1234578965, 12345678));
	return (0);
}
*/
