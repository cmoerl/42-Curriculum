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

static char *buffer;

void    fill_line(int fd, t_gnl *s)
{
    int     bytes_read;
    char    *newline_pos;

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
            s->end_line = newline_pos + 1;
            *s->end_line = '\0';
            buffer = s->end_line;
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
    }
    s.line = malloc(1);
    if (!s.line)
    {
        free(buffer);
        return (NULL);
    }
    s.line[0] = '\0';
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
	while (i < 5)
	{
		printf("%s", get_next_line(file_des));
		i++;
	}
	return (0);
}