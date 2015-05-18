/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 17:36:57 by abellion          #+#    #+#             */
/*   Updated: 2015/02/09 18:35:13 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../ft_minishell1.h"

int		builtin_exit(char **args)
{
	if (args_checker(&args[1], 0, 0) == -1)
	{
		errors_controller(errors_init(-1, "exit"), &exit_errors_printer);
		return (-1);
	}
	exit_prog();
	return (1);
}

void	exit_prog(void)
{
	ft_putstr("exit\n");
	exit(EXIT_SUCCESS);
}
