/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free_paths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:17:09 by csturm            #+#    #+#             */
/*   Updated: 2024/01/27 16:52:05 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
		return (NULL);
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

void	error(char *str, int exit_code)
{
	ft_putstr_fd(str, 2);
	if (exit_code == -1)
		exit (EXIT_FAILURE);
	else
		exit (exit_code);
}

void	free_array(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return ;
}

void	free_all(char **arr, char *str)
{
	free_array(arr);
	free(str);
}
