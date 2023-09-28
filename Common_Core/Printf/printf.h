/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:03:30 by csturm            #+#    #+#             */
/*   Updated: 2023/09/28 18:30:21 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_print_char(int c);
void	ft_print_hex(unsigned int n, int up);
void	ft_print_int(int n);
void	ft_print_ptr(void *ptr);
void	ft_print_str(char *str);
int		ft_printf(const char *format, ...);

#endif
