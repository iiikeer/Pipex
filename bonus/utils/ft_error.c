/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:43:27 by iullibar          #+#    #+#             */
/*   Updated: 2024/11/26 11:27:40 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_error(t_pipex **pipex)
{
	ft_free_pipex(pipex);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}
