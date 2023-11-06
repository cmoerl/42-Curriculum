#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char    *get_next_line(int fd);
char    *fill_left_over(int fd, char *left_over);
char    *ft_strchr(char *str, int c);
char    *ft_strjoin(char *left_over, char *buffer);
char    *fill_line(char *left_over);
char    *new_left_over(char *left_over);
size_t  ft_strlen(char *str);

#endif