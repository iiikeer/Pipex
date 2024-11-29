/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 08:51:12 by iullibar          #+#    #+#             */
/*   Updated: 2024/10/16 10:38:00 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned long	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i] != '\0')
	{
		f (i, &s[i]);
		i ++;
	}
}
