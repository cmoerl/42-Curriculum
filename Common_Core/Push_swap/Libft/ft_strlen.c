/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:14:09 by csturm            #+#    #+#             */
/*   Updated: 2023/09/12 16:22:36 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	*str;

	str = "Hello, my name is.";
	printf("%lu\n", ft_strlen(str));
	printf("%lu\n", strlen(str));
	return (0);
}
*/
