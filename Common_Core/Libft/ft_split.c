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

int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (j);
}

int	ft_findstart(char const *s, char c, int start)
{
	while (s[start] == c)
		start++;
	return (start);
}

int	ft_findlen(char const *s, char c, int start)
{
	int	len;

	len = 0;
	while (s[start] && s[start] != c)
	{
		len++;
		start++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		words;
	int		start;
	int		len;
	int		i;

	i = 0;
	words = ft_wordcount(s, c);
	array = (char **)malloc((words + 1) * sizeof(char *));
	start = 0;
	if (!array)
		return (0);
	while (i < words)
	{
		start = ft_findstart(s, c, start);
		len = ft_findlen(s, c, start);
		array[i] = ft_substr(s, start, len);
		start = start + len;
		i++;
	}
	array[i] = NULL;
	return (array);
}
