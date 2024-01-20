/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2024/01/20 13:44:24 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "Libft/libft.h"

char	**find_paths(char **envp);
char	*find_cmd_path(char *cmd, char **envp);
void	free_array(char **arr);
void	child_process(char *input, char **cmd, char **envp, int *pipe);
void	parent_process(char *output, char **cmd, char **envp, int *pipe);
void	free_all(char **arr, char *str);
void	error(char *str, int exit_code);

#endif