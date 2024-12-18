/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:46:45 by iullibar          #+#    #+#             */
/*   Updated: 2024/12/09 14:09:22 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*read_line(int fd, char *buffer, char *line)
{
	ssize_t		bytes_read;

	while (ft_strchr(line, '\n') == 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1 || (bytes_read == 0 && ft_strlen(line) == 0))
			return (buffer[0] = '\0', free(line), NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		line = get_line(line, buffer);
		if (line == NULL)
			return (NULL);
	}
	return (line);
}
