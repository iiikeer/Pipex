/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:28:16 by iullibar          #+#    #+#             */
/*   Updated: 2024/11/26 12:51:29 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	exec_cmd1(t_pipex *pipex, int pipe_fd[2], int fds[2], char **env)
{
	pipex->pid = fork();
	if (pipex->pid == -1)
		ft_error(&pipex);
	if (pipex->pid == 0)
	{
		if (dup2(fds[0], STDIN_FILENO) == -1)
			ft_error(&pipex);
		close(fds[0]);
		if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
			ft_error(&pipex);
		close(pipe_fd[1]);
		close(pipe_fd[0]);
		execve(pipex->path, pipex->cmd, env);
		ft_error(&pipex);
	}
}

void	exec_cmd2(t_pipex *pipex, int pipe_fd[2], int fds[2], char **env)
{
	pipex->pid = fork();
	if (pipex->pid == -1)
		ft_error(&pipex);
	if (pipex->pid == 0)
	{
		if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
			ft_error(&pipex);
		close(pipe_fd[1]);
		close(pipe_fd[0]);
		if (dup2(fds[1], STDOUT_FILENO) == -1)
			ft_error(&pipex);
		close(fds[1]);
		execve(pipex->path, pipex->cmd, env);
		ft_error(&pipex);
	}
}

void	exec_pipex(t_pipex **pipex, int pipe_fd[2], int fds[2], char **env)
{
	t_pipex	*node;

	node = *pipex;
	exec_cmd1(node, pipe_fd, fds, env);
	node = node->next;
	exec_cmd2(node, pipe_fd, fds, env);	
}
