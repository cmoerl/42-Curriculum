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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*substr;

	i = start;
	j = 0;
	if (!s || start >= ft_strlen(s))
	{
		substr = malloc(1);
		if (!substr)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
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
