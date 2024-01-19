/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:18:07 by csturm            #+#    #+#             */
/*   Updated: 2024/01/19 19:58:18 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_wordcount(char const *s, char c)
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

static int	ft_findstart(char const *s, char c, int start)
{
	while (s[start] == c)
		start++;
	return (start);
}

static int	ft_findlen(char const *s, char c, int start)
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

static char	**free_all(char **array, int i)
{
	while (i)
	{
		printf("freeing array[%d]=%s\n", i, array[i]);	
		free(array[i]);
		i--;
	}
	free(array);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	start;
	int		len;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	start = 0;
	array = malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	free_all(array, ft_wordcount(s, c));
	while (i < ft_wordcount(s, c))
	{
		start = ft_findstart(s, c, start);
		printf("start=%lu\n", start);
		// len = 0;
		len = ft_findlen(s, c, start);
		// printf("len=%d\n", len);
	// 	array[i] = ft_substr(s, start, len);
	// 	if (!array[i])
	// 		return (free_all(array, i));
		start = start + len;
		i++;
	}
	return (NULL);
	// array[i] = NULL;
	// return (array);
}
