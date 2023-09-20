/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:49:47 by csturm            #+#    #+#             */
/*   Updated: 2023/05/31 17:55:08 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || '9' < str[i])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*
int     main(void)
{
        printf("%d\n", ft_str_is_numeric("135567"));
        printf("%d\n", ft_str_is_numeric(""));
        printf("%d\n", ft_str_is_numeric("89,85"));
        return (0);
}
*/
