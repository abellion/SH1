/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 17:39:56 by abellion          #+#    #+#             */
/*   Updated: 2015/02/18 19:13:41 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell1.h"

int			args_checker(char **args, int nb_min, int nb_max)
{
	int			index;

	index = 0;
	while (args && args[index])
		index++;
	if (index < nb_min || index > nb_max)
		return (-1);
	return (index);
}

int			is_option(char *options)
{
	if (options && options[0] && options[0] == '-')
		return (1);
	return (0);
}

char		*args_input(char **args)
{
	int		index;

	index = 0;
	while (args && is_option(args[index]))
		index++;
	return ((args && args[index]) ? args[index] : 0);
}

char		*options_formater(char **args)
{
	int		index;
	char	*formated;

	formated = NULL;
	index = 1;
	while (args && args[index] && is_option(args[index]))
	{
		formated = (!formated) ? ft_strdup("") : formated;
		formated = ft_strjoin(formated, &args[index][1]);
		index++;
	}
	return (formated);
}

char		*options_checker(char *available_options, char *options)
{
	int		index;

	index = 0;
	while (options && options[index])
	{
		if (!(ft_strchr(available_options, options[index])))
			return (options[index + 1] = '\0', &options[index]);
		index++;
	}
	return (0);
}
