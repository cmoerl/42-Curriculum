/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2023/11/27 18:07:57 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    min_to_top(struct s_stack **stack)
{
    struct s_stack  *tmp;
    int             min;
    int             index;
    int             min_index;

    tmp = *stack;
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
    while ((*stack)->number != min)
    {
        if (min_index < index / 2)
            rotate(stack);
        else
            rev_rotate(stack);
    }
    
}
