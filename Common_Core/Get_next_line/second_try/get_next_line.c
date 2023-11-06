#include "get_next_line.h"
#include <stdio.h>

char    *fill_line(char *left_over)
{
    char    *str;
    int     i;

    i = 0;
    if (!left_over[i])
        return (NULL);
    while (left_over[i] && left_over[i] != '\n')
        i++;
    str = (char *)malloc((i + 2) * sizeof(char));
    if (!str)
        return (NULL);
    i = 0;
    while (left_over[i] && left_over[i] != '\n')
    {
        str[i] = left_over[i];
        i++;
    }
    if (left_over[i] == '\n')
    {
        str[i] = left_over[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

char    *new_left_over(char *left_over)
{
    char    *str;
    int     i;
    int     j;

    i = 0;
    while (left_over[i] && left_over[i] != '\n')
        i++;
    if (!left_over[i])
    {
        free(left_over);
        return (NULL);
    }
    str = malloc(ft_strlen(left_over) - i + 1);
    if (!str)
        return (NULL);
    i++;
    j = 0;
    while (left_over[i])
    {
        str[j] = left_over[i];
        i++;
        j++;
    }
    str[j] = '\0';
//    free(left_over);
    return (str);
}

char    *fill_left_over(int fd, char *left_over)
{
    char    *buffer;
    int     bytes_read;

    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (0);
    bytes_read = 1;
    while(!ft_strchr(left_over, '\n') && bytes_read != 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1)
        {
            free (buffer);
            return (0);
        }
        buffer[bytes_read] = '\0';
        left_over = ft_strjoin(left_over, buffer);
    }
    free(buffer);
    return (left_over);
}

char    *get_next_line(int fd)
{
    static char *left_over;
    char        *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    left_over = fill_left_over(fd, left_over);
    if (!left_over)
        return (NULL);
    line = fill_line(left_over);
    left_over = new_left_over(left_over);
    return (line);
}

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	file_des;
	int	i;
	char	*line;

	i = 0;
	file_des = open ("testfile3.txt", O_RDONLY);
	while (i < 6)
	{
        printf("function call %d\n", i);
		line = get_next_line(file_des);
		if (line)
		{
			printf("%s", line);
//			free(line);
		}
		i++;
	}
	return (0);
}