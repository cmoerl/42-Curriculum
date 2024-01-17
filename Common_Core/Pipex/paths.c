/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2024/01/15 17:36:34 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_paths(char **envp)
{
	char	**paths;
	int		i;
	int		j;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5))
		i++;
	paths = ft_split(envp[i], ':');
	if (!paths)
		return (NULL);
	j = 0;
	while (paths[j] != NULL)
	{
		paths[j] = ft_strjoin(paths[j], "/");
		j++;
	}
	paths[0] = ft_strtrim(paths[0], "PATH=");
	return (paths);
}

void	select_path1(char **paths, t_cmd *cmd1)
{
	char	*path_file;
	int		i;

	i = 0;
	while (paths[i] != NULL)
	{
		path_file = ft_strjoin(paths[i], cmd1->cmd);
		if (!path_file)
			return ;
		if (access(path_file, F_OK) != -1)
		{
			if (access(path_file, X_OK) != -1)
			{
				cmd1->path = path_file;
				return ;
			}
		}
		free(path_file);
		i++;
	}
	perror("Command not found");
	cmd1->exit_status = 127;
}

void	select_path2(char **paths, t_cmd *cmd2)
{
	char	*path_file;
	int		i;

	i = 0;
	while (paths[i] != NULL)
	{
		path_file = ft_strjoin(paths[i], cmd2->cmd);
		if (!path_file)
			return ;
		if (access(path_file, F_OK) != -1)
		{
			if (access(path_file, X_OK) != -1)
			{
				cmd2->path = path_file;
				return ;
			}
		}
		free(path_file);
		i++;
	}
	perror("Command not found");
	cmd2->exit_status = 127;
}