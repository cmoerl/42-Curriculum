/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2023/12/14 18:22:07 by csturm           ###   ########.fr       */
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
	struct s_stack	*tmp_1;
	struct s_stack	*tmp_2;
	int				dup;

	tmp_1 = *stack_a;
	while (tmp_1->next != NULL)
	{
		dup = tmp_1->number;
		tmp_1 = tmp_1->next;
		tmp_2 = tmp_1;
		while (tmp_2 != NULL)
		{
			if (tmp_2->number == dup)
				error(stack_a, stack_b);
			tmp_2 = tmp_2->next;
		}
	}
}

int	check_arg(char *str)
{
	long	tmp;
	int		i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && (ft_isdigit(str[i + 1])))
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9' || i > 11)
			return (1);
		i++;
	}
	if (i == 0)
		return (1);
	tmp = ft_atoi_long(str);
	if (tmp < INT_MIN || tmp > INT_MAX)
		return (1);
	return (0);
}
