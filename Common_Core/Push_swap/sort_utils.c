/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2023/11/28 18:27:13 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    min_to_top(struct s_stack **stack_a)
{
    struct s_stack  *tmp;
    int             min;
    int             index;
    int             min_index;

    tmp = *stack_a;
    min = tmp->number;
    index = 0;
    while (tmp != NULL)
    {
        if (tmp->number <= min)
        {
            min = tmp->number;
            min_index = index;
        }
        tmp = tmp->next;
        index++;
    }
    while ((*stack_a)->number != min)
    {
        if (min_index < index / 2)
            ra(stack_a);
        else
            rra(stack_a);
    }
    
}

int find_pivot(struct s_stack **stack)
{
    struct s_stack  *tmp;
    int             min;
    int             max;

    max = INT_MIN;
    min = INT_MAX;
    tmp = *stack;
    while(tmp != NULL)
    {
        if (tmp->number > max)
            max = tmp->number;
        if (tmp->number < min)
            min = tmp->number;
        tmp = tmp->next;
    }
    return ((max + min) / 2);
}

void    next_to_top(struct s_stack **stack_a, int pivot)
{
    struct s_stack  *tmp;

    tmp = *stack_a;
    while (tmp->number > pivot)
    {
        
    }
}
