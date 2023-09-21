/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:37:00 by csturm            #+#    #+#             */
/*   Updated: 2023/09/11 17:57:02 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int	length_dst;
	int	length_src;
	int	j;
	int	i;

	length_dst = ft_strlen(dst);
	length_src = ft_strlen(src);
	if (size <= length_dst)
		return (length_src + size);
	j = length_dst;
	i = 0;
	while (src[i] && (j + 1) < size)
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (length_dst + length_src);
}

/*
#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	char	dest[20] = "Good ";
	const char	*src;

	src = "Bye!";	
	printf("%zu\n", ft_strlcat(dest, src, 20));
	printf("%s\n", dest);
	printf("%zu\n", strlcat(dest, src, 20));
	printf("%s\n", dest);
	return (0);
}
*/
