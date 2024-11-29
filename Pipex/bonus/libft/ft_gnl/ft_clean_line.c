/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:48:21 by iullibar          #+#    #+#             */
/*   Updated: 2024/11/29 16:48:35 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_clean_line(char *next_line)
{
	char	*line;
	char	*ptr;
	int		len;

	ptr = ft_strchr(next_line, '\n');
	if (!ptr)
	{
		line = NULL;
		return (ft_free_gnl(&next_line));
	}
	else
		len = (ptr - next_line) + 1;
	if (!next_line[len])
		return (ft_free_gnl(&next_line));
	line = ft_substr(next_line, len, ft_strlen(next_line) - len);
	ft_free_gnl(&next_line);
	if (!line)
		return (NULL);
	return (line);
}
