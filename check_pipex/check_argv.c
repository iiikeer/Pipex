/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:20:42 by iullibar          #+#    #+#             */
/*   Updated: 2024/12/12 09:35:52 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	check_argv(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < (argc - 1))
	{
		if (ft_strncmp(argv[i], "", 1) == 0)
			return (0);
		i ++;
	}
	return (1);
}
