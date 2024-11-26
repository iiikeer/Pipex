/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_pipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:43:31 by iullibar          #+#    #+#             */
/*   Updated: 2024/11/26 10:52:23 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	ft_free(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free (array[i ++]);
	free (array);
}

void	ft_free_pipex(t_pipex **pipex)
{
	t_pipex *node;
	t_pipex	*temp;

	if (pipex)
	{
		node = *pipex;
		while (node != NULL)
		{
			temp = node->next;
			if (node->infile != -1)
				close(node->infile);
			if (node->outfile != -1)
				close(node->outfile);
			if (node->cmd)
				ft_free(node->cmd);
			if (node->path)
				free(node->path);
			if (node->pid != -1)
				waitpid(node->pid, NULL, 0);
			free(node);
			node = temp;
		}
		*pipex = NULL;
	}
}
