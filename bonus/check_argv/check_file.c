/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 08:54:07 by iullibar          #+#    #+#             */
/*   Updated: 2024/11/25 10:47:26 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	check_file(t_pipex **pipex, char **argv, int fds[2])
{
	if (!access(argv[1], F_OK) == 0)
		ft_error(pipex);
	if (!access(argv[1], R_OK) == 0)
		ft_error(pipex);
	fds[0] = open(argv[1], O_RDONLY);
	if (fds[0] == -1)
		ft_error(pipex);
	fds[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fds[1] == -1)
		ft_error(pipex);
}
