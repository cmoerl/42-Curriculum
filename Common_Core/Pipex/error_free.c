/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:17:09 by csturm            #+#    #+#             */
/*   Updated: 2024/01/26 10:52:36 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *str, int exit_code)
{
	ft_putstr_fd(str, 2);
	if (exit_code == -1)
		exit (EXIT_FAILURE);
	else
		exit (exit_code);
}

void	free_array(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return ;
}

void	free_all(char **arr, char *str)
{
	free_array(arr);
	free(str);
}
