/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2023/11/22 17:46:55 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_stack(struct s_stack **stack_a, struct s_stack **stack_b)
{
    push(stack_a, stack_b);
    push(stack_a, stack_b);
    push(stack_a, stack_b);
    rev_rotate(stack_a);
    rotate(stack_b);
    swap(stack_a);
    swap(stack_b);
    printf("stack a:\n");
    while (*stack_a != NULL)
    {
        printf("%d\n", (*stack_a)->number);
        *stack_a = (*stack_a)->next;
    }
    printf("\nstack b:\n");
    while (*stack_b != NULL)
    {
        printf("%d\n", (*stack_b)->number);
        *stack_b = (*stack_b)->next;
    }
}
