/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 10:26:59 by csturm            #+#    #+#             */
/*   Updated: 2023/05/29 17:11:55 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{	
		write(1, &str[i], 1);
		++i;
	}
}

/*
int	main(void)
{
	ft_putstr("This is a string.");
	return (0);
}
*/
