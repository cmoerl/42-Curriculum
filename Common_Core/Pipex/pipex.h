/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2024/01/12 11:10:49 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "Libft/libft.h"

typedef struct command
{
	char	*cmd;
	char	*flag1;
	char	*flag2;
	char	*path;
	int		exit_status;
}	t_cmd;

char	**find_paths(char **envp);
void	parse_cmd1(char *cmd, t_cmd *cmd1);
void	parse_cmd2(char *cmd, t_cmd *cmd2);
void	select_path1(char **paths, t_cmd *cmd1);
void	select_path2(char **paths, t_cmd *cmd2);
void	child_process(t_cmd *cmd1, int *read_end, const char *infile);
void	parent_process(t_cmd *cmd2, int *write_end, const char *outfile);
void	pipex(const char *infile, const char *outfile,
			t_cmd *cmd1, t_cmd *cmd2);
void	make_pipe(int fd[2]);
void	free_array(char **arr);
void	fill_cmd_struct(char **argv, char **paths, t_cmd *cmd1, t_cmd *cmd2);
void	allocate_cmds(t_cmd **cmd1, t_cmd **cmd2);

#endif