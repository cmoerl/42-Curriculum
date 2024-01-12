/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2024/01/12 11:53:49 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	make_pipe(int fd[2])
{
	if (pipe(fd) == -1)
	{
		perror("Could not create pipe");
		exit(EXIT_FAILURE);
	}
}

void	child_process(t_cmd *cmd1, int *pipe, const char *infile)
{
	char	*cmd_arr[4];

	close(pipe[0]);
	dup2(pipe[1], STDOUT_FILENO);
	close(pipe[1]);
	if (freopen(infile, "r", stdin) == NULL)
	{
		perror("Could not open infile");
		exit(EXIT_FAILURE);
	}
	cmd_arr[0] = cmd1->cmd;
	cmd_arr[1] = cmd1->flag1;
	cmd_arr[2] = cmd1->flag2;
	cmd_arr[3] = NULL;
	execve(cmd1->path, cmd_arr, NULL);
	perror("execve");
	exit(EXIT_FAILURE);
}

void	parent_process(t_cmd *cmd2, int *pipe, const char *outfile)
{
	char	*cmd_arr[4];

	close(pipe[1]);
	dup2(pipe[0], STDIN_FILENO);
	close(pipe[0]);
	if (freopen(outfile, "w", stdout) == NULL)
	{
		perror("Could not open outfile");
		exit(EXIT_FAILURE);
	}
	cmd_arr[0] = cmd2->cmd;
	cmd_arr[1] = cmd2->flag1;
	cmd_arr[2] = cmd2->flag2;
	cmd_arr[3] = NULL;
	execve(cmd2->path, cmd_arr, NULL);
	perror("execve");
	exit(EXIT_FAILURE);
}

void	pipex(const char *infile, const char *outfile,
			t_cmd *cmd1, t_cmd *cmd2)
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
	if (pid == 0 && cmd1->exit_status == 0)
		child_process(cmd1, pipe, infile);
	else
	{
		if (cmd2->exit_status == 0)
			parent_process(cmd2, pipe, outfile);
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
	allocate_cmds(&cmd1, &cmd2);
	paths = find_paths(envp);
	if (!paths)
	{
		free(cmd1);
		free(cmd2);
		exit(-1);
	}
	fill_cmd_struct(argv, paths, cmd1, cmd2);
	if (cmd1->exit_status != 0 && cmd2->exit_status != 0)
		exit (cmd1->exit_status);
	pipex(argv[1], argv[4], cmd1, cmd2);
	free(cmd1);
	free(cmd2);
	free_array(paths);
	if (cmd1->exit_status != 0)
		exit (cmd1->exit_status);
	else if (cmd2->exit_status != 0)
		exit (cmd2->exit_status);
	return (0);
}
