/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:03:53 by csturm            #+#    #+#             */
/*   Updated: 2023/06/01 09:20:34 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || 126 < str[i])
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
	printf("%d\n", ft_str_is_printable("hello"));
	printf("%d\n", ft_str_is_printable("hello "));
	printf("%d\n", ft_str_is_printable(""));
	return (0);
}
*/
