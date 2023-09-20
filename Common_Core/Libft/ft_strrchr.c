/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:49:42 by csturm            #+#    #+#             */
/*   Updated: 2023/09/11 17:49:53 by csturm           ###   ########.fr       */
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

char	*ft_strrchr(const char *s, int c)
{
	char	*point;
	int		i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == c)
		{
			point = (char *)&s[i];
			return (point);
		}
		i--;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*str;
	char	c;

	str = "Hello";
	c = 'i';
	printf("%s\n", ft_strrchr(str, c));
	printf("%s\n", strrchr(str, c));
	return (0);
}
*/
