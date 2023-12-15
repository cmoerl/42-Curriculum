/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2023/12/15 16:50:53 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(const char *infile, const char *cmd1, const char *cmd2, const char *outfile)
{
	pid_t	pid;
	char	**cmd1_argv;
	char	**cmd2_argv;
	int		fd[2];

	if (pipe(fd) == -1)
	{
		perror("Could not create pipe");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Could not fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		cmd1_argv = {cmd1, NULL};
		execve(cmd1_argv[0], cmd1_argv, NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else 
	{
		close(fd[0])
		dup2(fd[1], STDOUT_FILENO);
		cmd2_argv = {cmd2, NULL};
		execve(cmd2_argv[0], cmd2_argv, NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	close(fd[1]);
	freopen(outfile, "w", stdout);
}

int	main(int argc, char **argv)
{
	if (argc == 5)
		pipex(argv[1], argv[2], argv[3], argv[4]);
	return (0);
}