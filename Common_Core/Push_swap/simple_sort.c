/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2023/11/22 17:46:55 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_three(struct s_stack **stack)
{
    while(!is_sorted(stack))
    {
        if ((*stack)->number > (*stack)->next->number && (*stack)->number > (*stack)->next->next->number)
            rotate(stack);
        else if ((*stack)->number > (*stack)->next->number && (*stack)->number < (*stack)->next->next->number)
            swap(stack);
        else
            rotate(stack);
    }
}

void    sort_four(struct s_stack **stack_a, struct s_stack **stack_b)
{
    while(!is_sorted(stack_a) && stack_b != NULL)
    {
        
    }
}