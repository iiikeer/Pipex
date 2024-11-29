/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:05:29 by iullibar          #+#    #+#             */
/*   Updated: 2024/10/16 10:38:12 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned long	i;
	unsigned long	l;
	char			*str;

	if (s == NULL || f == NULL)
		return (NULL);
	l = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (l + 1));
	if (str == 0)
		return (str);
	i = 0;
	while (i < l)
	{
		str[i] = (*f)(i, s[i]);
		++i;
	}
	str[i] = 0;
	return (str);
}
