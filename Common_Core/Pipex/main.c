/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2024/01/08 18:04:17 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>

void	make_pipe(int fd[2])
{
	if (pipe(fd) == -1)
	{
		perror("Could not create pipe");
		exit(EXIT_FAILURE);
	}
}

void	child_process(t_cmd *cmd1, int *pipe, const char *infile, char **envp)
{
	char	*cmd_arr[3];

	close(pipe[0]);
	dup2(pipe[1], STDOUT_FILENO);
	close(pipe[1]);
	freopen(infile, "r", stdin);
	cmd_arr[0] = cmd1->cmd;
	cmd_arr[1] = cmd1->flag;
	cmd_arr[2] = NULL;
	execve(cmd1->path, cmd_arr, envp);
	perror("execve");
	exit(EXIT_FAILURE);
}

void	parent_process(t_cmd *cmd2, int *pipe, const char *outfile, char **envp)
{
	char	*cmd_arr[3];

	close(pipe[1]);
	dup2(pipe[0], STDIN_FILENO);
	close(pipe[0]);
	freopen(outfile, "w", stdout);
	cmd_arr[0] = cmd2->cmd;
	cmd_arr[1] = cmd2->flag;
	cmd_arr[2] = NULL;
	execve(cmd2->path, cmd_arr, envp);
	perror("execve");
	exit(EXIT_FAILURE);
}

void	pipex(const char *infile, const char *outfile,
			t_cmd *cmd1, t_cmd *cmd2, char **envp)
{
	pid_t	pid;
	int		pipe[2];
	int		status;

	make_pipe(pipe);
	pid = fork ();
	if (pid == -1)
	{
		perror("Could not fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
		child_process(cmd1, pipe, infile, envp);
	else
	{
		parent_process(cmd2, pipe, outfile, envp);
		close(pipe[1]);
	}
	if (waitpid(pid, &status, 0) == -1)
	{
		perror("waitpid failed");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_cmd	*cmd1;
	t_cmd	*cmd2;
	char	**paths;

	if (argc != 5)
	{
		perror("Wrong number of arguments");
		exit(EXIT_FAILURE);
	}
	cmd1 = malloc(sizeof(t_cmd));
	cmd2 = malloc(sizeof(t_cmd));
	if (!cmd1)
		exit(-1);
	if (!cmd2)
	{
		free_everything(cmd1, NULL, NULL);
		exit(-1);
	}
	paths = find_paths(envp);
	if (!paths)
	{
		free_everything(cmd1, cmd2, NULL);
		exit(-1);
	}
	fill_cmd_struct(argv, paths, cmd1, cmd2);
	pipex(argv[1], argv[4], cmd1, cmd2, envp);
	free_everything(cmd1, cmd2, paths);
	return (0);
}
