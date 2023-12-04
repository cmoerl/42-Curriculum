/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2023/11/28 14:50:14 by csturm           ###   ########.fr       */
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

int unsorted_rot(struct s_stack **stack_a, struct s_stack **stack_b)
{ printf("unsorted_rot\n");
    struct s_stack  *tmp_a;
    struct s_stack  *tmp_b;
    int             index;

    tmp_a = *stack_a;
    tmp_b = *stack_b;
    index = 0;
    while (tmp_a->next != NULL && tmp_b->next != NULL)
    {
        if (tmp_a->number > tmp_a->next->number && tmp_b->number < tmp_b->next->number
            &&(!is_max(tmp_a->number, stack_a) && !is_min(tmp_a->next->number, stack_a))
            &&(!is_min(tmp_b->number, stack_b) && !is_max(tmp_b->next->number, stack_b)))
            return (index);
        tmp_a = tmp_a->next;
        tmp_b = tmp_b->next;
        index++;
    }
    return (-1);
}

int unsorted_rev(struct s_stack **stack_a, struct s_stack **stack_b)
{ printf("unsorted_rev\n");
    struct s_stack  *tmp_a;
    struct s_stack  *tmp_b;
    int             size_a;
    int             size_b;
    int             index;

    size_a = get_size(stack_a);
    size_b = get_size(stack_b);
    while (size_a > size_b)
    {
        tmp_a = tmp_a->next;
        size_a--;
    }
    while (size_b > size_a)
    {
        tmp_b = tmp_b->next;
        size_b--;
    }
    index = -1;
    while (tmp_a->next != NULL && tmp_b->next != NULL)
    {
        if (tmp_a->number > tmp_a->next->number && tmp_b->number < tmp_b->next->number
            && (!is_max(tmp_a->number, stack_a) && !is_min(tmp_a->next->number, stack_a))
            && (!is_min(tmp_b->number, stack_b) && !is_max(tmp_b->next->number, stack_b)))
            index = size_a;
        size_a--;
        tmp_a = tmp_a->next;
        tmp_b = tmp_b->next;
    }
    return (index);
}

void    separate_to_top(struct s_stack **stack_a, struct s_stack **stack_b)
{ printf("separate_to_top\n");
    int move_a;
    int move_b;

    move_a = rot_or_rev_a(stack_a);
    move_b = rot_or_rev_b(stack_b);
    while (move_a > 0)
    {
        ra(stack_a);
        move_a--;
    }
    while (move_a < 0)
    {
        rra(stack_a);
        move_a++;
    }
    while (move_b > 0)
    {
        rb(stack_b);
        move_b--;
    }
    while (move_b < 0)
    {
        rrb(stack_b);
        move_b++;
    }
}