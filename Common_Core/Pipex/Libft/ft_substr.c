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

char	*allocate_memory(size_t len)
{
	static char	*substr;

	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	if (len == 0)
		substr[0] = '\0';
	return (substr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*substr;

	if (!s || start >= ft_strlen(s))
		return (allocate_memory(0));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	substr = allocate_memory(len);
	if (!substr)
		return (NULL);
	i = start;
	j = 0;
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
