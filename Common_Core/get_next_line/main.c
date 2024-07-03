#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	file_des;
	int	i;
	char	*line;

	i = 0;
	file_des = open ("testfile5.txt", O_RDONLY);
	while (i < 100)
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
