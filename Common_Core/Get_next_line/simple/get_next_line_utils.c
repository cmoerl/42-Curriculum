/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:51:02 by csturm            #+#    #+#             */
/*   Updated: 2023/11/07 14:42:05 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	copy_string(const char *src, char *dest)
{
	while (*src)
	{
		*dest = *src;
		src++;
		dest++;
	}
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	newstr = malloc(len1 + len2 + 1);
	if (!newstr)
		return (NULL);
	copy_string(s1, newstr);
	copy_string(s2, newstr + len1);
	newstr[len1 + len2] = '\0';
	return (newstr);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*newstr;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	newstr = malloc(len + 1);
	if (!newstr)
		return (NULL);
	copy_string(s, newstr);
	newstr[len] = '\0';
	return (newstr);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}
