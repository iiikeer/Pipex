/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacknew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:11:47 by iullibar          #+#    #+#             */
/*   Updated: 2024/11/26 11:03:59 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

t_pipex	*ft_stacknew(char **command)
{
	t_pipex		*new;

	new = (t_pipex *)malloc(sizeof(t_pipex));
	if (!new)
		return (NULL);
	new->infile = -1;
	new->outfile = -1;
	new->cmd = command;
	new->path = NULL;
	new->pid = -1;
	new->next = NULL;
	return (new);
}
