/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:52:24 by csturm            #+#    #+#             */
/*   Updated: 2023/09/12 18:16:31 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*newstring(int end, int start, char const *s1)
{
	char	*newstr;
	int		i;

	newstr = malloc(end - start + 2);
	if (!newstr)
		return (0);
	i = 0;
	while (start <= end)
	{
		newstr[i] = s1[start];
		i++;
		start++;
	}
	newstr[i] = '\0';
	return (newstr);
}

int	find_start(char const *s1, char const *set)
{
	int	i;
	int	start;

	i = 0;
	start = 0;
	while (set[i])
	{
		if (s1[start] == set[i])
		{
			start++;
			i = -1;
		}
		i++;
	}
	return (start);
}

int	find_end(char const *s1, char const *set)
{
	int	i;
	int	end;

	end = ft_strlen(s1) - 1;
	i = 0;
	while (set[i])
	{
		if (s1[end] == set[i])
		{
			end--;
			i = -1;
		}
		i++;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*newstr;
	int		start;
	int		end;

	start = find_start(s1, set);
	end = find_end(s1, set);
	newstr = newstring(end, start, s1);
	return (newstr);
}

/*
#include <stdio.h>

int	main(void)
{
	char const	*s1;
	char const	*set;

	s1 = "string_strings";
	set = "absrt";
	printf("%s\n", ft_strtrim(s1, set));
	return (0);
}
*/
