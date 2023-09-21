/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:06:51 by csturm            #+#    #+#             */
/*   Updated: 2023/09/11 17:05:43 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

/*
#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	char	dest[50];
	const char	*src;

	src = "lorem ipsum dolor sit amet";
	printf("%s\n", dest);
	printf("%s\n", src);
	printf("%zu\n", ft_strlcpy(dest, src, 0));
	printf("%s\n", dest);
	printf("%zu\n", strlcpy(dest, src, 0));
	printf("%s\n", dest);
	return (0);
}
*/
