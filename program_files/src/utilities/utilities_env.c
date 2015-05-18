/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 18:08:25 by abellion          #+#    #+#             */
/*   Updated: 2015/02/06 16:21:58 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell1.h"

char		*get_from_env_tab(char *to_get, char **env)
{
	int			index;
	char		**ret;

	index = 0;
	while (env && env[index])
	{
		ret = ft_strsplit(env[index], '=');
		if (!ft_strcmp(ret[0], to_get))
			return (ret[1]);
		index++;
	}
	return (0);
}

char		*get_from_env_lst(char *to_get, t_list *env)
{
	char		**ret;

	while (env)
	{
		ret = ft_strsplit(env->content, '=');
		if (!ft_strcmp(ret[0], to_get))
			return (ret[1]);
		env = env->next;
	}
	return (0);
}

t_list		*env_creator(char **env)
{
	t_list		*env_lst;
	t_list		*begin;
	int			index;

	index = 0;
	env_lst = NULL;
	begin = NULL;
	while (env && env[index])
	{
		if (!env_lst)
		{
			env_lst = ft_lstnew(env[index], ft_strlen(env[index]) + 1);
			begin = env_lst;
		}
		else
		{
			env_lst->next = ft_lstnew(env[index], ft_strlen(env[index]) + 1);
			env_lst = env_lst->next;
		}
		index++;
	}
	return (begin);
}
