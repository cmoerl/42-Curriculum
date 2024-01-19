/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2024/01/19 20:11:27 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *str, int exit_code)
{
	
	perror(str);
	if (exit_code == -1)
		exit (EXIT_FAILURE);
	else
	exit (exit_code);
}

char	*free_array(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (NULL);
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

void	free_all(char **arr, char *str)
{
	free_array(arr);
	free(str);
}

char	**find_paths(char **envp)
{
	char	**paths;
	char	*new_path;
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
		new_path = ft_strjoin(paths[j], "/");
		if (!new_path)
			return (NULL);
		free(paths[j]);
		paths[j] = new_path;
		j++;
	}
	new_path = ft_strtrim(paths[0], "PATH=");
	if (!new_path)
		return (NULL);
	free(paths[0]);
	paths[0] = new_path;
	return (paths);
}
