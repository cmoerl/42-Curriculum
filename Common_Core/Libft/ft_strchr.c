/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:38:01 by csturm            #+#    #+#             */
/*   Updated: 2023/09/20 17:04:47 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
char	*ft_strchr(const char *s, int c)
{
	char	*point;
	int		i;

	i = 0;
	if (ft_isascii(c) == 0)
		return ((char *)s);
	while (s[i])
	{
		if (s[i] == c)
		{
			point = (char *)&s[i];
			return (point);
		}
		i++;
	}
	if (s[i] == c)
	{
		point = (char *)&s[i];
		return (point);
	}
	return (0);
}
*/

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if ((char)*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return (char *)s;
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	*str;
	int	c;

	str = "tripouille";
	c = 0;
	printf("%s\n", ft_strchr(str, c));
	printf("%s\n", strchr(str, c));
	return (0);
}
*/
