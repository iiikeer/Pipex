/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:18:33 by iullibar          #+#    #+#             */
/*   Updated: 2024/10/16 10:39:22 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printf_hex(unsigned int nbr, int upper)
{
	int		i;
	int		n;
	char	s[16];
	char	*hex;

	i = 0;
	hex = "0123456789abcdef";
	if (nbr == 0)
		return (write(1, "0", 1), 1);
	while (nbr > 0)
	{
		s[i++] = hex[nbr % 16];
		nbr = nbr / 16;
	}
	n = i;
	if (upper == 1)
	{
		while (n-- > 0)
			s[n] = ft_toupper(s[n]);
	}
	n = i;
	i--;
	while (i >= 0)
		write (1, &s[i--], 1);
	return (n);
}
