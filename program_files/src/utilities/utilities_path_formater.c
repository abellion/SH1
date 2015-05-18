/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_path_formater.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 18:43:46 by abellion          #+#    #+#             */
/*   Updated: 2015/02/20 18:24:25 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell1.h"

char	*path_formater(char *cwd, char *input)
{
	char	**splits;
	char	*tmp;
	char	*final_path;
	int		i;

	i = 0;
	final_path = (input[0] == '/') ? ft_strdup("/") : ft_strdup(cwd);
	splits = ft_strsplit(input, '/');
	while (splits && splits[i])
	{
		if (!ft_strcmp(splits[i], "..") && ft_strcmp(final_path, "/"))
		{
			tmp = ft_strrchr(final_path, '/');
			final_path[ft_strlen(final_path) - ft_strlen(tmp)] = '\0';
		}
		else if (ft_strcmp(splits[i], ".") && ft_strcmp(splits[i], ".."))
			final_path = ft_strcjoin(final_path, splits[i], '/');
		i++;
	}
	return ((final_path[1] == '/') ? &final_path[1] : final_path);
}

char	*path_clear(char *path)
{
	int		index;
	char	**splits;
	char	*new_path;

	index = 0;
	new_path = NULL;
	splits = ft_strsplit(path, '/');
	while (splits && splits[index])
	{
		if (new_path)
			new_path = ft_strcjoin(new_path, splits[index], '/');
		else
		{
			new_path = (path[0] == '/') ? ft_strdup("/") : ft_strdup("");
			new_path = ft_strjoin(new_path, splits[index]);
		}
		index++;
	}
	if (!new_path && path)
		return (ft_strdup("/"));
	return (new_path);
}
