/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_errors_printer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 18:17:34 by abellion          #+#    #+#             */
/*   Updated: 2015/03/06 20:59:53 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell1.h"

void		launcher_errors_printer(t_error *error)
{
	if (error && error->number && error->details)
	{
		ft_putstr_fd("minishell: ", 2);
		if (error->number == -1)
			ft_putstr_fd("command not found: ", 2);
		if (error->number == -2)
			ft_putstr_fd("permission denied: ", 2);
		if (error->number == -3)
			ft_putstr_fd("no such file or directory: ", 2);
		ft_putstr_fd(error->details, 2);
		ft_putchar_fd('\n', 2);
	}
}
