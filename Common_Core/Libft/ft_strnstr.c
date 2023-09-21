/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:48:49 by csturm            #+#    #+#             */
/*   Updated: 2023/09/20 15:50:45 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = ft_strlen(little);
	if (j == 0)
		return ((char *)big);
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			k = 0;
			while (i + k < len && little[k] && big[i + k] == little[k])
			{
				if (k == j - 1)
					return ((char *)&big[i]);
				k++;
			}
		}
		i++;
	}
	return (NULL);
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
