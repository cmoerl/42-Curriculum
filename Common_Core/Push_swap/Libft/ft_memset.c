/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:08:08 by csturm            #+#    #+#             */
/*   Updated: 2023/09/11 18:04:13 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*mem;

	mem = s;
	i = 0;
	while (i < n)
	{
		mem[i] = c;
		i++;
	}
	return (mem);
}

/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(void)
{
	char	*s;

	s = malloc(strlen("longer!") + 1);
	strcpy(s, "longer!");
	printf("%p\n", ft_memset(s, 'a', 0));
	printf("%s\n", s);
	printf("%p\n", memset(s, 'o', 0));
	printf("%s\n", s);
	free(s);
	return (0);
}
*/
