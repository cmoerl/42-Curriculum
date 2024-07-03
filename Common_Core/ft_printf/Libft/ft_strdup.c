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

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		len;

	len = ft_strlen((char *)s) + 1;
	dup = malloc(len);
	if (!dup)
		return (0);
	ft_strlcpy(dup, s, len);
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
