/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:09:33 by csturm            #+#    #+#             */
/*   Updated: 2023/05/29 14:56:45 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <unistd.h>
#include <stdio.h>
*/

void	ft_rev_int_tab(int *tab, int size)
{
	int	a;
	int	b;
	int	temp;

	a = size - 1;
	b = 0;
	while (b < a)
	{
		temp = tab[b];
		tab[b] = tab[a];
		tab[a] = temp;
		a--;
		b++;
	}
}

/*
int	main(void)
{
	int	tab[4] = {1, 2, 3, 4};
	for(int i = 0; i < 4; i++)
	{
		printf("%i ",tab[i]);
	}
	ft_rev_int_tab(tab,4);
	 for(int i = 0; i < 4; i++)
        {
                printf("%i ",tab[i]);
        }
}
*/
