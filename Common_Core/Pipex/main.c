/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2024/01/20 16:09:18 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <stdlib.h>

char	*find_cmd_path(char *cmd, char **envp)
{
	char	*cmd_path;
	char	**paths;
	int		i;

	paths = find_paths(envp);
	if (!paths)
	{
		free_array(paths);
		return (NULL);
	}
	i = 0;
	while (paths[i] != NULL)
	{
		cmd_path = ft_strjoin(paths[i], cmd);
		if (!cmd_path)
			return (free_array(paths), NULL);
		if (access(cmd_path, F_OK) != -1)
		{
			if (access(cmd_path, X_OK) != -1)
			{
				free_array(paths);
				return (cmd_path);
			}
		}
		free(cmd_path);
		i++;
	}
	return (free_array(paths), NULL);
}

void	child_process(char *input, char **cmd, char **envp, int *pipe)
{
	char	*cmd_path;
	int		infile;
	int		fd_close;

	infile = open(input, O_RDONLY, 0777);
	if (infile == -1)
	{
		free_array(cmd);
		error("Could not access iput file", -1);
	}
	dup2(pipe[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	fd_close = close(pipe[0]);
	if (fd_close == -1)
	{
		free_array(cmd);
		error("Could not close pipe", -1);
	}
	fd_close = close(infile);
	if (fd_close == -1)
	{
		free_array(cmd);
		error("Could not close infile", -1);
	}
	cmd_path = find_cmd_path(cmd[0], envp);
	if (!cmd_path)
	{
		free_all(cmd, cmd_path);
		error("Command not found", 127);
	}
	execve(cmd_path, cmd, envp);
	free_all(cmd, cmd_path);
	error("execve", -1);
}

void	parent_process(char *output, char **cmd, char **envp, int *pipe)
{
	char	*cmd_path;
	int		outfile;
	int		fd_close;

	outfile = open(output, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
	{
		free_array(cmd);
		error("Could not access output file", -1);
	}
	dup2(pipe[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	fd_close = close(pipe[1]);
	if (fd_close == -1)
	{
		free_array(cmd);
		error("Could not close pipe", -1);
	}
	fd_close = close(outfile);
	if (fd_close == -1)
	{
		free_array(cmd);
		error("Could not close outfile", -1);
	}
	cmd_path = find_cmd_path(cmd[0], envp);
	if (!cmd_path)
	{
		free_all(cmd, cmd_path);
		error("Command not found", 127);
	}
	execve(cmd_path, cmd, envp);
	free_all(cmd, cmd_path);
	error("execve", -1);
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	char	**cmd1;
	char	**cmd2;
	int		CHILD_STATUS;
	int		fd[2];

	if (argc != 5)
		exit (EXIT_FAILURE);
	if (!envp || envp[0][0] == '\0')
		exit (EXIT_FAILURE);
	if (pipe(fd) == -1)
		error("Could not create pipe", -1);
	pid = fork ();
	if (pid == -1)
		error("Could not fork", -1);
	cmd1 = ft_split(argv[2], ' ');
	if (!cmd1)
		error("Error", -1);
	CHILD_STATUS = 0;
	if (pid == 0)
		child_process(argv[1], cmd1, envp, fd);
	else
		waitpid(pid, &CHILD_STATUS, 0);
	if (!WIFEXITED(CHILD_STATUS))
		error("Child Process Error", CHILD_STATUS);
	cmd2 = ft_split(argv[3], ' ');
	if (!cmd2)
	{
		free_array(cmd2);
		error("Error", -1);
	}
	free(cmd1);
	parent_process(argv[4], cmd2, envp, fd);
	return (0);
}
