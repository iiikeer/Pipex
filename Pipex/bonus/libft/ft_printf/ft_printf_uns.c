/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:17:54 by iullibar          #+#    #+#             */
/*   Updated: 2024/10/16 10:39:37 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printf_uns(unsigned int nbr)
{
	int		i;
	int		n;
	char	s[11];

	i = 0;
	if (nbr == 0)
		return (write(1, "0", 1), 1);
	while (nbr > 0)
	{
		s[i] = (nbr % 10) + 48;
		nbr = nbr / 10;
		i ++;
	}
	n = i;
	i--;
	while (i >= 0)
		write (1, &s[i--], 1);
	return (n);
}
