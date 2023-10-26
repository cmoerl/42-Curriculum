/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:16:05 by csturm            #+#    #+#             */
/*   Updated: 2023/10/25 17:44:09 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char *next_line;

static void handle_error(t_gnl *s)
{
    free(s->buffer);
    free(s->line);
}

void    fill_line(int fd, t_gnl *s)
{
    int bytes_read;

    while (1)
    {
        bytes_read = read(fd, s->buffer, BUFFER_SIZE);
        if (bytes_read < 0)
        {
            handle_error(s);
            return ;
        }
        if (bytes_read == 0)
        {
            free(s->buffer);
            return ;
        }
        s->buffer[bytes_read] = '\0';
        s->line = ft_strjoin(s->line, s->buffer);
        if (s->line == NULL)
        {
            handle_error(s);
            return ;
        }
        if (ft_strchr(s->line, '\n') != NULL)
        {
            s->end_line = ft_strchr(s->line, '\n');
            *s->end_line = '\0';
            s->end_line++;
            next_line = s->end_line;
            return ;
        }
    }
}

char    *get_next_line(int fd)
{
    t_gnl    s;

    s.buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (s.buffer == NULL)
        return (NULL);
    s.line = (char *) malloc(1);
    if (s.line == 0)
    {
        free(s.buffer);
        return (NULL);
    }
    s.line[0] = '\0';
    if (next_line != NULL)
    {
        while (next_line)
        {
            *s.buffer++ = *next_line++;
            next_line = NULL;
        }
        printf("buffer: %s\n", s.buffer);
//        s.buffer = next_line;
//        next_line = NULL;
    }
    fill_line(fd, &s);
    free(s.buffer);
    if (s.line == NULL)
        return (NULL);
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
	while (i < 2)
	{
		printf("%s", get_next_line(file_des));
		i++;
	}
	return (0);
}