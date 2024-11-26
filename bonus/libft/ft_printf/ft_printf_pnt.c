/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:16:17 by iullibar          #+#    #+#             */
/*   Updated: 2024/10/16 10:39:27 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printf_pnt(unsigned long long int ptr)
{
	int		len;
	int		i;
	char	s[16];
	char	*hex;

	len = 0;
	i = 0;
	hex = "0123456789abcdef";
	if (!ptr)
		return (ft_printf_str("(nil)"));
	if (ptr == 0)
		return (write(1, "0x0", 3), 3);
	len = ft_printf_str("0x");
	while (ptr > 0)
	{
		s[i++] = hex[ptr % 16];
		ptr = ptr / 16;
	}
	len = len + i;
	i--;
	while (i >= 0)
		write (1, &s[i--], 1);
	return (len);
}
