/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2023/12/14 18:11:55 by csturm           ###   ########.fr       */
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

struct s_stack	*handle_node(struct s_stack **stack_a,
					struct s_stack **stack_b, int arg)
{
	struct s_stack	*new_node;

	new_node = create_node(arg, -1, NULL);
	if (!new_node)
		error(stack_a, stack_b);
	return (new_node);
}

void	fill_struct_arr(int argc, char **argv, struct s_stack **stack_a,
				struct s_stack **stack_b)
{
	struct s_stack	*tmp;
	int				i;

	i = argc - 1;
	while (i >= 0)
	{
		if (check_arg(argv[i]))
		{
			free_array(argv);
			error(stack_a, stack_b);
		}
		tmp = handle_node(stack_a, stack_b, ft_atoi(argv[i]));
		tmp->next = *stack_a;
		*stack_a = tmp;
		i--;
	}
}

void	fill_struct(int argc, char **argv, struct s_stack **stack_a,
				struct s_stack **stack_b)
{
	struct s_stack	*tmp;
	int				i;

	i = argc - 1;
	while (i >= 1)
	{
		if (check_arg(argv[i]))
			error(stack_a, stack_b);
		tmp = handle_node(stack_a, stack_b, ft_atoi(argv[i]));
		tmp->next = *stack_a;
		*stack_a = tmp;
		i--;
	}
}

int	main(int argc, char **argv)
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (1);
	else if (argc == 2)
	{
		if (!fill_struct_one_arg(argv, &stack_a, &stack_b))
			return (0);
		argc = get_size(&stack_a) + 1;
	}
	else
		fill_struct(argc, argv, &stack_a, &stack_b);
	find_dup(&stack_a, &stack_b);
	sort_stack(argc, &stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
