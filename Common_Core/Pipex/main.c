/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2023/12/18 18:04:57 by csturm           ###   ########.fr       */
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

void	child_process(t_cmd *cmd1, int *read_end)
{
	char	*cmd_arr[3];

	close(read_end[1]);
	dup2(read_end[0], STDIN_FILENO);
	close(read_end[0]);
	cmd_arr[0] = cmd1->path;
	cmd_arr[1] = cmd1->flag;
	cmd_arr[2] = NULL;
	execve(cmd1->path, cmd_arr, NULL);
	perror("execve");
	exit(EXIT_FAILURE);
}

void	parent_process(t_cmd *cmd2, int *write_end)
{
	char	*cmd_arr[3];

	close(write_end[0]);
	dup2(write_end[1], STDOUT_FILENO);
	close(write_end[1]);
	cmd_arr[0] = cmd2->path;
	cmd_arr[1] = cmd2->flag;
	cmd_arr[2] = NULL;
	execve(cmd2->path, cmd_arr, NULL);
	perror("execve");
	exit(EXIT_FAILURE);
}

void	pipex(const char *infile, const char *outfile,
			t_cmd *cmd1, t_cmd *cmd2)
{
	pid_t	pid;
	int		fd[2];

	make_pipe(fd);
	pid = fork ();
	if (pid == -1)
	{
		perror("Could not fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
		child_process(cmd1, fd);
	else
		parent_process(cmd2, fd);
	close(fd[1]);
	freopen(outfile, "w", stdout);
	wait(NULL);
}

int	main(int argc, char **argv)
{
	char	*infile;
	char	*outfile;
	t_cmd	*cmd1;
	t_cmd	*cmd2;

	if (argc == 5)
	{
		infile = argv[1];
		outfile = argv[4];
		parse_cmd(argv[2], &cmd1);
		parse_cmd(argv[3], &cmd2);
		pipex(infile, outfile, cmd1, cmd2);
	}
	return (0);
}
