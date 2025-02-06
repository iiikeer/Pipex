/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 08:54:07 by iullibar          #+#    #+#             */
/*   Updated: 2025/02/06 10:28:58 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

void	check_file(t_pipex **pipex, t_info *info, int fds[2])
{
	char	*infile;
	char	*outfile;

	infile = info->argv[1];
	outfile = info->argv[info->argc - 1];
	if (ft_strncmp(info->argv[1], "here_doc", 4) != 0)
	{
		fds[0] = open(infile, O_RDONLY);
		if (fds[0] == -1)
			ft_error(pipex, info);
		fds[1] = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fds[1] == -1)
			ft_error(pipex, info);
	}
	else
	{
		fds[0] = open(infile, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fds[0] == -1)
			ft_error(pipex, info);
		fds[1] = open(outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fds[1] == -1)
			ft_error(pipex, info);
	}
}
