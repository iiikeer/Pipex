/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:47:21 by iullibar          #+#    #+#             */
/*   Updated: 2024/12/09 14:09:16 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*get_line(char *line, char *buffer)
{
	char	*new_line;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(line);
	len2 = 0;
	while (buffer[len2] != '\0' && buffer[len2] != '\n')
		len2++;
	if (buffer[len2] == '\n')
		len2++;
	new_line = (char *)malloc(len1 + len2 + 1);
	if (new_line == NULL)
		return (free(line), NULL);
	ft_strcpy(new_line, line, len1);
	ft_strcpy(new_line + len1, buffer, len2);
	new_line[len1 + len2] = '\0';
	return (free(line), new_line);
}
