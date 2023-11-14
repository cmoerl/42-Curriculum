/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:16:05 by csturm            #+#    #+#             */
/*   Updated: 2023/11/14 16:33:55 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	find_end_line(t_gnl *s, char **left_over, char *newline_pos)
{
	size_t		len;

	if (*left_over == NULL )
		*left_over = ft_strdup(newline_pos + 1);
	if (*left_over == NULL)
	{
		free(s->line);
		s->line = NULL;
		return ;
	}
	len = newline_pos - s->line + 1;
	if (len < ft_strlen(s->line))
		s->line[len] = '\0';
	if ((*left_over)[0] == '\0')
	{
		free(*left_over);
		*left_over = NULL;
	}
}

static int	read_line(int fd, t_gnl *s, char **left_over)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
	{
		free(s->line);
		s->line = NULL;
		return (0);
	}
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(buffer);
		buffer = NULL;
		if (bytes_read == -1)
			return (-1);
		return (0);
	}
	buffer[bytes_read] = '\0';
	if (!add_buffer_to_line(s, left_over, buffer))
		return (0);
	free(buffer);
	return (bytes_read);
}

static int	fill_line(int fd, t_gnl *s, char **left_over, int *end_of)
{
	char	*newline_pos;
	int		bytes_read;

	while (1)
	{
		bytes_read = read_line(fd, s, left_over);
		if (bytes_read <= 0)
		{
			if (bytes_read == -1)
				return (0);
			if (s->line[0] != '\0')
			{
				*end_of = 1;
				return (1);
			}
			return (0);
		}
		newline_pos = ft_strchr(s->line, '\n');
		if (newline_pos != NULL)
		{
			find_end_line(s, left_over, newline_pos);
			*end_of = 1;
			return (1);
		}
	}
}

static int	left_over_to_line(t_gnl *s, char **left_over)
{
	char	*new_line;
	char	*newline_pos;

	new_line = ft_strjoin(s->line, *left_over);
	if (!new_line)
	{
		free(s->line);
		s->line = NULL;
		free(*left_over);
		*left_over = NULL;
		return (0);
	}
	free(s->line);
	s->line = new_line;
	free(*left_over);
	*left_over = NULL;
	newline_pos = ft_strchr(s->line, '\n');
	if (newline_pos != NULL)
	{
		find_end_line(s, left_over, newline_pos);
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*left_over;	
	t_gnl		s;
	int			end_of;

	s.line = malloc(1);
	if (!s.line || fd < 0 || BUFFER_SIZE <= 0)
	{
		free(left_over);
		left_over = NULL;
		return (NULL);
	}
	s.line[0] = '\0';
	if (left_over && *left_over && left_over_to_line(&s, &left_over))
		return (s.line);
	end_of = 0;
	while (!end_of)
	{
		if (!fill_line(fd, &s, &left_over, &end_of))
		{
			return (free(s.line), free(left_over), NULL);
		}
		if (end_of || s.line[0])
			return (s.line);
	}
	return (NULL);
}
