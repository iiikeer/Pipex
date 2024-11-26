/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_set_cmd_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:02:10 by iullibar          #+#    #+#             */
/*   Updated: 2024/11/26 14:39:52 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	ft_free(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
		free (array[i ++]);
	free (array);
}

void	check_set_cmd_paths(t_pipex **pipex, int argc, char **argv, char **env)
{
	int		i;
	char	**paths;
	t_pipex	*node;

	i = 0;
	paths = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			paths = ft_split(env[i] + 5, ':');
		i++;
	}
	if (!paths)
		ft_error(pipex);
	i = 2;
	while (i < (argc - 1))
	{
		node = ft_stacknew(ft_split(argv[i], ' '));
		if (!node || !node->cmd)
		{
			ft_free(paths);
			ft_error(pipex);
		}
		set_cmd_paths(node, paths, node->cmd[0]);
		if (!node->path)
		{
			ft_free(paths);
			ft_error(pipex);
		}
		ft_add_back(pipex, node);
		node = node->next;
		i ++;
	}
	ft_free(paths);
}
