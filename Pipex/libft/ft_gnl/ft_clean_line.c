/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:06:55 by iullibar          #+#    #+#             */
/*   Updated: 2024/11/28 13:21:33 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gemartin <gemartin@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 00:41:32 by gemartin          #+#    #+#             */
/*   Updated: 2022/07/07 16:41:52 by gemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
