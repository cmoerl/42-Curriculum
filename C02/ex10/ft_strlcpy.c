/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:51:21 by csturm            #+#    #+#             */
/*   Updated: 2023/06/01 09:37:53 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (dest == NULL || src == NULL || size == 0)
	{
		return 0;
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
        char    dest[sizeof(src)];
	int	size = sizeof(dest);

        printf("strlcpy: %d\n", ft_strlcpy(dest, src, size));
        printf("src: %s\n", src);
        printf("dest: %s\n", dest);
        return (0);
}
*/
