/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_operations_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2023/11/28 15:00:25 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ra(struct s_stack **stack_a)
{
    ft_printf("ra\n");
    rotate(stack_a);
}

void    rb(struct s_stack **stack_b)
{
    ft_printf("rb\n");
    rotate(stack_b);
}

void    rr(struct s_stack **stack_a, struct s_stack **stack_b)
{
    ft_printf("rr\n");
    rotate(stack_a);
    rotate(stack_b);
}
