/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:20:28 by csturm            #+#    #+#             */
/*   Updated: 2023/06/01 09:38:44 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || 126 < str[i])
		{
			write(1, "\\", 1);
			write(1, &"0123456789ABCDEF"[str[i] / 16], 1);
			write(1, &"0123456789ABCDEF"[str[i] % 16], 1);
		}
		else
		{
			write(1, &str[i], 1);
		}
		i++;
	}
}

/*
int	main(void)
{
	ft_putstr_non_printable("Hello, good to see \n you!");
	ft_putstr_non_printable("My Number:\n -4567");
	return (0);
}
*/
