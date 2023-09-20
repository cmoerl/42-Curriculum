/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:59:22 by csturm            #+#    #+#             */
/*   Updated: 2023/05/29 16:11:12 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <unistd.h>
#include <stdio.h>
*/

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 1;
	while (i < size - 1)
	{
		if (tab[i] > tab[j])
		{
			temp = tab[i];
			tab[i] = tab[j];
			tab[j] = temp;
			i = 0;
			j = 1;
		}
		else
		{
			i++;
			j++;
		}
	}
}

/*
int     main(void)
{
        int     tab[6] = {-2, 100, 2, 56, 14, 10090};
        for(int i = 0; i < 6; i++)
        {
                printf("%i ",tab[i]);
        }
        ft_sort_int_tab(tab,6);
         for(int i = 0; i < 6; i++)
        {
                printf("%i ",tab[i]);
        }
}
*/
