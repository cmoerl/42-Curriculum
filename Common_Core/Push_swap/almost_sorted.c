/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   almost_sorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2023/12/04 18:47:09 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int almost_sorted_a(struct s_stack **stack_a)
{
    struct s_stack *tmp;

    tmp = *stack_a;
    while (tmp->next != NULL)
    {
        if (tmp->number > tmp->next->number && (!is_max(tmp->number, stack_a) || !is_min(tmp->next->number, stack_a)))
            return (0);
        tmp = tmp->next;
    }
    if (tmp->number > (*stack_a)->number && (!is_max(tmp->number, stack_a) || !is_min((*stack_a)->number, stack_a)))
        return (0);
    return (1);
}

int almost_sorted_b(struct s_stack **stack_b)
{
    struct s_stack *tmp;

    tmp = *stack_b;
    while (tmp->next != NULL)
    {
        if (tmp->number < tmp->next->number && (!is_min(tmp->number, stack_b) || !is_max(tmp->next->number, stack_b)))
            return (0);
        tmp = tmp->next;
    }
    if (tmp->number < (*stack_b)->number && (!is_min(tmp->number, stack_b) || !is_max((*stack_b)->number, stack_b)))
        return (0);
    return (1);
}

void    sort_stack_a(struct s_stack **stack_a)
{
    int moves;
    
    while (!is_sorted(stack_a))
    {
        if (almost_sorted_a(stack_a))
            min_to_top(stack_a);
        else if ((*stack_a)->number > (*stack_a)->next->number && (!is_max((*stack_a)->number, stack_a) || !is_min((*stack_a)->next->number, stack_a)))
            sa(stack_a);
        else
        {
            moves = rot_or_rev_a(stack_a);
            while (moves > 0)
            {
                ra(stack_a);
                moves--;
            }
            while (moves < 0)
            {
                rra(stack_a);
                moves++;
            }
        }
    }
}

void    sort_stack_b(struct s_stack **stack_a, struct s_stack **stack_b)
{
    int moves;
    
    while (*stack_b != NULL)
    {
        if (is_max((*stack_b)->number, stack_b))
            pa(stack_a, stack_b);
        else if (almost_sorted_b(stack_b))
        {
            max_to_top(stack_b);
            break ;
        }
        else if ((*stack_b)->number < (*stack_b)->next->number && (!is_min((*stack_b)->number, stack_b) || !is_max((*stack_b)->next->number, stack_b)))
            sb(stack_b);
        else
        {
            moves = rot_or_rev_b(stack_b);
            if (moves > 0)
                rb(stack_b);
            else if (moves < 0)
                rrb(stack_b);
        }
    }
}
