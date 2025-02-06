/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:02:36 by iullibar          #+#    #+#             */
/*   Updated: 2025/02/06 10:29:23 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

t_pipex	*ft_last_node(t_pipex *stack)
{
	while (stack->next != 0)
		stack = stack->next;
	return (stack);
}
