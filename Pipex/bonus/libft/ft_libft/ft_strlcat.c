/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:31:36 by iullibar          #+#    #+#             */
/*   Updated: 2024/11/29 16:45:02 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	src_len;
	size_t	dst_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dest);
	i = dst_len;
	j = 0;
	if (size > src_len + dst_len)
		size = src_len + dst_len + 1;
	while (i < size - 1 && src[j] != '\0' && size > 0)
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	if (src_len + dst_len > src_len + size)
		return (src_len + size);
	else
		return (src_len + dst_len);
}
