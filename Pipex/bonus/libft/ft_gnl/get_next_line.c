/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:58:39 by iullibar          #+#    #+#             */
/*   Updated: 2024/11/29 16:49:30 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*get_next_line(int fd)
{
	static char	*next_line;
	char		*line;

	if (fd < 0)
		return (NULL);
	if ((next_line && !ft_strchr(next_line, '\n')) || !next_line)
		next_line = ft_read_next_line(fd, next_line);
	if (!next_line)
		return (NULL);
	line = ft_get_line(next_line);
	if (!line)
		return (ft_free_gnl(&next_line));
	next_line = ft_clean_line(next_line);
	return (line);
}
