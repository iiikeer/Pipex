/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:33:49 by iullibar          #+#    #+#             */
/*   Updated: 2024/10/16 10:38:25 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s) || ft_strlen(s) == 0 || len == 0)
		return (ft_strdup(""));
	if (len >= (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	sub = malloc(sizeof(char) * ((len) + 1));
	if (sub == NULL)
		return (NULL);
	while (i < len && s[start] != '\0')
	{
		sub[i] = s[start + i];
		i ++;
	}
	sub[i] = '\0';
	return (sub);
}
