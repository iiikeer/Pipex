/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:28:16 by iullibar          #+#    #+#             */
/*   Updated: 2025/02/06 10:29:16 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

int	exec_cmd(t_pipex *pipe, t_info *info, int input_fd, int output_fd)
{
	pipe->pid = fork();
	if (pipe->pid == -1)
		return (-1);
	if (pipe->pid == 0)
	{
		if (dup2(input_fd, STDIN_FILENO) == -1)
			return (-1);
		if (dup2(output_fd, STDOUT_FILENO) == -1)
			return (-1);
		close(input_fd);
		close(output_fd);
		execve(pipe->path, pipe->cmd, info->env);
		return (-1);
	}
	return (1);
}

void	exec_pipex(t_pipex **pipex, t_info *info, int pipe_fd[2], int fds[2])
{
	int		prev_fd;
	t_pipex	*node;

	node = *pipex;
	prev_fd = fds[0];
	while (node)
	{
		if (node->next != NULL)
		{
			if (pipe(pipe_fd) == -1)
				ft_error(pipex, info);
			if (exec_cmd(node, info, prev_fd, pipe_fd[1]) == -1)
				ft_error(pipex, info);
			close(pipe_fd[1]);
			if (prev_fd != fds[0])
				close(prev_fd);
			prev_fd = pipe_fd[0];
		}
		else
			if (exec_cmd(node, info, prev_fd, fds[1]) == -1)
				ft_error(pipex, info);
		node = node->next;
	}
}
