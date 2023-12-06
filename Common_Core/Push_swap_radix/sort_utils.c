/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2023/12/06 16:34:15 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_size(struct s_stack **stack)
{
    struct s_stack  *tmp;
    int             size;

    tmp = *stack;
    size = 1;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
        size++;
    }
    return (size);
}

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
