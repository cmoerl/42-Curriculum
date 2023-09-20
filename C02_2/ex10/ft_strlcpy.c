/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:51:21 by csturm            #+#    #+#             */
/*   Updated: 2023/06/01 14:07:05 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

unsigned int	ft_strlen(const char *src)
{
	unsigned int	c;

	c = 0;
	while (*src != '\0')
	{
		c++;
		src++;
	}
	return (c);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	l;

	i = 0;
	if (size == 0)
	{
		l = ft_strlen(src);
		return (l);
	}
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}

/*
int     main(void)
{
        char    src[] = "Hello, world!";
        char    dest[sizeof(src) + 1];
	int	size = 9;

        printf("strlcpy: %d\n", ft_strlcpy(dest, src, size));
        printf("src: %s\n", src);
        printf("dest: %s\n", dest);
        return (0);
}
*/
