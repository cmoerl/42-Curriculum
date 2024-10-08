/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:02:35 by csturm            #+#    #+#             */
/*   Updated: 2023/12/14 16:23:49 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_int(int n)
{
	char	*str;
	size_t	count;

	if (n == 0)
	{
		count = ft_print_char('0');
		return (count);
	}
	str = ft_itoa(n);
	if (!str)
		return (0);
	count = ft_print_str(str);
	free(str);
	return (count);
}
