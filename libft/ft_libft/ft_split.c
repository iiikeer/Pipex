/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:46:14 by iullibar          #+#    #+#             */
/*   Updated: 2024/11/20 09:03:30 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_free(char **array, int j)
{
	int	i;

	i = 0;
	while (i < j)
		free (array[i ++]);
	free (array);
}

static char	*ft_strcdup(const char *s, const char c)
{
	int		i;
	char	*dup;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i ++;
	dup = malloc(sizeof(char) * (i + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		dup[i] = s[i];
		i ++;
	}
	dup[i] = '\0';
	return (dup);
}

static int	ft_words_count(char const *s, char c)
{
	int	i;
	int	con;

	i = 0;
	con = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i ++;
		if (s[i] != '\0')
			con ++;
		while (s[i] != '\0' && s[i] != c)
			i ++;
	}
	return (con);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		con;
	int		i;

	i = 0;
	con = 0;
	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * (ft_words_count(s, c) + 1));
	if (!split)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i ++;
		if (s[i] != '\0')
		{
			split[con++] = ft_strcdup(&s[i], c);
			if (split[con - 1] == NULL)
				return (ft_free(split, con - 1), NULL);
		}
		while (s[i] != '\0' && s[i] != c)
			i ++;
	}
	return (split[con] = NULL, split);
}
