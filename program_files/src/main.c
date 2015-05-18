/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 18:22:39 by abellion          #+#    #+#             */
/*   Updated: 2015/02/17 16:41:11 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_minishell1.h"

void	disp_lst(t_list *lst)
{
	while (lst)
	{
		ft_putstr(lst->content);
		ft_putchar('\n');
		lst = lst->next;
	}
}

void	signal_traitment(int signal_number)
{
	if (signal_number == SIGINT)
	{
		ft_putstr("\n");
		prompt_controller(NULL, 0);
	}
}

int		main(void)
{
	char			*to_exec;
	t_list			*env_lst;
	t_cmd			*cmd;
	extern char		**environ;

	signal(SIGINT, signal_traitment);
	signal(SIGQUIT, signal_traitment);
	env_lst = env_creator(environ);
	while (42)
	{
		to_exec = prompt_controller(env_lst, 1);
		cmd = cmd_controller(to_exec, env_lst);
		if (cmd && cmd->name)
			launcher_controller(cmd, &env_lst);
		cmd_delete(&cmd);
		(to_exec) ? ft_strdel(&to_exec) : exit_prog();
	}
	return (0);
}
