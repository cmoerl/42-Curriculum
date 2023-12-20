/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2023/12/20 15:21:02 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# define STDOUT_FILENO 1
# include "Libft/libft.h"

typedef struct command
{
	char	*cmd;
	char	*flag;
	char	*path;
}	t_cmd;

char	**find_paths(char **envp);
void	parse_cmd1(char *cmd, t_cmd *cmd1);
void	parse_cmd2(char *cmd, t_cmd *cmd2);
void	select_path1(char **paths, t_cmd *cmd1);
void	select_path2(char **paths, t_cmd *cmd2);

# endif