/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2023/11/21 18:47:32 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_stack* create_node(int arg, struct s_stack **stack_a, struct s_stack **stack_b)
{
    struct s_stack* new_node;

    new_node = malloc(sizeof(struct s_stack));
    if (!new_node)
        error(stack_a, stack_b);
    new_node->number = arg;
    new_node->next = NULL;
    return (new_node);
}

void    fill_struct(int argc, char **argv, struct s_stack **stack_a, struct s_stack **stack_b)
{
    int i;

    i = 1;
    while (i < argc)
    {
        if (check_arg(argv[i]))
            error(stack_a, stack_b);
        if (i < argc - 1)
            (*stack_a)->next = create_node(ft_atoi(argv[i]), stack_a, stack_b);
        else
            (*stack_a)->next = NULL;
        *stack_a = (*stack_a)->next;
        i++;
    }
}

int main(int argc, char **argv)
{
    struct s_stack   *stack_a;
    struct s_stack   *stack_b;

    stack_a = NULL;
    stack_b = NULL;
    if (argc < 2)
        error(stack_a, stack_b);
    fill_struct(argc, argv, &stack_a, &stack_b);
    find_dup(&stack_a, &stack_b);
    sort_stack(stack_a, stack_b);
    free_stack(stack_a);
    free_stack(stack_b);
    return 0;
}
