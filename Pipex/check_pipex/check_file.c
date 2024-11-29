/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 08:54:07 by iullibar          #+#    #+#             */
/*   Updated: 2024/11/29 12:03:40 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	check_file(t_pipex **pipex, t_info *info, int fds[2])
{
	char	*infile;
	char	*outfile;

	infile = info->argv[1];
	outfile = info->argv[info->argc - 1];
	if (!access(infile, F_OK) == 0)
		ft_error(pipex, info);
	if (!access(infile, R_OK) == 0)
		ft_error(pipex, info);
	fds[0] = open(infile, O_RDONLY);
	if (fds[0] == -1)
		ft_error(pipex, info);
	fds[1] = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fds[1] == -1)
		ft_error(pipex, info);
}
