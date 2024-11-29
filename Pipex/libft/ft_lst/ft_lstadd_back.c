/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:23:55 by iullibar          #+#    #+#             */
/*   Updated: 2024/10/16 10:38:37 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*nodo;

	nodo = *lst;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (nodo->next)
		nodo = nodo->next;
	nodo->next = new;
}
