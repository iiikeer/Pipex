/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:40:16 by iullibar          #+#    #+#             */
/*   Updated: 2024/12/12 09:36:32 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_free(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
		free (array[i ++]);
	free (array);
}
