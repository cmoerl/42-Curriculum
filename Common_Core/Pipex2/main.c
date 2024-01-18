/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2024/01/18 23:02:25 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_cmd_path(char *cmd, char **envp)
{
	char	*cmd_path;
	char	**paths;
	int		i;

	paths = find_paths(envp);
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i] != NULL)
	{
		cmd_path = ft_strjoin(paths[i], cmd);
		if (!cmd_path)
			return (NULL);
		if (access(cmd_path, F_OK) != -1)
		{
			if (access(cmd_path, X_OK) != -1)
				return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	return (NULL);
}

void	child_process(char *input, char **cmd, char **envp, int *pipe)
{
	char	*cmd_path;
	int		infile;

	infile = open(input, O_RDONLY, 0777);
	if (infile == -1)
		error("Could not access iput file", -1);
	dup2(pipe[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(pipe[0]);
	cmd_path = find_cmd_path(cmd[0], envp);
	if (!cmd_path)
	{
		free_all(cmd, cmd_path);
		error("Command not found", 127);
	}
	if (execve(cmd_path, cmd, envp) == -1)
		error("execve", -1);
	free_all(cmd, cmd_path);
}

void	parent_process(char *output, char **cmd, char **envp, int *pipe)
{
	char	*cmd_path;
	int		outfile;

	outfile = open(output, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		error("Could not access output file", -1);
	dup2(pipe[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(pipe[1]);
	cmd_path = find_cmd_path(cmd[0], envp);
	if (!cmd_path)
	{
		free_all(cmd, cmd_path);
		error("Command not found", 127);
	}
	if (execve(cmd_path, cmd, envp) == -1)
		error("execve", -1);
	free_all(cmd, cmd_path);
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
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
	if (pid == 0)
		child_process(argv[1], ft_split(argv[2], ' '), envp, fd);
	else
	 	waitpid(pid, NULL, 0);
	parent_process(argv[4], ft_split(argv[3], ' '), envp, fd);
	return (0);
}
