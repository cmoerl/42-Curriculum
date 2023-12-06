/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2023/12/06 15:44:08 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    move_to_top(struct s_stack **stack_a, int index_first, int index_last, int index)
{
    int front;
    int back;
    
    front = index_first;
    back = index - index_last;
    if (front <= back)
    {
        while (front > 0)
        {
            ra(stack_a);
            front--;
        }
    }
    else if (front > back)
    {
        while (back >= 0)
        {
            rra(stack_a);
            back--;
        }
    }
}

void    min_to_top(struct s_stack **stack_a)
{
    struct s_stack  *tmp;
    int             size;
    int             min_index;

    tmp = *stack_a;
    size = get_size(&tmp);
    while (!is_min(tmp->number, stack_a))
        tmp = tmp->next;
    min_index = tmp->index;
    if (min_index <= size - min_index)
    {
        while (min_index > 0)
        {
            ra(stack_a);
            min_index--;
        }
    }
    else
    {
        while (size - min_index > 0)
        {
            rra(stack_a);
            min_index++;
        }
    }
}

void    max_to_top(struct s_stack **stack_b)
{
    struct s_stack  *tmp;
    int             max_index;
    int             size;

    tmp = *stack_b;
    size = get_size(&tmp);
    while (!is_max(tmp->number, stack_b))
        tmp = tmp->next;
    max_index = tmp->index;
    if (max_index <= size - max_index)
    {
        while (max_index > 0)
        {
            rb(stack_b);
            max_index--;
        }
    }
    else
    {
        while (size - max_index > 0)
        {
            rrb(stack_b);
            max_index++;
        }
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

int    next_to_top(struct s_stack **stack_a, int pivot)
{
    struct s_stack  *tmp;
    int             index;
    int             index_first;
    int             index_last;

    tmp = *stack_a;
    while (tmp->next != NULL && tmp->number >= pivot)
        tmp = tmp->next;
    if (tmp->next == NULL && tmp->number >= pivot)
        return (0);
    index_first = tmp->index;
    index_last = index_first;
    while (tmp->next != NULL)
    {
        if (tmp->number < pivot)
            index_last = tmp->index;
        tmp = tmp->next;
    }
    move_to_top(stack_a, index_first, index_last, tmp->index + 1);
    return (1);
}
