/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:14:49 by csturm            #+#    #+#             */
/*   Updated: 2024/07/03 15:20:34 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
    ft_printf("Hello, World!\n");
    ft_printf("%d\n", 42);
    ft_printf("%s\n", "Hello, World!");
    ft_printf("%c\n", 'c');
    ft_printf("%x\n", 42);
    ft_printf("%X\n", 42);
    ft_printf("%p\n", "Hello, World!");
    ft_printf("%u\n", 4294967295);
    ft_printf("%i\n", -42);
    ft_printf("%%\n");
    return (0);
}
