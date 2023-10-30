/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:16:05 by csturm            #+#    #+#             */
/*   Updated: 2023/10/30 18:44:07 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t next_line;

void    fill_line(int fd, t_gnl *s)
{
    int     bytes_read;
    char    *newline_pos;
  
    while (1)
    {
        bytes_read = read(fd, s->buffer + next_line, BUFFER_SIZE);
        if (bytes_read < 0)
            return ;
        else if (bytes_read == 0)
            return ;
        if (s->buffer == NULL)
            break ;
        s->buffer[bytes_read] = '\0';
        s->line = ft_strjoin(s->line, s->buffer);
        if (s->line == NULL)
            return ;
        newline_pos = ft_strchr(s->line, '\n');
        if (newline_pos != NULL)
        {
            s->end_line = newline_pos + 1;
            *s->end_line = '\0';
            next_line = next_line + (s->end_line - s->line);
            return ;
        }
    }
}

char    *get_next_line(int fd)
{
    t_gnl   s;
    char    *tmp_buf;

    s.buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!s.buffer)
    {
        return (NULL);
    }
    s.buffer[BUFFER_SIZE] = '\0';
    s.line = malloc(1);
    if (!s.line)
    {
        free(s.buffer);
        return (NULL);
    }
    s.line[0] = '\0';
    if (!next_line)
        next_line = 0;
    fill_line(fd, &s);
    return (s.line);
}

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	file_des;
	int	i;

	i = 0;
	file_des = open ("testfile.txt", O_RDONLY);
	while (i < 4)
	{
		printf("%s", get_next_line(file_des));
		i++;
	}
	return (0);
}