/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2023/12/12 15:39:02 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_more(struct s_stack **stack_a, struct s_stack **stack_b)
{
	int	digit;
	int	last_digit;
	int	size;

	give_indexes(stack_a);
	convert_indexes(stack_a);
	last_digit = longest_index(stack_a);
	digit = 31;
	while (digit >= last_digit)
	{
		size = get_size(stack_a);
		while (size > 0)
		{
			if ((*stack_a)->index_s[digit] == '0')
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			size--;
		}
		while (*stack_b != NULL)
			pa(stack_a, stack_b);
		digit--;
	}
}

void	sort_stack(int argc, struct s_stack **stack_a, struct s_stack **stack_b)
{
	if (is_sorted(stack_a))
		return ;
	if (argc <= 6)
	{
		if (argc == 2)
			return ;
		else if (argc == 3)
			sa(stack_a);
		else if (argc == 4)
			sort_three(stack_a);
		else
			sort_four_five(argc, stack_a, stack_b);
	}
	else
		sort_more(stack_a, stack_b);
}
