/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:16:05 by csturm            #+#    #+#             */
/*   Updated: 2023/10/24 16:28:30 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*next_line;

void	fill_current_line(int fd, char *buffer, struct get_next_line *s)
{
	int		bytes_read;

	if (next_line != NULL)
		buffer = next_line;
	else
	{
		(*s).current_line = ft_strdup("");
		while (buffer != NULL && ft_strchr(buffer, '\n') == 0)
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			if (bytes_read == -1)
			{
				free(buffer);
				free((*s).current_line);
				return ;
			}
			else if (bytes_read == 0)
				break ;
			buffer[bytes_read] = '\0';
			(*s).current_line = ft_strjoin((*s).current_line, buffer);
		}
	}
	if (ft_strchr((*s).current_line, '\n') != 0)
	{
		(*s).end_line = ft_strchr((*s).current_line, '\n');
		*(*s).end_line = '\0';
	}
}

char	*get_next_line(int fd)
{
	char					*buffer;
	struct get_next_line 	s;
	
	if (!next_line)
		next_line = ft_strdup("");
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	fill_current_line(fd, buffer, &s);
	free(buffer);
	if (s.current_line == NULL)
		return (0);
	if (s.end_line)
	{
		next_line = s.end_line + 1;
		next_line[ft_strlen(next_line)] = '\0';
	}
	else
		next_line = NULL;
	return (s.current_line);
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
		printf("%s\n", get_next_line(file_des));
		i++;
	}
	return (0);
}
