/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher_controller.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 16:42:50 by abellion          #+#    #+#             */
/*   Updated: 2015/03/07 19:58:12 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell1.h"

void	launcher_binary(t_cmd *cmd, t_list **env)
{
	pid_t		prog_id;
	char		**env_formated;
	int			status;

	env_formated = lst_to_tab(*env);
	prog_id = fork();
	if (prog_id == 0)
		execve(cmd->args[0], cmd->args, env_formated);
	else
		waitpid(prog_id, &status, WCONTINUED);
}

void	launcher_builtin(t_cmd *cmd, t_list **env)
{
	if (!(ft_strcmp(cmd->name, "env")))
		env_env(cmd->args, env);
	else if (!(ft_strcmp(cmd->name, "setenv")))
		env_setenv(cmd->args, env);
	else if (!(ft_strcmp(cmd->name, "unsetenv")))
		env_unsetenv(cmd->args, env);
	else if (!(ft_strcmp(cmd->name, "cd")))
		builtin_cd(cmd->args, env);
	else if (!(ft_strcmp(cmd->name, "exit")))
		builtin_exit(cmd->args);
}

int		is_available(char *available_cmd, char *cmd)
{
	int		index;
	char	**splits;

	splits = ft_strsplit(available_cmd, ',');
	index = 0;
	while (splits && splits[index])
	{
		if (!ft_strcmp(splits[index], cmd))
		{
			tab_free(&splits);
			return (1);
		}
		index++;
	}
	tab_free(&splits);
	return (0);
}

void	launcher_controller(t_cmd *cmd, t_list **env)
{
	char		*builtins;
	char		*path;
	t_printer	errors_printer;

	path = cmd->path;
	errors_printer = &launcher_errors_printer;
	builtins = ft_strdup("cd,setenv,unsetenv,env,exit");
	if (cmd && is_available(builtins, cmd->name))
		launcher_builtin(cmd, env);
	else if (cmd && path_checker_rights(path) && path_checker_isreg(path))
		launcher_binary(cmd, env);
	else if (cmd)
	{
		if (cmd->name[0] != '.' && cmd->name[0] != '/')
			errors_controller(errors_init(-1, cmd->name), errors_printer);
		else if (!path_checker_exist(path))
			errors_controller(errors_init(-3, cmd->name), errors_printer);
		else if (!path_checker_rights(path) || !path_checker_isreg(path))
			errors_controller(errors_init(-2, cmd->name), errors_printer);
	}
}
