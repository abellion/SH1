/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:52:48 by abellion          #+#    #+#             */
/*   Updated: 2015/02/20 18:24:27 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../ft_minishell1.h"

char	*determine_path(char *path, t_list *env)
{
	char	*home;
	char	*pwd;
	char	*final_path;

	home = get_from_env_lst("HOME", env);
	pwd = get_from_env_lst("PWD", env);
	path = path_clear(path);
	if (!path)
		final_path = absolute_path(home);
	else
		final_path = relative_path(pwd, path);
	return (final_path);
}

char	*absolute_path(char *home)
{
	char	*path;

	if (home && ft_strlen(home))
		path = home;
	else
		path = "./";
	return (path);
}

char	*relative_path(char *pwd, char *path)
{
	char	*final_path;

	final_path = path_formater(pwd, path);
	return (final_path);
}
