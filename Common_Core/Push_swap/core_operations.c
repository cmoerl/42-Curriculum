/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2023/12/06 15:22:45 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    correct_index(struct s_stack **stack)
{
    struct s_stack  *tmp;
    int             index;

    tmp = *stack;
    index = 0;
    while (tmp->next != NULL)
    {
        tmp->index = index;
        tmp = tmp->next;
        index++;
    }
    tmp->index = index;
}

void    swap(struct s_stack **stack)
{
    struct s_stack    *one;
    struct s_stack    *two;

    if (stack != NULL && *stack != NULL && (*stack)->next != NULL)    
    {
        one = *stack;
        two = (*stack)->next;
        one->next = two->next;
        two->next = one;
        *stack = two;
        (*stack)->index = 0;
        (*stack)->next->index = 1;
    }
}

void    push(struct s_stack **src, struct s_stack **dst)
{
    struct s_stack  *new_node;
    struct s_stack  *tmp;
    
    if (src != NULL && *src != NULL)
    {
        new_node = create_node((*src)->number, dst, NULL, 0);
        new_node->next = *dst;
        *dst = new_node;
        tmp = (*src)->next;
        free(*src);
        *src = tmp;
        correct_index(src);
        correct_index(dst);
    }
}

void    rotate(struct s_stack **stack)
{
    struct s_stack     *tmp;

    if (stack != NULL && *stack != NULL && (*stack)->next != NULL)
    {
        tmp = *stack;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = *stack;
        *stack = (*stack)->next;
        tmp->next->next = NULL;
    }
    correct_index(stack);
}

void    rev_rotate(struct s_stack **stack)
{
    struct s_stack     *begin;
    struct s_stack     *end;
    struct s_stack     *new;

    if (stack != NULL && *stack != NULL && (*stack)->next != NULL)
    {
        begin = *stack;
        end = *stack;
        while (end->next != NULL)
        {
            new = end;
            end = end->next;
        }
        new->next = NULL;
        end->next = begin;
        *stack = end;
    }
    correct_index(stack);
}
