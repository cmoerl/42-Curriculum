/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:16:05 by csturm            #+#    #+#             */
/*   Updated: 2023/11/02 17:47:06 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *buffer;
static char *left_over;

void    fill_line(int fd, t_gnl *s)
{
    int     bytes_read;
    char    *newline_pos;
    int     i;

    i = 0;
    while (1)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read <= 0)
            return ;
        if (buffer == NULL)
            break ;
        buffer[bytes_read] = '\0';
        s->line = ft_strjoin(s->line, buffer);
        if (s->line == NULL)
            return ;
        newline_pos = ft_strchr(s->line, '\n');
        if (newline_pos != NULL)
        {
            left_over = malloc(BUFFER_SIZE + 1);
            if (left_over == NULL)
            {
                free(buffer);
                free(s->line);
                return ;
            }
            s->end_line = newline_pos + 1;
            while (s->end_line[i] != '\0')
            {
                left_over[i] = s->end_line[i];               
                i++;
            }
            left_over[i] = '\0';
            *s->end_line = '\0';
            return ;
        }
    }
}

char	*get_next_line(int fd)
{
    t_gnl   s;

    if (buffer == NULL)
    {
        buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
        if (buffer == NULL)
            return (NULL);
        buffer[0] = '\0';
    }
    s.line = malloc(1);
    if (!s.line)
    {
        free(buffer);
        free(left_over);
        return (NULL);
    }
    s.line[0] = '\0';
    if (left_over != NULL)
    {
        s.line = ft_strjoin(s.line, left_over);
        left_over = NULL;
    }
    fill_line(fd, &s);
    return (s.line);
}

/*
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	file_des;
	int	i;

	i = 0;
	file_des = open ("testfile.txt", O_RDONLY);
	while (i < 5)
	{
		printf("%s", get_next_line(file_des));
		i++;
	}
	return (0);
}
*/