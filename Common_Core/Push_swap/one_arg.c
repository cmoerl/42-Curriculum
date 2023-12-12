/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2023/12/12 17:14:00 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int  one_nb(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == ' ')
            return (0);
        i++;
    }
    return (1);
}

static int  check_one_arg(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] != ' ' && str[i] != '-' && str[i] != '+' && (str[i] < '0' || str[i] > '9'))
            return (0);
        i++;
    }
    return (1);
}

static void free_array(char **array)
{
    int i;
    
    i = 0;
    while (array[i])
    {
        free(array[i]);
        i++;
    }
    free(array);
}

void    fill_struct_one_arg(char **argv, struct s_stack **stack_a, struct s_stack **stack_b)
{
    struct s_stack  *tmp;
    char            **args;
    int             i;

    if (!check_one_arg(argv[1]))
        error(stack_a, stack_b);
    if (one_nb(argv[1]))
        return ;
    args = ft_split(argv[1], ' ');
    if (!args)
        error(stack_a, stack_b);
    i = 0;
    while (args[i])
    {
        if (i == 0)
        {
            *stack_a = handle_node(stack_a, stack_b, ft_atoi(args[i]));
            tmp = *stack_a;
        }
        else
            *stack_a = handle_node(stack_a, stack_b, ft_atoi(args[i]));
        if ((*stack_a)->next != NULL)
            *stack_a = (*stack_a)->next;
        i++;
    }
    *stack_a = tmp;
    free_array(args);
}
