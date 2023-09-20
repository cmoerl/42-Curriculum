/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:18:07 by csturm            #+#    #+#             */
/*   Updated: 2023/09/20 15:23:26 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

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

char	*ft_makestr(int start, int end, char const *s)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(end - start + 1);
	if (!str)
		return (0);
	while (start < end)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_fillarr(int i, const char *s, char **array, char *str)
{
	int	j;

	j = 0;
	array[i] = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	while (str[j])
	{
		array[i][j] = str[j];
		j++;
	}
	free (str);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		start;
	int		end;
	int		i;

	start = 0;
	end = 0;
	i = 0;
	array = (char **)malloc((ft_strlen(s) + 1) * sizeof (char *));
	if (!array)
		return (0);
	while (s[end])
	{
		while (s[end] != c && s[end] != '\0')
			end++;
		ft_fillarr(i, s, array, ft_makestr(start, end, s));
		if (s[end] != '\0')
			end ++;
		start = end;
		i++;
	}
	array[i] = NULL;
	return (array);
}
