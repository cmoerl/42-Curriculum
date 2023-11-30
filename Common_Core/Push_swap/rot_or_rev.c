/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_or_rev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:36:49 by csturm            #+#    #+#             */
/*   Updated: 2023/11/30 16:09:54 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_max(int index, struct s_stack **stack)
{
    struct s_stack  *tmp;
    int             max;
    int             number;
    int             i;

    tmp = *stack;
    i = 0;
    max = tmp->number;
    while (tmp->next != NULL && i < index)
    {
        if (tmp->number > max)
            max = tmp->number;
        tmp = tmp->next;
        i++;
    }
    number = tmp->number;
    while (tmp->next != NULL)
    {
        if (tmp->number > max)
            max = tmp->number;
        tmp = tmp->next;
    }
    if (max == number)
         return (1);
    return (0);
}

int find_min(int index, struct s_stack **stack)
{
    struct s_stack  *tmp;
    int             min;
    int             number;
    int             i;

    tmp = *stack;
    i = 0;
    min = tmp->number;
    while (tmp->next != NULL && i < index)
    {
        if (tmp->number < min)
            min = tmp->number;
        tmp = tmp->next;
        i++;
    }
    number = tmp->number;
    while (tmp->next != NULL)
    {
        if (tmp->number < min)
            min = tmp->number;
        tmp = tmp->next;
    }
    if (min == number)
         return (1);
    return (0);
}

int rot_or_rev_a(struct s_stack **stack_a)
{
    struct s_stack  *tmp;
    int             index;
    int             index_first;
    int             index_last;

    index = 0;
    tmp = *stack_a;
    while (tmp->next != NULL && tmp->number < tmp->next->number)
    {
        tmp = tmp->next;
        index++;
    }
    index_first = index;
    while (tmp->next != NULL)
    {
        if (tmp->number > tmp->next->number)
            index_last = index;
        tmp = tmp->next;
        index++;
    }
    if (index_first <= index - index_last && !find_max(index_first, stack_a) && !find_min(index_first, stack_a))
        return (1);
    else
        return (0);
}

int rot_or_rev_b(struct s_stack **stack_b)
{
    struct s_stack  *tmp;
    int             index;
    int             index_first;
    int             index_last;

    index = 0;
    tmp = *stack_b;
    while (tmp->next != NULL && tmp->number > tmp->next->number)
    {
        tmp = tmp->next;
        index++;
    }
    index_first = index;
    while (tmp->next != NULL)
    {
        if (tmp->number < tmp->next->number)
            index_last = index;
        tmp = tmp->next;
        index++;
    }
    if (index_first <= index - index_last && !find_min(index_first, stack_b) && !find_max(index_first, stack_b))
        return (1);
    else
        return (0);
}
