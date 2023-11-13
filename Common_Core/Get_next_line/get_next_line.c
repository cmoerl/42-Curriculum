/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:16:05 by csturm            #+#    #+#             */
/*   Updated: 2023/11/13 15:32:06 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	find_end_line(t_gnl *s, char **left_over, char *newline_pos)
{
	int		i;
	int		len;

	i = 0;
	if (*left_over == NULL)
	{
		*left_over = malloc(ft_strlen(s->line));
		if (*left_over == NULL)
		{
			free(s->line);
			s->line = NULL;
			return ;
		}
	}
	newline_pos++;
	len = newline_pos - s->line;
	while (newline_pos[i] != '\0')
	{
		(*left_over)[i] = newline_pos[i];
		i++;
	}
	(*left_over)[i] = '\0';
	s->line[len] = '\0';
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
	buffer = NULL;
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

static void	left_over_to_line(t_gnl *s, char **left_over)
{
	char	*new_line;

	new_line = ft_strjoin(s->line, *left_over);
	if (!new_line)
	{
		free(s->line);
		s->line = NULL;
		free(*left_over);
		*left_over = NULL;
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
	int			end_of;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s.line = malloc(1);
	if (!s.line)
	{
		if (left_over != NULL)
		{
			free(left_over);
			left_over = NULL;
		}
		return (NULL);
	}
	s.line[0] = '\0';
	if (left_over != NULL && left_over[0] != '\0')
		left_over_to_line(&s, &left_over);
	end_of = 0;
	while(!end_of)
	{
		if (!fill_line(fd, &s, &left_over, &end_of))
		{
			free(s.line);
			s.line = NULL;
			free(left_over);
			left_over = NULL;
			return (NULL);
		}
		if (end_of || s.line[0] != '\0')
			return (s.line);
	}
	return (NULL);
}


#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	file_des;
	int	i;
	char	*line;

	i = 0;
	file_des = open ("testfile4.txt", O_RDONLY);
	while (i < 3)
	{
		line = get_next_line(file_des);
		if (line)
		{
			printf("%s", line);
			free(line);
			line = NULL;
		}
		i++;
	}
	close(file_des);
	return (0);
}

/*
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
    int file_des;
//    int new_file_des;
    char *line;

	file_des = open ("testfile3.txt", O_RDONLY);
    // Duplicate file descriptor 1000 to a valid file descriptor (e.g., 0).
    if ((dup2(file_des, 1000)) < 0)
    {
        perror("Failed to duplicate file descriptor");
        return 1;
    }

	close(file_des);

    // Call get_next_line with the duplicated file descriptor.
    line = get_next_line(-1);
    if (line)
    {
        printf("Test Case 1 (file descriptor 1000): %s\n", line);
        free(line);
    }
    else
    {
        printf("Test Case 1 (file descriptor 1000): Returned NULL, as expected.\n");
    }

    // Close the duplicated file descriptor.
    close(1000);

    return 0;
}
*/