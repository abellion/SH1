/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_formater_p2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 15:14:36 by abellion          #+#    #+#             */
/*   Updated: 2015/03/11 15:31:45 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell1.h"

char	*clear_exhausts(char *str)
{
	int		index;
	char	**splits;
	char	*new_str;

	index = 0;
	new_str = ft_strdup("");
	splits = ft_strsplit(str, '\\');
	while (splits && splits[index])
	{
		new_str = ft_strjoin(new_str, splits[index]);
		index++;
	}
	return ((ft_strlen(new_str)) ? new_str : NULL);
}

char	*replace_special(char *str, t_list *env)
{
	int		index;
	char	*new_str;

	index = 0;
	new_str = ft_strdup("");
	while (str && str[index])
	{
		if (str[index] == '~' && index == 0)
			new_str = ft_strjoin(new_str, get_from_env_lst("HOME", env));
		else
			new_str = ft_strcjoin(new_str, "", str[index]);
		index++;
	}
	return ((ft_strlen(new_str)) ? new_str : NULL);
}

char	**clear_parts(char **parts, t_list *env)
{
	int		index;
	char	*part;

	index = 0;
	while (parts && parts[index])
	{
		part = parts[index];
		if (is_delimiteur(part[0], 0, 0))
			parts[index] = ft_strsub(part, 1, ft_strlen(part) - 2);
		else
		{
			parts[index] = (index) ? replace_special(part, env) : parts[index];
			parts[index] = clear_exhausts(parts[index]);
		}
		index++;
	}
	return (parts);
}
