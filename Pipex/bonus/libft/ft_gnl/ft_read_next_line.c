/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_next_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:46:45 by iullibar          #+#    #+#             */
/*   Updated: 2024/11/29 16:52:38 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_read_next_line(int fd, char *next_line)
{
	int		read_buffer;
	char	*buffer;

	read_buffer = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free_gnl(&next_line));
	buffer[0] = '\0';
	while (read_buffer > 0 && !ft_strchr(buffer, '\n'))
	{
		read_buffer = read (fd, buffer, BUFFER_SIZE);
		if (read_buffer > 0)
		{
			buffer[read_buffer] = '\0';
			//next_line = ft_strjoin(next_line, buffer);
			ft_strcat(next_line,  buffer);
		}
	}
	free(buffer);
	if (read_buffer == -1)
		return (ft_free_gnl(&next_line));
	return (next_line);
}
