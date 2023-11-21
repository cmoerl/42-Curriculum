/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2023/11/21 18:50:55 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    find_dup(int argc, struct s_stack **stack_a, struct s_stack **stack_b)
{
    int tmp;
    
    while ((*stack_a)->next != NULL)
    {
        
    }
}

void    free_stack(struct s_stack **stack)
{
    struct s_stack  *current;
    struct s_stack  *next;
    
    current = *stack;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *stack = NULL;
}

int check_arg(char *str)
{
    int i;
    
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
