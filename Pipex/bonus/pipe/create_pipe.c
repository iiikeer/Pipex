/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:21:22 by iullibar          #+#    #+#             */
/*   Updated: 2024/11/29 10:32:37 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	create_pipe(t_pipex **pipex, int pipe_fd[2])
{
	if (pipe(pipe_fd) == -1)
		ft_error(pipex, NULL);
}
