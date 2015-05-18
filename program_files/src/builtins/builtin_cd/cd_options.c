/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 14:53:22 by abellion          #+#    #+#             */
/*   Updated: 2015/02/11 14:53:07 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../ft_minishell1.h"

char	*cd_option_p(char *path)
{
	struct stat		infos;
	char			cwd[1024];

	if (!lstat(path, &infos) && S_ISLNK(infos.st_mode))
	{
		getcwd(cwd, 1024);
		return (ft_strdup(cwd));
	}
	return (path);
}
