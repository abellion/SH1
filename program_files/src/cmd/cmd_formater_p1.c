/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_formater_p1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 15:14:29 by abellion          #+#    #+#             */
/*   Updated: 2015/02/12 19:55:57 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell1.h"

char	is_delimiteur(char curent, char prev, char delimiter)
{
	if (curent == '\'' || curent == '\"')
	{
		if (delimiter && delimiter != curent)
			return (0);
		else if (prev && prev == '\\')
			return (0);
		else
			return (curent);
	}
	return (0);
}

int		return_part(char *str, char **save)
{
	int		index;
	int		end;
	char	*old_str;
	char	prev;
	char	delimiter;

	old_str = ft_strdup(str);
	str = ft_strtrim(str);
	delimiter = is_delimiteur(str[0], 0, 0);
	end = 0;
	index = 0;
	while (str && str[index] && end == 0)
	{
		if (delimiter && index && is_delimiteur(str[index], prev, delimiter))
			index++, end++;
		else if (!delimiter && is_delimiteur(str[index], prev, 0))
			end++;
		else if (!delimiter && (str[index] == ' ' || str[index] == '\t'))
			end++;
		else
			index++;
		prev = str[index - 1];
	}
	*save = ft_strsub(str, 0, index);
	return (ft_strlen(old_str) - ft_strlen(str) + index);
}

char	**make_parts(char *str)
{
	int		index_str;
	int		index_parts;
	char	**parts;

	if (!(parts = (char **)malloc(sizeof(char **) * (ft_strlen(str) + 1))))
		return (0);
	index_str = 0;
	index_parts = 0;
	while (str && str[index_str])
	{
		index_str += return_part(&str[index_str], &parts[index_parts]);
		index_parts++;
	}
	parts[index_parts] = NULL;
	return (parts);
}

char	**cmd_formater(char *str, t_list *env)
{
	char	**parts;

	if (!str)
		return (0);
	parts = make_parts(str);
	parts = clear_parts(parts, env);
	return (parts);
}
