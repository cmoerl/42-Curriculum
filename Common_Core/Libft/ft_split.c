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

char	*ft_makestr(int start, int end, char const *s)
{
	char	*str;
	int		length;
	int		i;

	length = end - start;
	str = malloc((length + 1) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (i < length)
	{
		str[i] = s[start + i];
		i++;
	}
	str[length] = '\0';
	return (str);
}

void	ft_fillarr(int i, const char *s, char **array, char *str)
{
	int	j;

	j = 0;
	array[i] = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!array[i])
		return ;
	while (str[j])
	{
		array[i][j] = str[j];
		j++;
	}
	array[i][j] = '\0';
	free (str);
}

int	check_deliminator(int start, char const *s, char c)
{
	while (s[start] && s[start] == c)
	{
		start++;
	}
	return (start - 1);
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
		if (s[start] == c)
			end = check_deliminator(start, s, c);
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
