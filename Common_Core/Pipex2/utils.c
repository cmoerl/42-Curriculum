/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2024/01/18 22:43:41 by csturm           ###   ########.fr       */
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

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_all(char **arr, char *str)
{
	free_array(arr);
	free(str);
}

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
