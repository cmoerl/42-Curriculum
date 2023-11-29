/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2023/11/29 17:48:52 by csturm           ###   ########.fr       */
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
            sa(stack_a);
        else if (argc == 4)
            sort_three(stack_a);
        else
            sort_four_five(argc, stack_a, stack_b);
    }
    else
        sort_more(stack_a, stack_b);
}

void    sort_both_stacks(struct s_stack **stack_a, struct s_stack **stack_b)
{
    while (!is_sorted(stack_a) && !is_rev_sorted(stack_b))
    {
        if ((*stack_a)->number > (*stack_a)->next->number && (*stack_b)->number < (*stack_b)->next->number)
            ss(stack_a, stack_b);
        else if(rot_or_rev_a(stack_a) && rot_or_rev_b(stack_b))
            rr(stack_a, stack_b);
        else
            rrr(stack_a, stack_b);
    }
//    if (!is_sorted(stack_a))
//        sort_stack_a(stack_a);
//    else if (!is_rev_sorted(stack_b))
//        sort_stack_b(stack_b);
}


void    sort_more(struct s_stack **stack_a, struct s_stack **stack_b)
{
    int pivot;
    int i;

    i = 0;
    pivot = find_pivot(stack_a);
    printf("pivot: %d\n", pivot);
    while(i < 3)
    {
        next_to_top(stack_a, pivot);
        pb(stack_a, stack_b);
        i++;
    }
    if (!is_rev_sorted(stack_b))
        sort_three_rev(stack_b);
    while (next_to_top(stack_a, pivot))
    {
        max_to_top(stack_b);
        pb(stack_a, stack_b);
    }
    sort_both_stacks(stack_a, stack_b);
//    while (*stack_b != NULL)
//        pa(stack_a, stack_b);
}


void    print_stack(struct s_stack **stack_a, struct s_stack **stack_b)
{
    struct s_stack  *tmp_a;
    struct s_stack  *tmp_b;
    
    tmp_a = *stack_a;
    tmp_b = *stack_b;
    printf("\nstack a:\n");
    while (tmp_a != NULL)
    {
        printf("%d\n", tmp_a->number);
        tmp_a = tmp_a->next;
    }
    printf("\nstack b:\n");
    while (tmp_b != NULL)
    {
        printf("%d\n", tmp_b->number);
        tmp_b = tmp_b->next;
    }
}
