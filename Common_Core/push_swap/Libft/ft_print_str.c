/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:59:48 by csturm            #+#    #+#             */
/*   Updated: 2023/12/14 16:24:04 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_str(char *str)
{
	if (str == NULL)
	{
		ft_print_str("(null)");
		return (6);
	}
	else
		write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}
