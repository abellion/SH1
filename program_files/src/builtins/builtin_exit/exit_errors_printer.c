/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_errors_printer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 16:03:52 by abellion          #+#    #+#             */
/*   Updated: 2015/02/11 17:56:39 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../ft_minishell1.h"

void	exit_errors_printer(t_error *error)
{
	if (error && error->number && error->details)
	{
		if (error->number == -1)
		{
			ft_putstr_fd(error->details, 2);
			ft_putstr_fd(": Expression Syntax.", 2);
		}
		ft_putchar_fd('\n', 2);
	}
}
