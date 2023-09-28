#ifndef PRINTF_H
#define PRINTF_H

int ft_printf(const char *format, ...);
void    ft_print_char(int c);
void    ft_print_hex(unsigned int n, int up);
void    ft_print_int(int n);
void    ft_print_ptr(void *ptr);
void    ft_print_str(char *str);

#endif