/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2024/01/17 17:38:29 by csturm           ###   ########.fr       */
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
	char	*pos;
	char	*end;

	pos = cmd;
	while (*pos && ft_iswhitespace(*pos))
		pos++;
	end = ft_strchr(pos, ' ');
	if (end != NULL)
	{
		cmd2->cmd = malloc(end - pos + 1);
		if (!cmd2->cmd)
			return ;
		ft_strncpy(cmd2->cmd, pos, end - pos + 1);
		cmd2->cmd[end-pos] = '\0';
		pos = end + 1;
	}
	else 
	{
		cmd2->cmd = ft_strdup(pos);
		if (!cmd2->cmd)
			return ;
		cmd2->flag = NULL;
		return ;
	}
	cmd2->flag = ft_strdup(pos);
	if (!cmd2->flag)
		return ;
	cmd2->flag = ft_strtrim(cmd2->flag, "'");
}

void	parse_cmd1(char *cmd, t_cmd *cmd1)
{
	char	*pos;
	char	*end;

	pos = cmd;
	while (*pos && ft_iswhitespace(*pos))
		pos++;
	end = ft_strchr(pos, ' ');
	if (end != NULL)
	{
		cmd1->cmd = malloc(end - pos + 1);
		if (!cmd1->cmd)
			return ;
		ft_strncpy(cmd1->cmd, pos, end - pos + 1);
		cmd1->cmd[end-pos] = '\0';
		pos = end + 1;
	}
	else 
	{
		cmd1->cmd = ft_strdup(pos);
		if (!cmd1->cmd)
			return ;
		cmd1->flag = NULL;
		return ;
	}
	cmd1->flag = ft_strdup(pos);
	if (!cmd1->flag)
		return ;
	cmd1->flag = ft_strtrim(cmd1->flag, "'");
}

void	fill_cmd_struct(char **argv, char **paths, t_cmd *cmd1, t_cmd *cmd2)
{
	int	parse_quotes1;
	int	parse_quotes2;
	
	cmd1->exit_status = 0;
	cmd2->exit_status = 0;
	parse_quotes1 = parse_quotes_cmd1(argv[2], cmd1);
	if (parse_quotes1 == 0)
		parse_cmd1(argv[2], cmd1);
	else if (parse_quotes1 == -1)
		exit (-1);
	parse_quotes2 = parse_quotes_cmd2(argv[3], cmd2);
	if (parse_quotes2 == 0)
		parse_cmd2(argv[3], cmd2);
	else if (parse_quotes2 == -1)
		exit (-1);
	ft_printf("cmd: %s, flag: %s\n", cmd2->cmd, cmd2->flag);
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
