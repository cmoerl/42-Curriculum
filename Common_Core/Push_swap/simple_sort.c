/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2023/11/27 18:41:39 by csturm           ###   ########.fr       */
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

void    sort_three(struct s_stack **stack)
{
    while(!is_sorted(stack))
    {
        if ((*stack)->number > (*stack)->next->number && (*stack)->number > (*stack)->next->next->number)
            rotate(stack);
        else if ((*stack)->number > (*stack)->next->number && (*stack)->number < (*stack)->next->next->number)
            swap(stack);
        else
            rev_rotate(stack);
    }
}

void    sort_four_five(int argc, struct s_stack **stack_a, struct s_stack **stack_b)
{
    min_to_top(stack_a);
    if (!is_sorted(stack_a))
    {
        push(stack_a, stack_b);
        if (argc == 6)
        {
            min_to_top(stack_a);
            push(stack_a, stack_b);
        }
        sort_three(stack_a);
        push(stack_b, stack_a);
        if (argc == 6)
            push(stack_b, stack_a);
    }
}
