/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_here_doc_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:08:06 by iullibar          #+#    #+#             */
/*   Updated: 2024/12/12 09:35:44 by iullibar         ###   ########.fr       */
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
	free(str);
}
