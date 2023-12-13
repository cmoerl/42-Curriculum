/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2023/12/13 16:36:05 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(struct s_stack **stack)
{
	struct s_stack	*current;
	struct s_stack	*next;

	current = *stack;
	while (current != NULL)
	{
		next = current->next;
		free(current->index_s);
		free(current);
		current = next;
	}
	*stack = NULL;
}

void	error(struct s_stack **stack_a, struct s_stack **stack_b)
{
	ft_printf("Error\n");
	free_stack(stack_a);
	free_stack(stack_b);
	exit (1);
}

void	find_dup(struct s_stack **stack_a, struct s_stack **stack_b)
{
	struct s_stack	*begin;
	struct s_stack	*tmp;
	int				dup;

	begin = *stack_a;
	while ((*stack_a)->next != NULL)
	{
		dup = (*stack_a)->number;
		*stack_a = (*stack_a)->next;
		tmp = *stack_a;
		while (tmp != NULL)
		{
			if (tmp->number == dup)
				error(stack_a, stack_b);
			tmp = tmp->next;
		}
	}
	*stack_a = begin;
}

int	check_arg(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9' || i > 11)
			return (1);
		i++;
	}
	return (0);
}

void	check_limits(struct s_stack **stack_a, struct s_stack **stack_b)
{
	struct s_stack	*tmp;

	tmp = *stack_a;
	while (tmp != NULL)
	{
		if (tmp->number > INT_MAX || tmp->number < INT_MIN)
			error(stack_a, stack_b);
		tmp = tmp->next;
	}
}
