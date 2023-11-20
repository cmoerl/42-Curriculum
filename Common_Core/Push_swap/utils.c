/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2023/11/20 16:28:06 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void    swap(t_stack **stack)
{
    t_stack    *one;
    t_stack    *two;

    if (stack != NULL && *stack != NULL && (*stack)->next != NULL)    
    {
        one = *stack;
        two = (*stack)->next;
        one->next = two->next;
        two->next = one;
        *stack = two;
    }
}