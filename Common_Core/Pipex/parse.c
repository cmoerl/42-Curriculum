/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2023/12/19 18:04:12 by csturm           ###   ########.fr       */
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
	
}