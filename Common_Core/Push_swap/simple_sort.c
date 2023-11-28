/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2023/11/28 18:22:01 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(struct s_stack **stack)
{
    struct s_stack  *tmp;

    tmp = *stack;
    while (tmp != NULL && tmp->next != NULL)
    {
        if (tmp->number > tmp->next->number)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

int is_rev_sorted(struct s_stack **stack)
{
    struct s_stack  *tmp;

    tmp = *stack;
    while (tmp != NULL && tmp->next != NULL)
    {
        if (tmp->number < tmp->next->number)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

void    sort_three(struct s_stack **stack_a)
{
    while(!is_sorted(stack_a))
    {
        if ((*stack_a)->number > (*stack_a)->next->number && (*stack_a)->number > (*stack_a)->next->next->number)
            ra(stack_a);
        else if ((*stack_a)->number > (*stack_a)->next->number && (*stack_a)->number < (*stack_a)->next->next->number)
            sa(stack_a);
        else
            rra(stack_a);
    }
}

void    sort_three_rev(struct s_stack **stack_b)
{
    while(!is_rev_sorted(stack_b))
    {
        if ((*stack_b)->number < (*stack_b)->next->number && (*stack_b)->number < (*stack_b)->next->next->number)
            rb(stack_b);
        else if ((*stack_b)->number < (*stack_b)->next->number && (*stack_b)->number > (*stack_b)->next->next->number)
            sb(stack_b);
        else
            rrb(stack_b);
    }
}

void    sort_four_five(int argc, struct s_stack **stack_a, struct s_stack **stack_b)
{
    min_to_top(stack_a);
    if (!is_sorted(stack_a))
    {
        pb(stack_a, stack_b);
        if (argc == 6)
        {
            min_to_top(stack_a);
            pb(stack_a, stack_b);
        }
        sort_three(stack_a);
        pa(stack_a, stack_b);
        if (argc == 6)
            pa(stack_a, stack_b);
    }
}
