/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:56:12 by csturm            #+#    #+#             */
/*   Updated: 2023/05/30 12:41:30 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

/*
int	main(void)
{
	char	src[] = "Hello, world!";
	char	dest[sizeof(src)];

	ft_strcpy(dest, src);
	printf("src: %s\n", src);
	printf("dest: %s\n", dest);
	return (0);
}
*/
