/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:47:21 by iullibar          #+#    #+#             */
/*   Updated: 2024/11/28 13:17:32 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *next_line)
{
	char	*line;
	char	*ptr;
	int		len;

	ptr = ft_strchr(next_line, '\n');
	len = (ptr - next_line) + 1;
	line = ft_substr(next_line, 0, len);
	if (!line)
		return (NULL);
	return (line);
}
