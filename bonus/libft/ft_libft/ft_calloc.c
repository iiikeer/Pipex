/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:42:54 by iullibar          #+#    #+#             */
/*   Updated: 2024/10/16 10:37:03 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	i;

	i = 0;
	p = malloc(nmemb * size);
	if (p == NULL)
		return (NULL);
	while (i < (nmemb * size))
	{
		((char *)p)[i] = 0;
		i ++;
	}
	return (p);
}
