/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_operations_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2023/12/04 16:09:33 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sa(struct s_stack **stack_a)
{
    ft_printf("sa\n");
    swap(stack_a);
}

void    sb(struct s_stack **stack_b)
{
    ft_printf("sb\n");
    swap(stack_b);
}

void    ss(struct s_stack **stack_a, struct s_stack **stack_b)
{
    ft_printf("ss\n");
    swap(stack_a);
    swap(stack_b);
}

void    pa(struct s_stack **stack_a, struct s_stack **stack_b)
{
    ft_printf("pa\n");
    push(stack_b, stack_a);
}

void    pb(struct s_stack **stack_a, struct s_stack **stack_b)
{
    ft_printf("pb\n");
    push(stack_a, stack_b);
}