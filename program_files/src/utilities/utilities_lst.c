/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 19:12:07 by abellion          #+#    #+#             */
/*   Updated: 2015/02/07 14:28:16 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell1.h"

int			count_links(t_list *lst)
{
	int			nb;

	nb = 0;
	while (lst)
	{
		nb++;
		lst = lst->next;
	}
	return (nb);
}

char		**lst_to_tab(t_list *lst)
{
	int			nb_links;
	int			index;
	char		**tab;

	nb_links = count_links(lst);
	if (!(tab = (char **)malloc(sizeof(char **) * (nb_links + 1))))
		return (0);
	index = 0;
	while (lst)
	{
		tab[index] = ft_strdup(lst->content);
		index++;
		lst = lst->next;
	}
	tab[index] = NULL;
	return (tab);
}

t_list		*lst_dup(t_list *lst)
{
	t_list		*dup;
	t_list		*begin;

	dup = ft_lstnew("", 1);
	begin = dup;
	while (lst)
	{
		dup->next = ft_lstnew(lst->content, ft_strlen(lst->content) + 1);
		dup = dup->next;
		lst = lst->next;
	}
	return (begin->next);
}
