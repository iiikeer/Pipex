/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_next_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:45:12 by iullibar          #+#    #+#             */
/*   Updated: 2024/10/16 10:36:39 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_read_next_line(int fd, char *next_line)
{
	int		read_buffer;
	char	*buffer;

	read_buffer = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (read_buffer != 0 && !ft_strchr(next_line, '\n'))
	{
		read_buffer = read(fd, buffer, BUFFER_SIZE);
		if (read_buffer == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_buffer] = '\0';
		next_line = ft_strjoin(next_line, buffer);
	}
	free(buffer);
	return (next_line);
}
