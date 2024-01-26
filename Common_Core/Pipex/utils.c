/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2024/01/26 15:48:21 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_cmd(char *cmd)
{
	if (access(cmd, F_OK) != -1)
	{
		if (access(cmd, X_OK) != -1)
			return (0);
	}
	return (1);
}

char	*append_slash(char *path)
{
	char	*new_path;

	new_path = ft_strjoin(path, "/");
	if (!new_path)
		return (NULL);
	free(path);
	return (new_path);
}

char	**find_paths(char **envp)
{
	char	**paths;
	char	*new_path;
	int		i;
	int		j;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	paths = ft_split(envp[i], ':');
	if (!paths)
		return (NULL);
	j = 0;
	while (paths[j] != NULL)
	{
		paths[j] = append_slash(paths[j]);
		if (!paths[j])
			return (NULL);
		j++;
	}
	new_path = ft_strtrim(paths[0], "PATH=");
	if (!new_path)
		return (NULL);
	free(paths[0]);
	paths[0] = new_path;
	return (paths);
}
