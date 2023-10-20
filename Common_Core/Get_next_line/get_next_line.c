/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:16:05 by csturm            #+#    #+#             */
/*   Updated: 2023/10/20 13:39:47 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd)
{
	static char	**buffer;
	int			bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	it (bytes_read == -1)
	{
		free(buffer);
		return (NULL);
	}
}
