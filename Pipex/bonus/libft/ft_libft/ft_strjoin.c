/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:54:23 by iullibar          #+#    #+#             */
/*   Updated: 2024/11/29 15:26:46 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		indx;
	int		refc;
	char	*line;

	if (!s1 && !s2)
		return (NULL);
	line = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen (s2)) + 1);
	if (!line)
		return (NULL);
	indx = 0;
	while (s1 && s1[indx] != '\0')
	{
		line[indx] = s1[indx];
		indx++;
	}
	refc = 0;
	while (s2 && s2[refc] != '\0')
		line[indx++] = s2[refc++];
	line[indx] = '\0';
	return (line);
}
