/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:43:27 by iullibar          #+#    #+#             */
/*   Updated: 2025/02/06 10:29:31 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

void	ft_error(t_pipex **pipex, t_info *info)
{
	static int	error;

	ft_free_pipex(pipex);
	if (info)
		free(info);
	if (error == 0)
	{
		ft_printf("Error\n");
		error = 1;
	}
	exit(EXIT_FAILURE);
}
