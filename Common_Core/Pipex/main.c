/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2024/01/05 17:18:03 by csturm           ###   ########.fr       */
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
		parent_process(cmd2, pipe, outfile, envp);
	close(pipe[1]);
	wait(NULL);
}

int	main(int argc, char **argv, char **envp)
{
	char	*infile;
	char	*outfile;
	t_cmd	*cmd1;
	t_cmd	*cmd2;
	char	**paths;

	cmd1 = malloc(sizeof(t_cmd));
	cmd2 = malloc(sizeof(t_cmd));
	if (!cmd1 || !cmd2)
	{
		perror("Not enough memory");
		exit(EXIT_FAILURE);
	}
	ft_printf("1\n");
	paths = find_paths(envp);
	if (!paths)
	{
		perror("Not enough memory");
		exit(EXIT_FAILURE);
	}
	ft_printf("2\n");
	if (argc == 5)
	{
		ft_printf("3\n");
		infile = argv[1];
		outfile = argv[4];
		parse_cmd1(argv[2], cmd1);
		parse_cmd2(argv[3], cmd2);
		ft_printf("4\n");
		select_path1(paths, cmd1);
		select_path2(paths, cmd2);
		ft_printf("5\n");
		pipex(infile, outfile, cmd1, cmd2, envp);
	}
	ft_printf("6\n");
	free_array(paths);
	free(cmd1);
	free(cmd2);
	ft_printf("7\n");
	return (0);
}
