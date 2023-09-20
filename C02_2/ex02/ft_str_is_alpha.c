/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:52:15 by csturm            #+#    #+#             */
/*   Updated: 2023/05/30 15:47:42 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < 'A' || 'Z' < str[i]) && (str[i] < 'a' || 'z' < str[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*
int	main(void)
{
	printf("%d\n", ft_str_is_alpha("hello"));
	printf("%d\n", ft_str_is_alpha("hello!"));
	printf("%d\n", ft_str_is_alpha(""));
	return (0);
}
*/
