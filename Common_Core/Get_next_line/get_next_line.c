/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:16:05 by csturm            #+#    #+#             */
/*   Updated: 2023/11/07 18:32:47 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	find_end_line(t_gnl *s, char **left_over, char *newline_pos)
{
	char	*end_line;
	int		i;

	i = 0;
	if (*left_over == NULL)
	{
		*left_over = malloc(BUFFER_SIZE + 1);
		if (*left_over == NULL)
		{
			free(s->line);
			return ;
		}
	}
	end_line = newline_pos + 1;
	while (end_line[i] != '\0')
	{
		(*left_over)[i] = end_line[i];
		i++;
	}
	(*left_over)[i] = '\0';
	*end_line = '\0';
}

static int	read_line(int fd, t_gnl *s, char **left_over)
{
	char	*new_line;
	char	*buffer;
	int		bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
	{
		free(s->line);
		return (0);
	}
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(buffer);
		return (0);
	}
	buffer[bytes_read] = '\0';
	new_line = ft_strjoin(s->line, buffer);
	if (new_line == NULL)
	{
		free(buffer);
		free(s->line);
		free(*left_over);
		return (0);
	}
	free(s->line);
	s->line = new_line;
	free(buffer);
	return (bytes_read);
}

static void	fill_line(int fd, t_gnl *s, char **left_over)
{
	char	*newline_pos;
	int		bytes_read;

	while (1)
	{
		bytes_read = read_line(fd, s, left_over);
		if (bytes_read == 0)
			return ;
		newline_pos = ft_strchr(s->line, '\n');
		if (newline_pos != NULL)
		{
			find_end_line(s, left_over, newline_pos);
			return ;
		}
	}
}

static void	left_over_to_line(t_gnl *s, char **left_over)
{
	s->line = ft_strjoin(s->line, *left_over);
	if (!s->line)
	{
		free(s->line);
		free(*left_over);
		return ;
	}
	free(*left_over);
	*left_over = NULL;
}

char	*get_next_line(int fd)
{
	static char	*left_over;	
	t_gnl		s;

	s.line = malloc(1);
	if (!s.line)
	{
		free(left_over);
		return (NULL);
	}
	s.line[0] = '\0';
	if (left_over != NULL)
		left_over_to_line(&s, &left_over);
	fill_line(fd, &s, &left_over);
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
	close(file_des);
	return (0);
}
*/
