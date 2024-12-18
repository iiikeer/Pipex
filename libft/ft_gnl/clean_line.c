/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:06:55 by iullibar          #+#    #+#             */
/*   Updated: 2024/12/09 14:09:09 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	clean_line(char *buffer)
{
	size_t	i;
	size_t	res;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
	{
		res = ft_strlen(&buffer[i + 1]);
		ft_strcpy(buffer, &buffer[i + 1], res);
		buffer[res] = '\0';
	}
	else
		buffer[0] = '\0';
}
