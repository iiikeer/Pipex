/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cmd_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:00:24 by iullibar          #+#    #+#             */
/*   Updated: 2024/12/12 09:36:04 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	set_cmd_paths(t_pipex *pipex, char **paths, char *cmd)
{
	char	*cmd_path;
	int		i;

	i = 0;
	while (paths[i])
	{
		cmd_path = check_path(cmd, paths[i]);
		if (cmd_path)
		{
			if (pipex->path)
				free(pipex->path);
			pipex->path = cmd_path;
			return ;
		}
		i++;
	}
}
