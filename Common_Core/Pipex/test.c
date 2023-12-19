#include "pipex.h"
#include <unistd.h>
pipe(fd);
// fd[0] fd[1]
dup2(infile, STDIN_FILENO);
dup2(fd[1], STDOUT_FILENO);
dup2(fd[0], STDIN_FILENO);

