/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:59:11 by csturm            #+#    #+#             */
/*   Updated: 2023/09/28 18:27:06 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "Libft/libft.h"

static void	ft_getstr(char *str, long long num, int up)
{
	int	i;
	int	neg;
	int	rem;

	neg = 0;
	i = 0;
	if (num < 0)
	{
		num = -num;
		neg = 1;
	}
	while (num > 0)
	{
		rem = num % 16;
		if (rem < 10)
			str[i] = rem + '0';
		else
		{
			if (up == 0)
				str[i] = rem - 10 + 'a';
			else
				str[i] = rem - 10 + 'A';
		}
		num = num / 16;
		i++;
	}
	if (neg == 1)
	{
		str[i] = '-';
		i++;
	}
	str[i] = '\0';
}

static int	ft_digits(long long num)
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
		num = num / 16;
		i++;
	}
	return (i);
}

static char	*ft_reversestr(char *str)
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
	return (revstr);
}

void	ft_print_hex(unsigned int n, int up)
{
	long long	num;
	char		*str;
	char		*revstr;
	int			i;

	i = 0;
	num = n;
	if (num == 0)
	{
		str = malloc(2);
		if (!str)
			return ;
		str[i] = '0';
		str[i + 1] = '\0';
		return ;
	}
	str = malloc(ft_digits(num) + 1);
	if (!str)
		return ;
	ft_getstr(str, num, up);
	revstr = ft_reversestr(str);
	free(str);
	ft_print_str(str);
}
