/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:10:38 by iullibar          #+#    #+#             */
/*   Updated: 2024/10/16 10:38:23 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*trim;
	int		st;
	int		end;
	int		i;

	if (s1 == NULL)
		return (NULL);
	st = 0;
	end = ft_strlen(s1) - 1;
	while (st <= end && ft_strchr(set, s1[st]))
		st++;
	while (st <= end && ft_strchr(set, s1[end]))
		end--;
	trim = malloc(end - st + 1);
	if (trim == NULL)
		return (NULL);
	i = 0;
	while (st <= end)
		trim[i++] = s1[st++];
	trim[i] = '\0';
	return (trim);
}
