/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_set_cmd_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:02:10 by iullibar          #+#    #+#             */
/*   Updated: 2025/02/06 10:29:02 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

void	check_set_cmd_paths(t_pipex **pipex, t_info *info)
{
	int		i;
	char	**paths;

	i = 0;
	paths = NULL;
	while (info->env[i])
	{
		if (ft_strncmp(info->env[i], "PATH=", 5) == 0)
			paths = ft_split(info->env[i] + 5, ':');
		i++;
	}
	if (!paths)
		ft_error(pipex, info);
	if (ft_strncmp(info->argv[1], "here_doc", 8) == 0)
		i = 3;
	else
		i = 2;
	check_cmd_path(pipex, info, paths, i);
}
