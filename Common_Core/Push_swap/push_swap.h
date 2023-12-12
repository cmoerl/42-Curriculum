/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:27 by csturm            #+#    #+#             */
/*   Updated: 2023/12/12 14:47:15 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "Printf/ft_printf.h"
#include "Printf/Libft/libft.h"

struct s_stack
{
    int                    number;
    int                    index_n;
    char                   *index_s;
    struct s_stack         *next;
};

struct s_stack* create_node(int arg, struct s_stack **stack_a, struct s_stack **stack_b, int index_n, char *index_s);
void            rev_rotate(struct s_stack **stack);
void            rotate(struct s_stack **stack);
void            push(struct s_stack **src, struct s_stack **dst);
void            swap(struct s_stack **stack);
void            find_dup(struct s_stack **stack_a, struct s_stack **stack_b);
void            error(struct s_stack **stack_a, struct s_stack **stack_b);
void            free_stack(struct s_stack **stack);
void            sort_four_five(int argc, struct s_stack **stack_a, struct s_stack **stack_b);
void            sort_three(struct s_stack **stack);
void            sort_stack(int argc, struct s_stack **stack_a, struct s_stack **stack_b);
void            sort_more(struct s_stack **stack_a, struct s_stack **stack_b);
void            sa(struct s_stack **stack_a);
void            sb(struct s_stack **stack_b);
void            ss(struct s_stack **stack_a, struct s_stack **stack_b);
void            pa(struct s_stack **stack_a, struct s_stack **stack_b);
void            pb(struct s_stack **stack_a, struct s_stack **stack_b);
void            ra(struct s_stack **stack_a);
void            rb(struct s_stack **stack_b);
void            rr(struct s_stack **stack_a, struct s_stack **stack_b);
void            rra(struct s_stack **stack_a);
void            rrb(struct s_stack **stack_b);
void            rrr(struct s_stack **stack_a, struct s_stack **stack_b);
void            min_to_top(struct s_stack **stack_a);
void            give_indexes(struct s_stack **stack_a);
void            convert_indexes(struct s_stack **stack_a);
int             longest_index(struct s_stack **stack_a);
int             check_arg(char *str);
int             is_sorted(struct s_stack **stack);
int             get_size(struct s_stack **stack);

#endif