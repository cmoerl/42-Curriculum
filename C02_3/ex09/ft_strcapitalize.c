/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:26:47 by csturm            #+#    #+#             */
/*   Updated: 2023/06/01 10:54:23 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	f;

	i = 0;
	f = 1;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')
			|| (str[i] >= '0' && str[i] <= '9'))
		{
			if (f == 1 && (str[i] >= 'a' && str[i] <= 'z'))
				str[i] -= 32;
			else if (f == 0 && (str[i] >= 'A' && str[i] <= 'Z'))
			{
				str[i] += 32;
			}
			f = 0;
		}
		else
		{
			f = 1;
		}
		i++;
	}
	return (str);
}

/*
int	main(void)
{
	char	str1[] = "hello, nice to meet you!";
	char	str2[] = "-HELLO,-NICE-TO-MEET-YOU!";
	char	str3[] = "this IS on3word.";

	printf("%s\n", ft_strcapitalize(str1));
	printf("%s\n", ft_strcapitalize(str2));
	printf("%s\n", ft_strcapitalize(str3));
	return (0);
}
*/
