/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:23:26 by csturm            #+#    #+#             */
/*   Updated: 2024/01/04 17:24:41 by csturm           ###   ########.fr       */
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