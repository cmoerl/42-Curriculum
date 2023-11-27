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

void    sort_stack(int argc, struct s_stack **stack_a, struct s_stack **stack_b)
{
    if (is_sorted(stack_a))
        return ;
    if (argc <= 6)
    {
        if (argc == 2)
            return ;
        else if (argc == 3)
            swap(stack_a);
        else if (argc == 4)
            sort_three(stack_a);
        else if (argc == 5)
            sort_four(stack_a, stack_b);
        else
            sort_five(stack_a, stack_b);
    }
    else
        sort_more(stack_a, stack_b);
}

void    sort_more(struct s_stack **stack_a, struct s_stack **stack_b)
{
    int pivot;
    int i;

    i = 0;
    pivot = find_pivot(stack_a);
    while(i < 3)
    {
        if ((*stack_a)->number < pivot)
        {
            push(stack_a, stack_b);
            i++;
        }
        else
            rotate(stack_a);
    }
    if (!is_rev_sorted(stack_b))
        sort_three(stack_b);
    while (next_to_top(stack_a, pivot))
    {
        max_to_top(stack_b);
        push(stack_a, stack_b);
    }
    sort_both_stacks(stack_a, stack_b);
    while (*stack_b != NULL)
        push(stack_b, stack_a);
}

void    print_stack(struct s_stack **stack_a, struct s_stack **stack_b)
{
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
