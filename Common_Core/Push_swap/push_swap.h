/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:27 by csturm            #+#    #+#             */
/*   Updated: 2023/11/27 18:41:54 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>

struct s_stack
{
    int                    number;
    struct s_stack         *next;
};

void    rev_rotate(struct s_stack **stack);
void    rotate(struct s_stack **stack);
void    push(struct s_stack **src, struct s_stack **dst);
void    swap(struct s_stack **stack);
int check_arg(char *str);
void    find_dup(struct s_stack **stack_a, struct s_stack **stack_b);
void    error(struct s_stack **stack_a, struct s_stack **stack_b);
void    free_stack(struct s_stack **stack);
void    print_stack(struct s_stack **stack_a, struct s_stack **stack_b);
int	ft_atoi(const char *nptr);
struct s_stack* create_node(int arg, struct s_stack **stack_a, struct s_stack **stack_b);
void    sort_four_five(int argc, struct s_stack **stack_a, struct s_stack **stack_b);
void    sort_three(struct s_stack **stack);
void    sort_stack(int argc, struct s_stack **stack_a, struct s_stack **stack_b);
void    sort_more(struct s_stack **stack_a, struct s_stack **stack_b);
int is_sorted(struct s_stack **stack);
void    min_to_top(struct s_stack **stack);

#endif