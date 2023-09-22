/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:18:33 by csturm            #+#    #+#             */
/*   Updated: 2023/09/15 12:08:01 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_getstr(char *str, long long num)
{
	int	i;
	int	neg;

	neg = 0;
	i = 0;
	if (num < 0)
	{
		num = -num;
		neg = 1;
	}
	while (num > 0)
	{
		str[i] = (num % 10 + '0');
		num = num / 10;
		i++;
	}
	if (neg == 1)
	{
		str[i] = '-';
		i++;
	}
	str[i] = '\0';
}

int	ft_digits(long long num)
{
	int	i;

	i = 0;
	if (num < 0)
	{
		i++;
		num = -num;
	}
	while (num > 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

char	*ft_reversestr(char *str)
{
	char	*revstr;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(str) - 1;
	revstr = malloc(ft_strlen(str) + 1);
	if (!revstr)
		return (0);
	while (j >= 0)
	{
		revstr[i] = str[j];
		i++;
		j--;
	}
	revstr[i] = '\0';
	free(str);
	return (revstr);
}

char	*ft_itoa(int n)
{
	long long	num;
	char		*str;
	int			i;

	i = 0;
	num = n;
	if (num == 0)
	{
		str = malloc(2);
		if (!str)
			return (0);
		str[i] = '0';
		str[i + 1] = '\0';
		return (str);
	}
	str = malloc(ft_digits(num) + 1);
	if (!str)
		return (0);
	ft_getstr(str, num);
	str = ft_reversestr(str);
	return (str);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_itoa(-2147483648));
	return (0);
}
*/
