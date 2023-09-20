/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:46:49 by csturm            #+#    #+#             */
/*   Updated: 2023/09/17 16:46:49 by csturm           ###   ########.fr       */
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*substr;

	i = start;
	j = 0;
	substr = malloc(len + 1);
	if (!substr || !s || i >= ft_strlen(s))
		return (0);
	while (j < len && s[i])
	{
		substr[j] = s[i];
		j++;
		i++;
	}
	substr[j] = '\0';
	return (substr);
}

/*
#include <stdio.h>

int	main(void)
{
	char const	*s;

	s = "This is a string.";
	printf("%s\n", ft_substr(s, 8, 9));
	free(substr);
	return (0);
}
*/
