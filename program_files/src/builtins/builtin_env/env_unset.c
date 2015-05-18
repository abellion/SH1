/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 16:05:48 by abellion          #+#    #+#             */
/*   Updated: 2015/02/06 16:01:41 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../ft_minishell1.h"

int			env_unsetenv(char **args, t_list **env)
{
	int		index;

	if (!args[1])
	{
		errors_controller(errors_init(-5, "unsetenv"), &env_errors_printer);
		return (-1);
	}
	index = 1;
	while (args[index])
	{
		*env = env_unset(args[index], *env);
		index++;
	}
	return (1);
}

t_list		*env_unset(char *unset_name, t_list *env)
{
	t_list		*begin;
	char		**splits;

	begin = env;
	while (env)
	{
		splits = ft_strsplit(env->content, '=');
		if (!(ft_strcmp(splits[0], unset_name)))
			return (ft_lstpop(begin, env));
		free(splits);
		env = env->next;
	}
	return (begin);
}
