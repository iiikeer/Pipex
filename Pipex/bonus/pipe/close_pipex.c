/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:49:52 by iullibar          #+#    #+#             */
/*   Updated: 2024/11/29 15:23:43 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	close_pipex(t_pipex **pipex, t_info *info, int pipe_fd[2], int fds[2])
{
	t_pipex	*node;

	node = *pipex;
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	while (node != NULL)
	{
		waitpid(node->pid, NULL, 0);
		node = node->next;
	}
	close(fds[0]);
	close(fds[1]);
	if (ft_strncmp(info->argv[1], "here_doc", 8) == 0)
		unlink("here_doc");
	free(info);
	ft_free_pipex(pipex);
}
