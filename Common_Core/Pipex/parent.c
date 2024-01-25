/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:33:14 by csturm            #+#    #+#             */
/*   Updated: 2024/01/25 15:25:53 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	handle_file_pipe_parent(char *output, char **cmd, int *pipe)
{
	int	outfile;

	outfile = open(output, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
	{
		close(pipe[0]);
		close(pipe[1]);
		free_array(cmd);
		error("Could not access output file", -1);
	}
	dup2(pipe[0], STDIN_FILENO);
	if (close(pipe[0]) == -1 || close(pipe[1]) == -1)
	{
		free_array(cmd);
		error("Could not close pipe", -1);
	}
	dup2(outfile, STDOUT_FILENO);
	if (close(outfile) == -1)
	{
		free_array(cmd);
		error("Could not close output file", -1);
	}
	return (outfile);
}

void	parent_process(char *output, char **cmd, char **envp, int *pipe)
{
	char	*cmd_path;
	int		outfile;

	outfile = handle_file_pipe_parent(output, cmd, pipe);
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
