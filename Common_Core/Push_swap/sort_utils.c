/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2023/12/12 14:49:50 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int longest_index(struct s_stack **stack_a)
{
    struct s_stack  *tmp;
    int             first_one;
    int             i;
    
    tmp = *stack_a;
    first_one = 32;
    while (tmp != NULL)
    {
        i = 0;
        while (tmp->index_s[i])
        {
            if (tmp->index_s[i] == '1')
                break;
            i++;
        }
        if (first_one > i)
            first_one = i;
        tmp = tmp->next;
    }
    return (first_one);
}

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
        if (min_index <= index / 2)
            ra(stack_a);
        else
            rra(stack_a);
    }
}
