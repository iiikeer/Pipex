/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_pipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:43:31 by iullibar          #+#    #+#             */
/*   Updated: 2025/02/06 10:29:33 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

void	ft_free_pipex(t_pipex **pipex)
{
	t_pipex	*node;
	t_pipex	*temp;

	if (pipex)
	{
		node = *pipex;
		while (node)
		{
			temp = node->next;
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
	return ;
}
