/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:45:50 by iullibar          #+#    #+#             */
/*   Updated: 2024/10/16 10:36:33 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_get_line(const char *next_line)
{
	int		indx;
	char	*line;

	indx = 0;
	if (!next_line[indx])
		return (NULL);
	while (next_line[indx] != '\0' && next_line[indx] != '\n')
		indx ++;
	line = malloc(sizeof(char) * (indx + 2));
	if (!line)
		return (NULL);
	indx = 0;
	while (next_line[indx] != '\0' && next_line[indx] != '\n')
	{
		line[indx] = next_line[indx];
		indx ++;
	}
	if (next_line[indx] == '\n')
		line[indx++] = '\n';
	line[indx] = '\0';
	return (line);
}
