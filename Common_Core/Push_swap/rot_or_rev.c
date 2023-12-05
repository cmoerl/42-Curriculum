/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_or_rev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2023/12/05 15:20:52 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_max(int max, struct s_stack **stack)
{
    struct s_stack  *tmp;

    tmp = *stack;
    while (tmp->next != NULL)
    {
        if (tmp->number > max)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

int is_min(int min, struct s_stack **stack)
{
    struct s_stack  *tmp;

    tmp = *stack;
    while (tmp->next != NULL)
    {
        if (tmp->number < min)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

int rot_or_rev_a(struct s_stack **stack_a)
{
    struct s_stack  *tmp;
    int             index;
    int             index_first;
    int             index_last;

    tmp = *stack_a;
    index = 0;
    while (tmp->number < tmp->next->number || (is_max(tmp->number, stack_a) && is_min(tmp->next->number, stack_a)))
    {
        tmp = tmp->next;
        index++;
    }
    index_first = index;
    index_last = index;
    while (tmp->next != NULL)
    {
        if (tmp->number > tmp->next->number && (!is_max(tmp->number, stack_a) || !is_min(tmp->next->number, stack_a)))
            index_last = index;
        tmp = tmp->next;
        index++;
    }
    index++;
    if (index_first > 1 && tmp->number > (*stack_a)->number && (!is_max(tmp->number, stack_a) || !is_min((*stack_a)->number, stack_a)))
        return (-1);
    else if (index_first <= index - index_last)
        return (index_first);
    else
        return ((index - index_last) * (-1));
}

int rot_or_rev_b(struct s_stack **stack_b)
{
    struct s_stack  *tmp;
    int             index;
    int             index_first;
    int             index_last;

    tmp = *stack_b;
    index = 0;
    while (tmp->number > tmp->next->number || (is_min(tmp->number, stack_b) && is_max(tmp->next->number, stack_b)))
    {
        tmp = tmp->next;
        index++;
    }
    index_first = index;
    index_last = index;
    while (tmp->next != NULL)
    {
        if (tmp->number < tmp->next->number && (!is_min(tmp->number, stack_b) || !is_max(tmp->next->number, stack_b)))
            index_last = index;
        tmp = tmp->next;
        index++;
    }
    index++;
    if (index_first > 1 && tmp->number < (*stack_b)->number && (!is_min(tmp->number, stack_b) || !is_max((*stack_b)->number, stack_b)))
        return (-1);
    else if (index_first <= index - index_last)
        return (index_first);
    else
        return ((index - index_last) * (-1));
}
