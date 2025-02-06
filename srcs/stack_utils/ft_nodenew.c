/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodenew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:14:52 by iullibar          #+#    #+#             */
/*   Updated: 2025/02/06 10:29:25 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

t_info	*ft_nodenew(int argc, char **argv, char **env)
{
	t_info		*new;

	new = (t_info *)malloc(sizeof(t_info));
	if (!new)
		return (NULL);
	new->argc = argc;
	new->argv = argv;
	new->env = env;
	return (new);
}
