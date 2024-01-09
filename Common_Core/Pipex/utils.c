/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2024/01/09 19:24:38 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	fill_cmd_struct(char **argv, char **paths, t_cmd *cmd1, t_cmd *cmd2)
{
	parse_cmd1(argv[2], cmd1);
	parse_cmd2(argv[3], cmd2);
	select_path1(paths, cmd1);
	select_path2(paths, cmd2);
}

void	allocate_cmds(t_cmd **cmd1, t_cmd **cmd2)
{
	*cmd1 = malloc(sizeof(t_cmd));
	if (!*cmd1)
		exit(-1);
	*cmd2 = malloc(sizeof(t_cmd));
	if (!*cmd2)
	{
		free(*cmd1);
		exit(-1);
	}
}
