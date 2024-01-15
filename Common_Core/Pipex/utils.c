/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2024/01/12 16:25:43 by csturm           ###   ########.fr       */
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
	int		i;
	char	*tmp;

	arr = ft_split(cmd, ' ');
	if (!arr)
		return ;
	cmd2->cmd = arr[0];
	cmd2->flag = NULL;
	i = 1;
	while (arr[i] != NULL)
	{
		if (cmd2->flag == NULL)
			cmd2->flag = ft_strdup(arr[i]);
		else
		{
			tmp = ft_strjoin(cmd2->flag, " ");
			free(cmd2->flag);
			cmd2->flag = ft_strjoin(tmp, arr[i]);
			free(tmp);
		}
		i++;
	}
	free_array(arr);
}

void	parse_cmd1(char *cmd, t_cmd *cmd1)
{
	char	**arr;
	int		i;
	char	*tmp;

	arr = ft_split(cmd, ' ');
	if (!arr)
		return ;
	cmd1->cmd = arr[0];
	cmd1->flag = NULL;
	i = 1;
	while (arr[i] != NULL)
	{
		if (cmd1->flag == NULL)
			cmd1->flag = ft_strdup(arr[i]);
		else
		{
			tmp = ft_strjoin(cmd1->flag, " ");
			free(cmd1->flag);
			cmd1->flag = ft_strjoin(tmp, arr[i]);
			free(tmp);
		}
		i++;
	}
	free_array(arr);
}

void	fill_cmd_struct(char **argv, char **paths, t_cmd *cmd1, t_cmd *cmd2)
{
	cmd1->exit_status = 0;
	cmd2->exit_status = 0;
	parse_cmd1(argv[2], cmd1);
	if (cmd1->flag[0] == '\'' || cmd1->flag[0] == '\"')
		cmd1->flag = ft_strtrim(cmd1->flag, "\'\"");
	parse_cmd2(argv[3], cmd2);
	if (cmd2->flag[0] == '\'' || cmd2->flag[0] == '\"')
		cmd2->flag = ft_strtrim(cmd2->flag, "\'\"");
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
