/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:53:42 by iullibar          #+#    #+#             */
/*   Updated: 2024/12/12 09:35:54 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	check_cmd_path(t_pipex **pipex, t_info *info, char **paths, int i)
{
	t_pipex	*node;

	while (i < (info->argc - 1))
	{
		node = ft_stacknew(ft_split(info->argv[i], ' '));
		if (!node || !node->cmd)
		{
			ft_free(paths);
			ft_error(pipex, info);
		}
		set_cmd_paths(node, paths, node->cmd[0]);
		if (!node->path)
		{
			ft_free(node->cmd);
			free(node);
			ft_free(paths);
			ft_error(pipex, info);
		}
		ft_add_back(pipex, node);
		node = node->next;
		i ++;
	}
	ft_free(paths);
}
