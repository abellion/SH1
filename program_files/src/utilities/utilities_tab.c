/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 14:38:55 by abellion          #+#    #+#             */
/*   Updated: 2015/02/17 16:26:51 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell1.h"

int		ft_tablen(char **tab)
{
	int		index;

	index = 0;
	while (tab && tab[index])
		index++;
	return (index + 1);
}

char	*ft_tabjoin(char **tab)
{
	int		index;
	char	*str;

	str = ft_strdup("");
	index = 0;
	while (tab && tab[index])
	{
		str = ft_strjoin(str, tab[index]);
		if (tab[index + 1])
			str = ft_strjoin(str, " ");
		index++;
	}
	return (str);
}

void	tab_free(char ***tab)
{
	int		index;

	index = 0;
	if (tab)
	{
		while ((*tab)[index])
		{
			ft_strdel(&(*tab)[index]);
			index++;
		}
		free(*tab);
		*tab = NULL;
	}
}
