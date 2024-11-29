/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:29:24 by iullibar          #+#    #+#             */
/*   Updated: 2024/10/16 10:39:39 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_switch_case(va_list args, const char c)
{
	int	cont;

	if (c == '%')
	{
		write(1, "%", 1);
		cont = 1;
	}
	else if (c == 'c')
		cont = ft_printf_char(va_arg(args, int));
	else if (c == 's')
		cont = ft_printf_str(va_arg(args, char *));
	else if (c == 'p')
		cont = ft_printf_pnt(va_arg(args, unsigned long long int));
	else if (c == 'd' || c == 'i')
		cont = ft_printf_nbr(va_arg(args, int));
	else if (c == 'u')
		cont = ft_printf_uns(va_arg(args, unsigned int));
	else if (c == 'x')
		cont = ft_printf_hex(va_arg(args, unsigned int), 0);
	else if (c == 'X')
		cont = ft_printf_hex(va_arg(args, unsigned int), 1);
	return (cont);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		cont;

	i = 0;
	cont = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			cont += ft_switch_case(args, str[i + 1]);
			i ++;
		}
		else
		{
			write(1, &str[i], 1);
			cont ++;
		}
		i ++;
	}
	va_end(args);
	return (cont);
}
