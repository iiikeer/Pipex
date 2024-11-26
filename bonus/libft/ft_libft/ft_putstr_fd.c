/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:33:31 by iullibar          #+#    #+#             */
/*   Updated: 2024/10/16 10:37:47 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	count;

	count = 0;
	if (s == NULL)
		return ;
	while (s[count] != '\0')
	{
		write(fd, &s[count], 1);
		count++;
	}
}
