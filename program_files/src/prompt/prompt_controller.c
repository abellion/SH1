/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 18:39:27 by abellion          #+#    #+#             */
/*   Updated: 2015/02/12 15:47:07 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell1.h"

void		prompt_line(char *user_name, char *curent_d)
{
	ft_putchar('[');
	ft_putstr(user_name);
	ft_putstr(" : ");
	ft_putstr(curent_d);
	ft_putstr("] > ");
}

char		*curent_directory(char *path, char *user_name)
{
	char			*curent_d;

	if ((curent_d = ft_strstr(path, user_name)))
	{
		curent_d = ft_strchr(curent_d, '/');
		curent_d = (curent_d) ? ft_strjoin("~", curent_d) : "~";
		return (curent_d);
	}
	else
		return (path);
}

t_infos		*get_infos(t_list *env)
{
	static char		**old_infos_tab;
	char			**infos_tab;
	t_infos			*infos;

	if (old_infos_tab && !env)
		infos_tab = old_infos_tab;
	else
		infos_tab = lst_to_tab(env);
	infos = (t_infos *)malloc(sizeof(t_infos *));
	infos->user_name = get_from_env_tab("USER", infos_tab);
	infos->path = get_from_env_tab("PWD", infos_tab);
	old_infos_tab = infos_tab;
	return (infos);
}

void		infos_del(t_infos **infos)
{
	if (infos && *infos)
	{
		free((*infos)->user_name);
		free((*infos)->path);
		free(*infos);
		*infos = NULL;
	}
}

char		*prompt_controller(t_list *env, int get_input)
{
	char			*input;
	char			*curent_d;
	int				ret;
	t_infos			*infos;

	infos = get_infos(env);
	curent_d = curent_directory(infos->path, infos->user_name);
	prompt_line(infos->user_name, curent_d);
	infos_del(&infos);
	if (get_input)
		ret = get_next_line(0, &input);
	else
		return (0);
	return ((ret) ? input : 0);
}
