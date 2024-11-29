/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:31:12 by iullibar          #+#    #+#             */
/*   Updated: 2024/10/16 10:38:07 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (src[len] != '\0')
		len ++;
	if (size == 0)
		return (len);
	while (i < (size - 1) && src[i] != '\0')
	{
		dest[i] = src[i];
		i ++;
	}
	dest[i] = '\0';
	return (len);
}
