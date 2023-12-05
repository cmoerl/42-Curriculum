/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2023/12/05 18:12:09 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    unsorted_to_top(struct s_stack **stack_a, struct s_stack **stack_b)
{
    int rot_moves;
    int rev_moves;
    int moves_a;
    int moves_b;

    rot_moves = unsorted_rot(stack_a, stack_b);
    rev_moves = unsorted_rev(stack_a, stack_b);
    moves_a = moves_to_swap_a(stack_a);
    moves_b = moves_to_swap_b(stack_b);
    if (rot_moves >= 0 && (rev_moves < 0 || rot_moves <= rev_moves) && rot_moves <= moves_a + moves_b)
    {
        while (rot_moves > 0)
        {
            rr(stack_a, stack_b);
            rot_moves--;
        }
    }
    else if (rev_moves > 0 && (rot_moves < 0 || rot_moves > rev_moves) && rev_moves <= moves_a + moves_b)
    {
        while (rev_moves > 0)
        {
            rrr(stack_a, stack_b);
            rev_moves--;
        }
    }
    else
        separate_to_top(stack_a, stack_b);
}

void    sort_both_stacks(struct s_stack **stack_a, struct s_stack **stack_b)
{
    while (!is_sorted(stack_a) && !is_rev_sorted(stack_b))
    {
        if (almost_sorted_a(stack_a))
            min_to_top(stack_a);
        else if (almost_sorted_b(stack_b))
            max_to_top(stack_b);
        else if ((*stack_a)->number < (*stack_a)->next->number || (*stack_b)->number > (*stack_b)->next->number)
            unsorted_to_top(stack_a, stack_b);
        else
            ss(stack_a, stack_b);
    }
//    if (!is_sorted(stack_a))
//        sort_stack_a(stack_a);
//    else if (!is_rev_sorted(stack_b))
//        sort_stack_b(stack_a, stack_b);
}


void    sort_more(struct s_stack **stack_a, struct s_stack **stack_b)
{
    int pivot;
    int i;

    i = 0;
    pivot = find_pivot(stack_a);
    printf("pivot: %d\n", pivot);
    while(i < 3 && next_to_top(stack_a, pivot))
    {
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
