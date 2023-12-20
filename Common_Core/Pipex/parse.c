/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2023/12/20 15:20:40 by csturm           ###   ########.fr       */
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
		ft_strjoin(paths[j], "/");
	return (paths);
}

void	parse_cmd2(char *cmd, t_cmd *cmd2)
{
	char	**arr;

	arr = ft_split(cmd, ' ');
	if (!arr)
		return ;
	cmd2->cmd = arr[0];
	if (arr[1] != NULL)
		cmd2->flag = arr[1];
	else
		cmd2->flag = NULL;
}

void	parse_cmd1(char *cmd, t_cmd *cmd1)
{
	char	**arr;

	arr = ft_split(cmd, ' ');
	if (!arr)
		return ;
	cmd1->cmd = arr[0];
	if (arr[1] != NULL)
		cmd1->flag = arr[1];
	else
		cmd1->flag = NULL;
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
}