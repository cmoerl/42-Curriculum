/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_operations_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2023/12/12 15:15:59 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(struct s_stack **stack_a)
{
	ft_printf("rra\n");
	rev_rotate(stack_a);
}

void	rrb(struct s_stack **stack_b)
{
	ft_printf("rrb\n");
	rev_rotate(stack_b);
}

void	rrr(struct s_stack **stack_a, struct s_stack **stack_b)
{
	ft_printf("rrr\n");
	rev_rotate(stack_a);
	rev_rotate(stack_b);
}
