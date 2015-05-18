/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_errors_printer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 15:55:38 by abellion          #+#    #+#             */
/*   Updated: 2015/02/11 17:53:29 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../ft_minishell1.h"

void	env_errors_printer(t_error *error)
{
	if (error && error->number && error->details)
	{
		if (error->number == -1)
		{
			ft_putstr_fd("env: illegal option -- ", 2);
			ft_putstr_fd(error->details, 2);
			ft_putstr_fd("\nusage: env [-i] ", 2);
			ft_putstr_fd("[name=value ...] [utility [argument ...]]", 2);
		}
		else
			ft_putstr_fd(error->details, 2);
		if (error->number == -2)
			ft_putstr_fd(": Too many arguments.", 2);
		if (error->number == -3)
			ft_putstr_fd(": Syntax Error.", 2);
		if (error->number == -4)
			ft_putstr_fd(": Expression Syntax.", 2);
		if (error->number == -5)
			ft_putstr_fd(": Too few arguments.", 2);
		ft_putchar_fd('\n', 2);
	}
}
