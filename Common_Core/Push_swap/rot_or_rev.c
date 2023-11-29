/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_or_rev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:36:49 by csturm            #+#    #+#             */
/*   Updated: 2023/11/29 17:35:30 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
    if (index_first + 1 < index - index_last)
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
    if (index_first + 1 < index - index_last)
        return (1);
    else
        return (0);
}
