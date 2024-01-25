/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2024/01/25 17:22:21 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>

char	*check_cmd_path(char **paths, char *cmd, int i)
{
	char	*cmd_path;

	cmd_path = ft_strjoin(paths[i], cmd);
	if (!cmd_path)
		return (NULL);
	if (access(cmd_path, F_OK) != -1)
	{
		if (access(cmd_path, X_OK) != -1)
		{
			free_array(paths);
			return (cmd_path);
		}
	}
	free(cmd_path);
	return (NULL);
}

char	*find_cmd_path(char *cmd, char **envp)
{
	char	*cmd_path;
	char	**paths;
	int		i;

	if (!check_cmd(cmd))
		return (cmd);
	paths = find_paths(envp);
	if (!paths)
	{
		free_array(paths);
		return (NULL);
	}
	i = 0;
	while (paths[i] != NULL)
	{
		cmd_path = check_cmd_path(paths, cmd, i);
		if (cmd_path)
			return (cmd_path);
		i++;
	}
	free_array(paths);
	return (NULL);
}

void	handle_child(char *infile, char *cmd, char **envp, int *fd)
{
	char	**cmd_arr;

	cmd_arr = ft_split(cmd, ' ');
	if (!cmd_arr)
	{
		free_array(cmd_arr);
		error("Error", -1);
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
		error("Error", -1);
	}
	parent_process(outfile, cmd_arr, envp, fd);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1, pid2;
	int		status1, status2;

	if (argc != 5 || !envp || envp[0][0] == '\0')
		exit (EXIT_FAILURE);
	if (pipe(fd) == -1)
		error("Could not create pipe", -1);
	pid2 = fork();
	if (pid2 == -1)
		error("Could not fork", -1);
	if (pid2 == 0)
	{
		handle_parent(argv[4], argv[3], envp, fd);
		exit (EXIT_SUCCESS);
	}
	pid1 = fork();
	if (pid1 == -1)
		error("Could not fork", -1);
	if (pid1 == 0)
	{
		handle_child(argv[1], argv[2], envp, fd);
		exit (EXIT_SUCCESS);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, &status1, 0);
	waitpid(pid2, &status2, 0);
	if (!WIFEXITED(status1) || !WIFEXITED(status2))
		error("Child Process Error", -1);
	return (0);
}
