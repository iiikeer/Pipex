/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:45:45 by iullibar          #+#    #+#             */
/*   Updated: 2024/10/16 10:35:13 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_clean_line(char *next_line)
{
	int		indx;
	int		refc;
	char	*line;

	indx = 0;
	while (next_line[indx] != '\0' && next_line[indx] != '\n')
		indx ++;
	if (!next_line[indx])
	{
		free(next_line);
		return (NULL);
	}
	line = (char *)malloc(sizeof(char) * (ft_strlen(next_line) - indx + 1));
	if (!line)
		return (NULL);
	refc = 0;
	indx ++;
	while (next_line[indx] != '\0')
		line[refc++] = next_line[indx++];
	line[refc] = '\0';
	free(next_line);
	return (line);
}
