/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2023/12/12 15:33:59 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	convert_indexes(struct s_stack **stack_a)
{
	struct s_stack	*tmp;
	char			*index_bin;
	int				i;

	tmp = *stack_a;
	while (tmp != NULL)
	{
		i = 31;
		index_bin = malloc(32 + 1);
		if (!index_bin)
			return ;
		while (i >= 0)
		{
			index_bin[i] = (tmp->index_n & 1) + '0';
			tmp->index_n >>= 1;
			i--;
		}
		index_bin[32] = '\0';
		tmp->index_s = index_bin;
		tmp = tmp->next;
	}
}

static void	implement_index(struct s_stack **stack_a, int value, int index)
{
	struct s_stack	*tmp;

	tmp = *stack_a;
	while (tmp != NULL)
	{
		if (tmp->number == value)
			tmp->index_n = index;
		tmp = tmp->next;
	}
}

static long	find_min(struct s_stack **stack_a, long old_min)
{
	struct s_stack	*tmp;
	long			new_min;

	tmp = *stack_a;
	new_min = 2147483648;
	while (tmp != NULL)
	{
		if ((long)tmp->number < new_min && (long)tmp->number > old_min)
			new_min = (long)tmp->number;
		tmp = tmp->next;
	}
	return (new_min);
}

static int	all_indexes_given(struct s_stack **stack_a)
{
	struct s_stack	*tmp;

	tmp = *stack_a;
	while (tmp->next != NULL)
	{
		if (tmp->index_n < 0)
			return (0);
		tmp = tmp->next;
	}
	if (tmp->index_n < 0)
		return (0);
	else
		return (1);
}

void	give_indexes(struct s_stack **stack_a)
{
	long	min;
	int		index;

	min = -2147483649;
	index = 0;
	while (!all_indexes_given(stack_a))
	{
		min = find_min(stack_a, min);
		implement_index(stack_a, (int)min, index);
		index++;
	}
}
