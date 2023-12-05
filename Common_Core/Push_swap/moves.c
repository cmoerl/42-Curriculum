/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2023/12/05 18:07:45 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int moves_to_swap_a(struct s_stack **stack_a)
{
    int moves;

    moves = rot_or_rev_a(stack_a);
    if (moves < 0)
        moves = moves * (-1);
    return (moves);
}

int moves_to_swap_b(struct s_stack **stack_b)
{
    int moves;

    moves = rot_or_rev_b(stack_b);
    if (moves < 0)
        moves = moves * (-1);
    return (moves);
}