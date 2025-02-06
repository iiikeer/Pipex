/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:27:45 by iullibar          #+#    #+#             */
/*   Updated: 2025/02/06 10:29:20 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

void	ft_add_back(t_pipex **stack, t_pipex *new)
{
	t_pipex	*nodo;

	nodo = *stack;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	while (nodo->next)
		nodo = nodo->next;
	nodo->next = new;
}
