/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2023/12/13 16:44:31 by csturm           ###   ########.fr       */
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
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '-' && str[i] != '+'
			&& (str[i] < '0' || str[i] > '9'))
			return (0);
		i++;
	}
	return (1);
}

static void	free_array(char **array)
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

void	fill_struct_one_arg(char **argv, struct s_stack **stack_a,
			struct s_stack **stack_b)
{
	char	**args;
	int		size;

	if (!check_one_arg(argv[1]))
		error(stack_a, stack_b);
	if (one_nb(argv[1]))
		return ;
	args = ft_split(argv[1], ' ');
	if (!args)
		error(stack_a, stack_b);
	size = size_of_array(args);
	fill_struct_arr(size, args, stack_a, stack_b);
	free_array(args);
}
