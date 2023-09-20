/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:26:47 by csturm            #+#    #+#             */
/*   Updated: 2023/06/01 09:31:46 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < 48 || (57 < str[i] && str[i] < 65) ||
			(90 < str[i] && str[i] < 97) || 122 < str[i]))
		{
			if (96 < str[i + 1] && str[i + 1] < 123)
				str[i + 1] = str[i + 1] - 32;
		}
		else
		{
			if (i == 0 && (96 < str[i] && str[i] < 123))
				str[i] = str[i] - 32;
			else if (64 < str[i + 1] && str[i + 1] < 91)
				str[i + 1] = str[i + 1] + 32;
		}
		i++;
	}
	return (str);
}

/*
int	main(void)
{
	char	str1[] = "hello, nice to meet you!";
	char	str2[] = "HELLO,-NICE-TO-MEET-YOU!";
	char	str3[] = "this IS on3word.";

	printf("%s\n", ft_strcapitalize(str1));
	printf("%s\n", ft_strcapitalize(str2));
	printf("%s\n", ft_strcapitalize(str3));
	return (0);
}
*/
