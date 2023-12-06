/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2023/12/06 17:18:06 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_more(struct s_stack **stack_a, struct s_stack **stack_b)
{
    int digit;
    give_indexes(stack_a);
    convert_indexes(stack_a);
    digit = longest_index(stack_a);
    while (digit >= 0)
    {
        while (!all_ones(stack_a, digit))
        {
            if (push_or_rot(stack_a, digit))
                pb(stack_a, stack_b);
            else
                ra(stack_a);
        }
        while (stack_b != NULL)
            pa(stack_a, stack_b);
        digit--;        
    }
}

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
