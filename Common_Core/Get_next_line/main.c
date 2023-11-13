/*
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	file_des;
	int	i;
	char	*line;

	i = 0;
	file_des = open ("testfile3.txt", O_RDONLY);
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