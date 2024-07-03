/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2024/01/27 17:11:07 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>

void	handle_child(char *infile, char *cmd, char **envp, int *fd)
{
	char	**cmd_arr;

	cmd_arr = ft_split(cmd, ' ');
	if (!cmd_arr)
	{
		free_array(cmd_arr);
		error("Error\n", -1);
	}
	child_process(infile, cmd_arr, envp, fd);
	exit(EXIT_SUCCESS);
}

void	handle_parent(char *outfile, char *cmd, char **envp, int *fd)
{
	char	**cmd_arr;

	cmd_arr = ft_split(cmd, ' ');
	if (!cmd_arr)
	{
		free_array(cmd_arr);
		error("Error\n", -1);
	}
	parent_process(outfile, cmd_arr, envp, fd);
	exit(EXIT_SUCCESS);
}

pid_t	create_parent(char *file, char *cmd, char **envp, int *fd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		error("Could not fork\n", -1);
	if (pid == 0)
	{
		handle_parent(file, cmd, envp, fd);
		exit(EXIT_SUCCESS);
	}
	return (pid);
}

pid_t	create_child(char *file, char *cmd, char **envp, int *fd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		error("Could not fork\n", -1);
	if (pid == 0)
	{
		handle_child(file, cmd, envp, fd);
		exit(EXIT_SUCCESS);
	}
	return (pid);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status1;
	int		status2;

	if (argc != 5)
		error("Invalid number of arguments\n", -1);
	if (pipe(fd) == -1)
		error("Could not create pipe\n", -1);
	pid1 = create_child(argv[1], argv[2], envp, fd);
	pid2 = create_parent(argv[4], argv[3], envp, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, &status1, 0);
	waitpid(pid2, &status2, 0);
	if (WIFEXITED(status2) && WEXITSTATUS(status2) != 0)
		error("", WEXITSTATUS(status2));
	return (0);
}
