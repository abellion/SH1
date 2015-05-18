/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_errors_printer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 15:50:08 by abellion          #+#    #+#             */
/*   Updated: 2015/02/11 20:40:21 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../ft_minishell1.h"

void	cd_errors_printer(t_error *error)
{
	if (error && error->number && error->details)
	{
		ft_putstr_fd("cd: ", 2);
		if (error->number == -1)
			ft_putstr_fd("usage: cd [-pl][directory]", 2);
		if (error->number == -2)
			ft_putstr_fd("no such file or directory: ", 2);
		if (error->number == -3)
			ft_putstr_fd("permission denied: ", 2);
		if (error->number == -4)
			ft_putstr_fd("not a directory: ", 2);
		if (error->number != -1)
			ft_putstr_fd(error->details, 2);
		ft_putchar_fd('\n', 2);
	}
}
