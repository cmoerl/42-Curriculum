/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:16:05 by csturm            #+#    #+#             */
/*   Updated: 2023/11/03 13:25:12 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	fill_line(int fd, t_gnl *s, char **left_over)
{
	char	*newline_pos;
	int		bytes_read;
	int		i;

	i = 0;
	while (1)
	{
		bytes_read = read(fd, s->buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			return ;
		if (s->buffer == NULL)
			break ;
		s->buffer[bytes_read] = '\0';
		s->line = ft_strjoin(s->line, s->buffer);
		if (s->line == NULL)
		{
			free(left_over);
			return ;
		}
		newline_pos = ft_strchr(s->line, '\n');
		if (newline_pos != NULL)
		{
			if (*left_over == NULL)
			{
				*left_over = malloc(BUFFER_SIZE + 1);
				if (*left_over == NULL)
				{
					free(s->buffer);
					free(s->line);
					return ;
				}
			}
			s->end_line = newline_pos + 1;
			while (s->end_line[i] != '\0')
			{
				(*left_over)[i] = s->end_line[i];
				i++;
			}
			(*left_over)[i] = '\0';
			*s->end_line = '\0';
			return ;
		}
	}
}

char	*get_next_line(int fd)
{
	static char	*left_over;	
	t_gnl		s;

	s.buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (s.buffer == NULL)
		return (NULL);
	s.buffer[0] = '\0';
	s.line = malloc(1);
	if (!s.line)
	{
		free(s.buffer);
		free(left_over);
		return (NULL);
	}
	s.line[0] = '\0';
	if (left_over != NULL)
	{
		s.line = ft_strjoin(s.line, left_over);
		if (!s.line)
		{
			free(s.line);
			free(s.buffer);
			free(left_over);
			return (NULL);
		}
		free(left_over);
		left_over = NULL;
	}
	fill_line(fd, &s, &left_over);
	free(s.buffer);
	return (s.line);
}

/*
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	file_des;
	int	i;
	char	*line;

	i = 0;
	file_des = open ("testfile4.txt", O_RDONLY);
	while (i < 6)
	{
		line = get_next_line(file_des);
		if (line)
		{
			printf("%s", line);
			free(line);
		}
		i++;
	}
	return (0);
}
*/
