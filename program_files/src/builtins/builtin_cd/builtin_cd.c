/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 20:35:38 by abellion          #+#    #+#             */
/*   Updated: 2015/02/15 18:33:37 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../ft_minishell1.h"

int		builtin_cd(char **args, t_list **env)
{
	char	*input;
	char	*options;
	char	*path;
	char	*old_path;

	options = options_formater(args);
	input = args_input(&args[1]);
	if (cd_errors(options, input) != 1)
		return (-1);
	path = determine_path(input, *env);
	old_path = get_from_env_lst("PWD", *env);
	if (ft_strlen(path) && chdir(path) == 0)
	{
		path = (ft_strchr(options, 'P')) ? cd_option_p(path) : path;
		*env = env_set("PWD", path, *env);
		*env = env_set("OLDPWD", old_path, *env);
	}
	return (1);
}

int		cd_errors(char *options, char *input)
{
	char	*ret;

	if ((ret = options_checker("LP", options)))
		errors_controller(errors_init(-1, ret), &cd_errors_printer);
	else if (!input)
		return (1);
	else if (!path_checker_exist(input))
		errors_controller(errors_init(-2, input), &cd_errors_printer);
	else if (!path_checker_isdir(input))
		errors_controller(errors_init(-4, input), &cd_errors_printer);
	else if (!path_checker_rights(input))
		errors_controller(errors_init(-3, input), &cd_errors_printer);
	else
		return (1);
	return (-1);
}
