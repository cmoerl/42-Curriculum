/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2023/12/12 17:28:41 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_stack	*create_node(int arg, int index_n, char *index_s)
{
	struct s_stack	*new_node;

	new_node = malloc(sizeof(struct s_stack));
	if (!new_node)
		return (NULL);
	new_node->number = arg;
	new_node->index_n = index_n;
	new_node->index_s = index_s;
	new_node->next = NULL;
	return (new_node);
}

struct s_stack	*handle_node(struct s_stack **stack_a, struct s_stack **stack_b, int arg)
{
	struct s_stack	*new_node;

	new_node = create_node(arg, -1, NULL);
	if (!new_node)
		error(stack_a, stack_b);
	if ((*stack_a)->next == NULL)
	{
		(*stack_a)->next = new_node;
		new_node->next = NULL;
	}
	else
		(*stack_a)->next = new_node;
	return (new_node);
}

void	fill_struct(int argc, char **argv, struct s_stack **stack_a,
				struct s_stack **stack_b)
{
	struct s_stack	*tmp;
	int				i;

	i = 1;
	while (i < argc)
	{
		if (check_arg(argv[i]))
			error(stack_a, stack_b);
		if (i == 1)
		{
			*stack_a = handle_node(stack_a, stack_b, ft_atoi(argv[i]));
			tmp = *stack_a;
		}
		else
			*stack_a = handle_node(stack_a, stack_b, ft_atoi(argv[i]));
		if ((*stack_a)->next != NULL)
			*stack_a = (*stack_a)->next;
		i++;
	}
	*stack_a = tmp;
}

int	main(int argc, char **argv)
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		error(&stack_a, &stack_b);
	else if (argc == 2)
		fill_struct_one_arg(argv, &stack_a, &stack_b);
	else
		fill_struct(argc, argv, &stack_a, &stack_b);
	find_dup(&stack_a, &stack_b);
	check_limits(&stack_a, &stack_b);
	sort_stack(argc, &stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
