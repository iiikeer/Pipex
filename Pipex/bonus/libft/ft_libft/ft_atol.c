/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:19:17 by iullibar          #+#    #+#             */
/*   Updated: 2024/10/17 08:59:22 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

long int	ft_atol(const char *str)
{
	int			i;
	int			s;
	long int	r;

	i = 0;
	s = 1;
	r = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i ++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i ++;
	}
	while (str[i] >= '0' && str [i] <= '9')
	{
		r = r * 10 + (str[i] - '0');
		i ++;
	}
	return (s * r);
}
