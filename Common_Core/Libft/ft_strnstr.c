/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:48:49 by csturm            #+#    #+#             */
/*   Updated: 2023/09/11 17:55:14 by csturm           ###   ########.fr       */
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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = ft_strlen(little);
	if (j == 0)
		return ((char *)big);
	while ((i < len) && (i <= (len - j)))
	{
		if (big[i] == little[0])
		{
			k = ft_strncmp(&big[i], little, j);
			if (k == 0)
			{
				return ((char *)&big[i]);
			}
		}
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	char	*str1;
	char	*str2;

	str1 = "lorem ipsum dolor sit amet";
	str2 = "ipsumm";
	printf("%s\n", ft_strnstr(str1, str2, 30));
	printf("%s\n", strnstr(str1, str2, 30));
	return (0);
}
*/
