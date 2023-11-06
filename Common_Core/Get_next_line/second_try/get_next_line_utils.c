#include "get_next_line.h"
#include <stdio.h>

size_t  ft_strlen(char *str)
{
    size_t  i;

    i = 0;
    if (!str)
        return (0);
    while (str[i])
        i++;
    return (i);
}

char    *ft_strchr(char *str, int c)
{
    int i;

    i = 0;
    if (!str)
        return (NULL);
    if (c == '\0')
        return ((char *)&str[ft_strlen(str)]);
    while (str[i])
    {
        if (str[i] == (char)c)
            return ((char *)&str[i]);
        i++;
    }
    return (NULL);    
}

char    *ft_strjoin(char *left_over, char *buffer)
{
    size_t  i;
    size_t  j;
    char    *str;

    if (!left_over)
    {
        left_over = malloc(1);
        left_over[0] = '\0';
    }
    if (!left_over || !buffer)
        return (NULL);
    str = malloc(ft_strlen(left_over) + ft_strlen(buffer) + 1);
    if (!str)
        return (NULL);
    i = -1;
    j = 0;
    if (left_over)
    {
        while (left_over[i] != '\0')
        {
            str[i] = left_over[i];
            i++;
        }
    }
    while (buffer[j])
    {
        str[i] = buffer[j];
        i++;
        j++;
    }
    str[ft_strlen(left_over) + ft_strlen(buffer)] = '\0';
//    free(left_over);
    return (str);
}