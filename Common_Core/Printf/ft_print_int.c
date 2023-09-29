/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:02:35 by csturm            #+#    #+#             */
/*   Updated: 2023/09/29 10:51:47 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

int	ft_print_int(int n)
{
	char	*str;
	size_t	count;

	str = ft_itoa(n);
	count = ft_print_str(str);
	free(str);
	return (count);
}
