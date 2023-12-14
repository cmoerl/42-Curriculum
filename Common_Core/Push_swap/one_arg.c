/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2023/12/14 18:12:29 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	one_nb(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (0);
		i++;
	}
	return (1);
}

static int	check_one_arg(char *str)
{
	int	i;

	i = 0;
	if (only_space(str))
		return (0);
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '-' && str[i] != '+'
			&& (str[i] < '0' || str[i] > '9'))
			return (0);
		i++;
	}
	if (i == 0)
		return (0);
	return (1);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	size_of_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		i++;
	return (i);
}

int	fill_struct_one_arg(char **argv, struct s_stack **stack_a,
			struct s_stack **stack_b)
{
	char	**args;
	int		size;

	if (!check_one_arg(argv[1]))
		error(stack_a, stack_b);
	if (one_nb(argv[1]))
	{
		if (check_arg(argv[1]))
			error(stack_a, stack_b);
		else
			return (0);
	}
	args = ft_split(argv[1], ' ');
	if (!args)
		error(stack_a, stack_b);
	size = size_of_array(args);
	fill_struct_arr(size, args, stack_a, stack_b);
	free_array(args);
	return (1);
}
