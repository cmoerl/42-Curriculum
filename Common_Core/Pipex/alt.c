

void	parse_cmd2(char *cmd, t_cmd *cmd2)
{
	char	**arr;

	arr = ft_split(cmd, ' ');
	if (!arr)
		return ;
	cmd2->cmd = arr[0];
	if (arr[1] != NULL)
		cmd2->flag1 = arr[1];
	else
		cmd2->flag1 = NULL;
	if (arr[2] != NULL)
		cmd2->flag2 = arr[2];
	else
		cmd2->flag2 = NULL;
}

void	parse_cmd1(char *cmd, t_cmd *cmd1)
{
	char	**arr;

	arr = ft_split(cmd, ' ');
	if (!arr)
		return ;
	cmd1->cmd = arr[0];
	if (arr[1] != NULL)
		cmd1->flag1 = arr[1];
	else
		cmd1->flag1 = NULL;
	if (arr[2] != NULL)
		cmd1->flag2 = arr[2];
	else
		cmd1->flag2 = NULL;
}