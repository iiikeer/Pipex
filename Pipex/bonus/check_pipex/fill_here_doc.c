/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_here_doc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:08:06 by iullibar          #+#    #+#             */
/*   Updated: 2024/11/29 15:24:19 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	fill_here_doc(char *limit, int fd)
{
	char	*str;

	str = get_next_line(0);
	while (ft_strncmp(str, limit, ft_strlen(limit)) != 0)
	{
		ft_putstr_fd(str, fd);
		free(str);
		str = get_next_line(0);
	}
	ft_putstr_fd(str, fd);
	free(str);
}
