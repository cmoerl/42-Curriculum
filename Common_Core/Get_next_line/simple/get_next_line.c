/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:16:05 by csturm            #+#    #+#             */
/*   Updated: 2023/11/08 16:46:20 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	find_end_line(t_gnl *s, char *newline_pos)
{
	char	*end_line;
	char	*new_line;

	end_line = newline_pos + 1;
	if (!s->line)
		s->line = ft_strdup(end_line);
	else
	{
		new_line = ft_strdup(end_line);
		free(s->line);
		s->line = new_line;
	}
	*newline_pos = '\0';
}

static int	read_line(int fd, t_gnl *s)
{
	char	*new_line;
	char	*buffer;
	int		bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (-1);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(buffer);
		return (bytes_read);
	}
	buffer[bytes_read] = '\0';
	new_line = ft_strjoin(s->line, buffer);
	free(buffer);
	if (new_line == NULL)
		return (-1);
	free(s->line);
	s->line = new_line;
	free(buffer);
	return (bytes_read);
}

static void	left_over_to_line(t_gnl *s, char **left_over)
{
	char	*new_line;

	new_line = ft_strjoin(s->line, *left_over);
	if (!new_line)
	{
		free(s->line);
		free(*left_over);
		return ;
	}
	free(s->line);
	s->line = new_line;
	free(*left_over);
	*left_over = NULL;
}

char	*get_next_line(int fd)
{
	static char	*left_over;	
	t_gnl		s;
	int			bytes_read;
	char		*newline_pos;

//	s.line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s.line = malloc(1);
	if (!s.line)
	{
		free(left_over);
		return (NULL);
	}
	s.line[0] = '\0';
	if (left_over != NULL)
	{
		left_over_to_line(&s, &left_over);
		return (s.line);
	}
	while (1)
	{
		bytes_read = read_line(fd, &s);
		if (bytes_read <= 0)
		{
			free(left_over);
			return (s.line);
		}
		newline_pos = ft_strchr(s.line, '\n');
		if (newline_pos)
		{
			find_end_line(&s, newline_pos);
			free(left_over);
			left_over = ft_strdup(newline_pos + 1);
			return (s.line);
		}
	}
}


#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	file_des;
	int	i;
	char	*line;

	i = 0;
	file_des = open ("testfile2.txt", O_RDONLY);
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
	close(file_des);
	return (0);
}

