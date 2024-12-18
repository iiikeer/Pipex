/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:01:00 by iullibar          #+#    #+#             */
/*   Updated: 2024/12/12 09:35:48 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_pipex	*pipex;
	t_info	*info;
	int		fds[2];
	int		pipe_fd[2];

	pipex = NULL;
	if (argc < 5)
		ft_error(&pipex, NULL);
	if (!check_argv(argc, argv))
		ft_error(&pipex, NULL);
	info = ft_nodenew(argc, argv, env);
	check_file(&pipex, info, fds);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		fill_here_doc(argv[2], fds[0]);
	check_set_cmd_paths(&pipex, info);
	exec_pipex(&pipex, info, pipe_fd, fds);
	close_pipex(&pipex, info, pipe_fd, fds);
	return (0);
}
