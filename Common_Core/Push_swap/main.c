/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2023/12/12 14:47:39 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_stack* create_node(int arg, struct s_stack **stack_a, struct s_stack **stack_b, int index_n, char *index_s)
{
    struct s_stack* new_node;

    new_node = malloc(sizeof(struct s_stack));
    if (!new_node)
        error(stack_a, stack_b);
    new_node->number = arg;
    new_node->index_n = index_n;
    new_node->index_s = index_s;
    new_node->next = NULL;
    return (new_node);
}

void    fill_struct(int argc, char **argv, struct s_stack **stack_a, struct s_stack **stack_b)
{
    struct s_stack  *tmp;
    int             i;

    i = 1;
    while (i < argc)
    {
        if (check_arg(argv[i]))
            error(stack_a, stack_b);
        if (i == 1)
        {
            *stack_a = create_node(ft_atoi(argv[i]), stack_a, stack_b, -1, NULL);
            tmp = *stack_a;
        }
        else if (i < argc)
            (*stack_a)->next = create_node(ft_atoi(argv[i]), stack_a, stack_b, -1, NULL);
        else
            (*stack_a)->next = NULL;
        if ((*stack_a)->next != NULL)
            *stack_a = (*stack_a)->next;
        i++;
    }
    *stack_a = tmp;
}

int main(int argc, char **argv)
{
    struct s_stack   *stack_a;
    struct s_stack   *stack_b;

    stack_a = NULL;
    stack_b = NULL;
    if (argc < 2)
        error(&stack_a, &stack_b);
    fill_struct(argc, argv, &stack_a, &stack_b);
    find_dup(&stack_a, &stack_b);
    sort_stack(argc, &stack_a, &stack_b);
    free_stack(&stack_a);
    free_stack(&stack_b);
    return 0;
}
