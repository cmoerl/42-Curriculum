/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:03:30 by csturm            #+#    #+#             */
/*   Updated: 2023/10/02 16:13:34 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_print_char(int c);
int	ft_print_hex(unsigned int n, int up);
int	ft_print_int(unsigned int n);
int	ft_print_ptr(void *p);
int	ft_print_str(char *str);
int	ft_printf(const char *format, ...);

#endif
