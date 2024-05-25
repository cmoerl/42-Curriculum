#include "microshell2.h"

int	error(char *msg)
{
	while (*msg)
		write (2, msg++, 1);
	return (1);
}

int	cd(char **argv, int i)
{
	if (i != 2)
		return (error("error: cd: bad arguments\n"));
	if (chdir(argv[1]) == -1)
		return (error("error: cd: cannot change directory to "), error (argv[1]), error("\n"));
	return (0);
}

int	exec(char **argv, char **envp, int i)
{
	int	status;
	int	fd[2];
	int	pipe_exist;
	int	pid;

	status = 0;
	pipe_exist = argv[i] && !strcmp(argv[i], "|");
	if (pipe_exist && pipe(fd) == -1)
		return (error("error: fatal\n"));
	pid = fork();
	if (!pid)
	{
		argv[i] = 0;
		if (pipe_exist && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
			return (error("error: fatal\n"));
		execve(*argv, argv, envp);
		return (error("error: cannot execute "), error(*argv), error("\n"));
	}
	waitpid(pid, &status, 0);
	if (pipe_exist && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
		return (error("error: fatal\n"));
	return (WIFEXITED(status) && WEXITSTATUS(status));
}

int	main(int argc, char **argv, char **envp)
{
	int	status;
	int	i;

	status = 0;
	i = 0;
	if (argc > 1)
	{
		while (argv[i] && argv[++i])
		{
			argv += i;
			i = 0;
			while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
				i++;
			if (!strcmp(*argv, "cd"))
				status = cd (argv, i);
			else if (i)
				status = exec(argv, envp, i);
		}
	}
	return (status);
}
