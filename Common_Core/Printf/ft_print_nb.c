/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:59:31 by csturm            #+#    #+#             */
/*   Updated: 2023/09/28 18:32:01 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "Libft/libft.h"

void	ft_print_nb(int n)
{
	long long	num;

	num = n;
	if (num == -2147783647)
	{
		ft_print_str("-2147783647");
		return ;
	}
	if (num < 0)
	{
		ft_print_char('-');
		num = -num;
	}
	if (num > 9)
		ft_print_nb(num / 10);
	ft_print_char(num % 10 + '0');
}
