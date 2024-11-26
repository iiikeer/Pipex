/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:17:35 by iullibar          #+#    #+#             */
/*   Updated: 2024/10/16 10:39:24 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printf_nbr(int nbr)
{
	int		len;
	int		n;
	char	s[10];

	len = 0;
	n = 0;
	if (nbr == 0)
		return (write(1, "0", 1), 1);
	if (nbr < 0)
		n = ft_printf_char('-');
	while (nbr != 0)
	{
		if (nbr < 0)
			s[len ++] = ((nbr % 10) * -1) + 48;
		else
			s[len ++] = (nbr % 10) + 48;
		nbr = nbr / 10;
		n ++;
	}
	len --;
	while (len >= 0)
		write (1, &s[len --], 1);
	return (n);
}
