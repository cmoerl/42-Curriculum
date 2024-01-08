/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:23:26 by csturm            #+#    #+#             */
/*   Updated: 2024/01/08 18:04:35 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    free_array(char **arr)
{
    int i;

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

void	free_everything(char **paths, t_cmd *cmd1, t_cmd *cmd2)
{
	free_array(paths);
	free(cmd1->path);
	free(cmd2->path);
}