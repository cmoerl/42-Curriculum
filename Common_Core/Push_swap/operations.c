/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2023/11/21 15:32:05 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
    }
}

void    push(struct s_stack **src, struct s_stack **dst)
{
    if (src != NULL && *src != NULL)
    {
        while((*dst)->next != NULL)
            *dst = (*dst)->next;
        (*dst)->next = *src;
        (*src)->number = (*dst)->number;
        *dst = *src;
        *src = (*src)->next;
        (*dst)->next = NULL;
    }
}

void    rotate(struct s_stack **stack)
{
    struct s_stack     *tmp;
    int                number;

    if (stack != NULL && *stack != NULL && (*stack)->next != NULL)
    {
        tmp = *stack;
        number = tmp->number;
        *stack = (*stack)->next;
        while ((*stack)->next != NULL)
            *stack = (*stack)->next;
        (*stack)->next = tmp;
        tmp->number = number;
        tmp->next = NULL;
    }
}

void    rev_rotate(struct s_stack **stack)
{
    struct s_stack     *tmp;
    int                number;

    if (stack != NULL && *stack != NULL && (*stack)->next != NULL)
    {
        tmp = *stack;
        number = tmp->number;
        *stack = (*stack)->next;
        while ((*stack)->next != NULL)
            *stack = (*stack)->next;
        tmp->next = *stack;
        tmp->number = number;
        *stack = tmp;
    }
}
