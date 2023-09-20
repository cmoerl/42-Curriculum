/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:25:53 by csturm            #+#    #+#             */
/*   Updated: 2023/09/11 17:46:35 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(void)
{
	char	*s;

	s = malloc(strlen("longer!") + 1);
	strcpy(s, "longer!");
	ft_bzero(s, 0);
	printf("%s\n", s);
	bzero(s, 10);
	printf("%s\n", s);
	free(s);
	return (0);
}
*/
