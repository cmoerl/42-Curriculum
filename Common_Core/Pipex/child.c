/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:31:17 by csturm            #+#    #+#             */
/*   Updated: 2024/01/24 18:33:11 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	handle_file_pipe_child(char *input, char **cmd, int *pipe)
{
	int	infile;

	infile = open(input, O_RDONLY, 0777);
	if (infile == -1)
	{
		free_array(cmd);
		error("Could not access iput file", -1);
	}
	dup2(pipe[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	if (close(pipe[0]) == -1)
	{
		free_array(cmd);
		error("Could not close pipe", -1);
	}
	return (infile);
}

void	child_process(char *input, char **cmd, char **envp, int *pipe)
{
	char	*cmd_path;
	int		infile;

	infile = handle_file_pipe_child(input, cmd, pipe);
	cmd_path = find_cmd_path(cmd[0], envp);
	if (!cmd_path)
	{
		free_all(cmd, cmd_path);
		error("Command not found", 127);
	}
	if (execve(cmd_path, cmd, envp) == -1)
	{
		free_all(cmd, cmd_path);
		error("execve", -1);
	}
}
