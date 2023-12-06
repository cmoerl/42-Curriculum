/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2023/12/06 18:44:46 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    convert_indexes(struct s_stack **stack_a)
{
    struct s_stack  *tmp;
    long            new_index;
    int             i;

    tmp = *stack_a;
    while (tmp != NULL)
    {
        i = 0;
        new_index = 0;
        while (i < 32)
        {
            new_index <<= 1;
            if (tmp->index & (1 << i))
                new_index |= 1;
            i++;
        }
        tmp->index = new_index;
        if (tmp->next != NULL)
            tmp = tmp->next;
    }
}

static void    implement_index(struct s_stack **stack_a, int value, long index)
{
    struct s_stack  *tmp;

    tmp = *stack_a;
    while (tmp->next != NULL)
    {
        if (tmp->number == value)
            tmp->index = index;
        tmp = tmp->next;
    }
    if (tmp->number == value)
        tmp->index = index;
}

static int     find_min(struct s_stack **stack_a, long old_min)
{
    struct s_stack  *tmp;
    long             new_min;
    
    tmp = *stack_a;
    new_min = 2147483648;
    while (tmp->next != NULL)
    {
        if (tmp->number < new_min && tmp->number > old_min)
            new_min = tmp->number;
        tmp = tmp->next;
    }
    if (tmp->number < new_min && tmp->number > old_min)
        new_min = tmp->number;
    return (new_min);
}

static int     all_indexes_given(struct s_stack **stack_a)
{
    struct s_stack *tmp;

    tmp = *stack_a;
    while (tmp->next != NULL)
    {
        if (tmp->index < 0)
            return (0);
        tmp = tmp->next;
    }
    if (tmp->index < 0)
        return (0);
    else
        return (1);
}

void    give_indexes(struct s_stack **stack_a)
{
    long    min;
    long    index;
    
    min = -2147483649;
    index = 0;
    while (!all_indexes_given(stack_a))
    {
        min = find_min(stack_a, min);
        implement_index(stack_a, (int)min, index);
        index++;
    }
}