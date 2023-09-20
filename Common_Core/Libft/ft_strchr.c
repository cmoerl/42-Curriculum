/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:38:01 by csturm            #+#    #+#             */
/*   Updated: 2023/09/11 17:50:54 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*point;
	int		i;

	i = 0;
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

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	*str;
	char	c;

	str = "tripouille";
	c = 't' + 256;
	printf("%s\n", ft_strchr(str, c));
	printf("%s\n", strchr(str, c));
	return (0);
}
*/
