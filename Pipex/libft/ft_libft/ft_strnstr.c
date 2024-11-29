/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:34:28 by iullibar          #+#    #+#             */
/*   Updated: 2024/10/16 10:38:17 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (str == NULL || to_find == NULL)
		return (NULL);
	if (to_find[0] == '\0')
		return ((char *)str);
	while ((str[i] != '\0') && (i < n))
	{
		j = 0;
		while ((str[i + j] == to_find[j]) && (i + j) < n)
		{
			if (to_find[j + 1] == '\0')
				return (&((char *)str)[i]);
			j ++;
		}
		i ++;
	}
	return (NULL);
}
