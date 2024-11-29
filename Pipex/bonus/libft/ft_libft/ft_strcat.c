/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:37:25 by iullibar          #+#    #+#             */
/*   Updated: 2024/11/29 16:46:18 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_strcat(char *dest, const char *src)
{
	size_t	i;
	size_t	dst_len;

	i = 0;
	dst_len = ft_strlen(dest);
	while (src[i] != '\0')
	{
		dest[dst_len + i] = src[i];
		i ++;
	}
	dest[dst_len + i] = '\0';
}
