/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csturm <csturm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:37:11 by csturm            #+#    #+#             */
/*   Updated: 2024/01/17 15:50:45 by csturm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int parse1(char *cmd, t_cmd *cmd1)
{
    char    *pos;
    char    *end;
    
    pos = cmd;
    while (*pos && ft_iswhitespace(*pos))
        pos++;
    end = ft_strchr(pos, ' ');
    if (!end)
        return (1);
    cmd1->cmd = malloc(end - pos + 1);
    if (!cmd1->cmd)
        return (1);
    ft_strncpy(cmd1->cmd, pos, end - pos + 1);
    cmd1->cmd[end - pos] = '\0';
    pos = end + 1;
    cmd1->flag = ft_strdup(pos);
    if (!cmd1->flag)
        return (1);
    cmd1->flag = ft_strtrim(cmd1->flag, "'");
    return (0);
}

int parse_quotes_cmd1(char *cmd, t_cmd *cmd1)
{
    char    *pos;
    char    *end;
    int     i;
    int     quote;

    quote = 0;
    i = 0;
    while (cmd[i])
    {
        if (cmd[i] == '\'')
            quote++;
        i++;
    }
    if (quote != 2)
        return (0);
    if (parse1(cmd, cmd1) != 0)
        return (-1);
    return (1);
}
int parse2(char *cmd, t_cmd *cmd2)
{
    char    *pos;
    char    *end;
    
    pos = cmd;
    while (*pos && ft_iswhitespace(*pos))
        pos++;
    end = ft_strchr(pos, ' ');
    if (!end)
        return (1);
    cmd2->cmd = malloc(end - pos + 1);
    if (!cmd2->cmd)
        return (1);
    ft_strncpy(cmd2->cmd, pos, end - pos + 1);
    cmd2->cmd[end - pos] = '\0';
    pos = end + 1;
    cmd2->flag = ft_strdup(pos);
    if (!cmd2->flag)
        return (1);
    cmd2->flag = ft_strtrim(cmd2->flag, "'");
    return (0);
}

int parse_quotes_cmd2(char *cmd, t_cmd *cmd2)
{
    char    *pos;
    char    *end;
    int     i;
    int     quote;

    quote = 0;
    i = 0;
    while (cmd[i])
    {
        if (cmd[i] == '\'')
            quote++;
        i++;
    }
    if (quote != 2)
        return (0);
    if (parse2(cmd, cmd2) != 0)
        return (-1);
    return (1);
}