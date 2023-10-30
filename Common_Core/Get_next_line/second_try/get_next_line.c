/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:16:05 by csturm            #+#    #+#             */
/*   Updated: 2023/10/30 17:14:15 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char *next_line;

static void handle_error(t_gnl *s)
{
    free(s->buffer);
    s->buffer = NULL;
    free(s->line);
    s->line = NULL;
}

void    fill_line(int fd, t_gnl *s)
{
    int bytes_read;
    int len_line;
    char    *whole_line;

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
        if (s->buffer != NULL)
            s->line = ft_strjoin(s->line, s->buffer);
        else
            break ;
        if (s->line == NULL)
        {
            handle_error(s);
            return ;
        }
        if (ft_strchr(s->line, '\n') != NULL)
        {
            s->end_line = ft_strchr(s->line, '\n');
            s->new_line = s->end_line;
            *s->end_line = '\0';
            s->buffer = s->end_line + 1;
            s->end_line++;
            next_line = s->end_line;
            if (s->new_line != NULL)
            {
                len_line = ft_strlen(s->line) + 1;
                whole_line = (char *) malloc(len_line);
                if (whole_line == NULL)
                {
                    handle_error(s);
                    return ;
                }
                ft_strcpy(whole_line, s->line);
                *s->new_line = '\n';
                s->line = whole_line;
                free(whole_line);
                return ;
            }
        }
        else
            continue ;
    }
}

char    *get_next_line(int fd)
{
    t_gnl    s;
    char    *buffer_ptr;

    s.buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (s.buffer == NULL)
    {
        free(s.line);
        return (NULL);
    }
    s.buffer[BUFFER_SIZE] = '\0';
    s.line = (char *) malloc(1);
    if (s.line == NULL)
    {
        free(s.buffer);
        return (NULL);
    }
    s.line[0] = '\0';
    s.new_line = NULL;
    if (next_line != NULL)
    {
        buffer_ptr = s.buffer;
        while (*next_line)
        {
            if (buffer_ptr != NULL)
                *buffer_ptr++ = *next_line++;
        }
    }
    fill_line(fd, &s);
    if (s.line == NULL)
    {
        if (s.buffer != NULL)
        {
            free(s.buffer);
            s.buffer = NULL;
        }
        return (NULL);
    }
    if (s.line != NULL && ft_strlen(s.line) == 0)
        s.line = ft_strjoin(s.line, s.buffer);
    if (s.buffer != NULL)
    {
        free (s.buffer);
        s.buffer = NULL;
    }
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