/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 16:05:39 by abellion          #+#    #+#             */
/*   Updated: 2015/02/12 18:20:45 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../ft_minishell1.h"

int			env_setenv(char **args, t_list **env)
{
	int			ret;

	if ((ret = args_checker(&args[1], 0, 2)) == -1)
	{
		errors_controller(errors_init(-2, "setenv"), &env_errors_printer);
		return (-1);
	}
	if (ft_strchr(args[1], '='))
	{
		errors_controller(errors_init(-3, "setenv"), &env_errors_printer);
		return (-1);
	}
	if (ret == 0)
		disp_lst(*env);
	else
		*env = env_set(args[1], args[2], *env);
	return (1);
}

t_list		*env_set(char *name, char *value, t_list *env)
{
	t_list		*begin;
	t_list		*prev;
	char		**splits;
	char		*new;

	begin = env;
	prev = NULL;
	value = (!value) ? ft_strdup("") : value;
	name = (!name) ? ft_strdup("") : name;
	new = ft_strcjoin(name, value, '=');
	while (env)
	{
		splits = ft_strsplit(env->content, '=');
		if (!ft_strcmp(splits[0], name))
			return (env->content = new, begin);
		prev = env;
		env = env->next;
	}
	if (prev)
		prev->next = ft_lstnew(new, ft_strlen(new) + 1);
	else
		begin = ft_lstnew(new, ft_strlen(new) + 1);
	return (begin);
}
