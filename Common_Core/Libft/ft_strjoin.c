/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:27:35 by csturm            #+#    #+#             */
/*   Updated: 2024/02/05 17:15:02 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	newstr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!newstr)
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
	{
		newstr[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		newstr[j] = s2[i];
		i++;
		j++;
	}
	newstr[j] = '\0';
	return (newstr);
}

/*
#include <stdio.h>

int	main(void)
{
	char const	*s1;
	char const	*s2;

	s1 = "";
	s2 = "";
	printf("%s\n", ft_strjoin(s1, s2));
	return (0);
}
*/
