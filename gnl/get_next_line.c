/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 15:11:29 by abellion          #+#    #+#             */
/*   Updated: 2015/01/29 19:04:33 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft/includes/libft.h"

int		save_file(int const fd, t_list **file)
{
	int		ret;
	char	buf[BUFF_SIZE];
	t_list	*beggin;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if ((*file)->content)
		{
			(*file)->next = ft_lstnew(buf, ret + 1);
			*file = (*file)->next;
		}
		else
		{
			*file = ft_lstnew(buf, ret + 1);
			beggin = *file;
		}
		if (buf[ret - 1] == '\n')
			return (*file = beggin, 1);
	}
	if (ret < 0)
		return (-1);
	*file = beggin;
	return (1);
}

int		get_next_line(int const fd, char **line)
{
	static t_list	*file;
	unsigned int	index;
	char			*content;

	if (!line || fd < 0 || fd == 1)
		return (-1);
	if ((!file || fd == 0) && (file = ft_lstnew(NULL, 0)))
		if ((save_file(fd, &file)) < 1)
			return (-1);
	*line = "\0";
	while (file)
	{
		index = 0;
		content = file->content;
		while (content[index] && content[index] != '\n')
			index++;
		*line = ft_strjoin(*line, ft_strsub(content, 0, index));
		if (content[index] == '\n' && content[index + 1])
			return (file->content = &content[index + 1], 1);
		else if ((content[index] == '\n' && !content[index + 1]) || !file->next)
			return (file = file->next, 1);
		file = file->next;
	}
	return (0);
}
