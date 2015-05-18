/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 16:04:57 by abellion          #+#    #+#             */
/*   Updated: 2015/02/12 18:37:03 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../ft_minishell1.h"

int			env_env(char **args, t_list **env)
{
	t_list		*env_tmp;
	int			ret;

	if ((ret = env_env_ignore(args)) == -1)
		return (-1);
	env_tmp = (ret) ? NULL : lst_dup(*env);
	env_tmp = env_env_set(args, env_tmp);
	ret = env_env_launcher(args, env_tmp);
	if (!ret)
		disp_lst(env_tmp);
	return (1);
}

int			env_env_ignore(char **args)
{
	char		*options;
	char		*ret;

	options = options_formater(args);
	ret = options_checker("i", options);
	if (ret)
	{
		errors_controller(errors_init(-1, ret), &env_errors_printer);
		return (-1);
	}
	if (ft_strchr(options, 'i'))
		return (1);
	return (0);
}

t_list		*env_env_set(char **args, t_list *env)
{
	int			index;
	char		**split;
	char		*search;

	index = 1;
	while (args[index])
	{
		if (ft_strchr(args[index], '='))
		{
			split = ft_strsplit(args[index], '=');
			search = ft_strchr(args[index], '=');
			if (split[0] && split[1])
				env = env_set(split[0], split[1], env);
			else if (search && search[1])
				env = env_set(NULL, split[0], env);
			else if (search && !search[1])
				env = env_set(split[0], NULL, env);
		}
		index++;
	}
	return (env);
}

int			env_env_launcher(char **args, t_list *env)
{
	char		*to_exec;
	int			index;
	t_cmd		*cmd;

	to_exec = NULL;
	index = 1;
	while (args[index])
	{
		if ((!is_option(args[index]) && !ft_strchr(args[index], '='))
				|| to_exec)
		{
			to_exec = (!to_exec) ? ft_strdup("") : to_exec;
			to_exec = ft_strcjoin(to_exec, args[index], ' ');
		}
		index++;
	}
	if (to_exec)
	{
		cmd = cmd_controller(to_exec, env);
		if (cmd && cmd->name)
			launcher_controller(cmd, &env);
		return (1);
	}
	return (0);
}
