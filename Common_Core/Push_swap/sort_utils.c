/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2023/12/04 18:58:53 by csturm           ###   ########.fr       */
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

void    max_to_top(struct s_stack **stack_b)
{
    struct s_stack  *tmp;
    int             max;
    int             index;
    int             max_index;

    tmp = *stack_b;
    max = tmp->number;
    index = 0;
    while (tmp != NULL)
    {
        if (tmp->number >= max)
        {
            max = tmp->number;
            max_index = index;
        }
        tmp = tmp->next;
        index++;
    }
    if (max_index <= index - max_index)
    {
        while (max_index > 0)
        {
            rb(stack_b);
            max_index--;
        }
    }
    else
    {
        while (index - max_index > 0)
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
    index = 0;
    while (tmp->next != NULL && tmp->number >= pivot)
    {
        tmp = tmp->next;
        index++;
    }
    if (tmp->next == NULL && tmp->number >= pivot)
        return (0);
    index_first = index;
    index_last = index;
    while (tmp->next != NULL)
    {
        if (tmp->number < pivot)
            index_last = index;
        tmp = tmp->next;
        index++;
    }
    move_to_top(stack_a, index_first, index_last, index);
    return (1);
}
