/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_path_checker.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 18:43:10 by abellion          #+#    #+#             */
/*   Updated: 2015/02/12 20:05:35 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell1.h"

int		path_checker_rights(char *path)
{
	int				ret;

	ret = access(path, X_OK);
	if (path_checker_exist(path) && ret == 0)
		return (1);
	return (0);
}

int		path_checker_isreg(char *path)
{
	struct stat		infos;
	int				ret;

	ret = stat(path, &infos);
	if (ret == 0 && S_ISREG(infos.st_mode))
		return (1);
	return (0);
}

int		path_checker_isdir(char *path)
{
	struct stat		infos;
	int				ret;

	ret = stat(path, &infos);
	if ((ret == 0 && S_ISDIR(infos.st_mode)) || (ret == -1 && errno == EACCES))
		return (1);
	return (0);
}

int		path_checker_exist(char *path)
{
	struct stat		infos;
	int				ret;

	ret = stat(path, &infos);
	if (ret == 0 || (ret == -1 && errno == EACCES))
		return (1);
	return (0);
}

int		path_checker_exec(char *path)
{
	int				ret;

	ret = access(path, X_OK);
	return ((ret == 0) ? 1 : 0);
}
