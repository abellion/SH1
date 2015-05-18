/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_determine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 18:44:14 by abellion          #+#    #+#             */
/*   Updated: 2015/03/06 16:24:37 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell1.h"

char		**cmd_args(char *path, char **cmd)
{
	char	**args;
	int		index;

	if (!(args = (char **)malloc(sizeof(char **) * (ft_tablen(&cmd[1]) + 1))))
		return (0);
	index = 1;
	while (cmd && cmd[index])
	{
		args[index] = ft_strdup(cmd[index]);
		index++;
	}
	args[0] = path;
	args[index] = NULL;
	return (args);
}

char		*cmd_path(char **path_list, char *cmd_name)
{
	int				index;
	char			*path_tmp;
	char			pwd[1024];

	getcwd(pwd, 1024);
	path_tmp = NULL;
	index = 0;
	while (path_list && path_list[index])
	{
		path_tmp = ft_strcjoin(path_list[index], cmd_name, '/');
		if (path_checker_exec(path_tmp))
			return (path_tmp);
		ft_strdel(&path_tmp);
		index++;
	}
	if (cmd_name && cmd_name[0] == '.')
		path_tmp = ft_strcjoin(pwd, cmd_name, '/');
	else if (cmd_name && cmd_name[0] == '/')
		path_tmp = ft_strdup(cmd_name);
	return (path_tmp);
}
