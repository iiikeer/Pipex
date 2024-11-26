/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:01:00 by iullibar          #+#    #+#             */
/*   Updated: 2024/11/26 11:28:59 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_pipex	*pipex;
	int		fds[2];
	int		pipe_fd[2];

	pipex = NULL;
	if (argc != 5)
		ft_error(&pipex);
	check_file(&pipex, argv, fds);
	check_set_cmd_paths(&pipex, argc, argv, env);
	create_pipe(&pipex, pipe_fd);
	exec_pipex(&pipex, pipe_fd, fds, env);
	close_pipex(&pipex, pipe_fd, fds);
	return (0);
}
