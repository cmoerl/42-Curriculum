/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:02:56 by csturm            #+#    #+#             */
/*   Updated: 2023/09/11 18:03:38 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

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

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int	i;

	i = 0;
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		len;

	len = ft_strlen((char *)s) + 1;
	dup = malloc(len);
	if (!dup)
		return (0);
	ft_strlcpy(dup, (char *)s, len);
	return (dup);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	*s;

	s = "";
	printf("%s\n", ft_strdup(s));
	printf("%s\n", strdup(s));
	return (0);
}
*/
