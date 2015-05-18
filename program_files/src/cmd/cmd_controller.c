/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_controller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 18:11:37 by abellion          #+#    #+#             */
/*   Updated: 2015/03/04 19:43:38 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell1.h"

t_cmd		*cmd_init(char *name, char *path, char **args)
{
	t_cmd			*cmd;

	if (!(cmd = (t_cmd *)malloc(sizeof(cmd))))
		return (0);
	cmd->name = name;
	cmd->path = path;
	cmd->args = args;
	return (cmd);
}

void		cmd_delete(t_cmd **cmd)
{
	if (cmd && *cmd)
	{
		ft_strdel(&(*cmd)->name);
		ft_strdel(&(*cmd)->path);
		free(&(*cmd)->args);
		free(*cmd);
		*cmd = NULL;
	}
}

t_cmd		*cmd_controller(char *to_exec, t_list *env)
{
	char			**paths;
	extern char		**environ;
	char			**cmd_formated;
	t_cmd			*cmd;

	to_exec = ft_strtrim(to_exec);
	if (!to_exec || !ft_strlen(to_exec))
		return (0);
	cmd_formated = cmd_formater(to_exec, env);
	if (cmd_formated)
	{
		cmd = cmd_init(NULL, NULL, NULL);
		paths = ft_strsplit(environ[0], ':');
		cmd->name = ft_strdup(cmd_formated[0]);
		cmd->path = cmd_path(paths, cmd->name);
		cmd->args = cmd_args(cmd->path, cmd_formated);
		tab_free(&cmd_formated);
		tab_free(&paths);
	}
	return ((cmd) ? cmd : NULL);
}
