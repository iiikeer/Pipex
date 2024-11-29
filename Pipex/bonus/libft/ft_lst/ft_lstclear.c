/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:24:30 by iullibar          #+#    #+#             */
/*   Updated: 2024/10/16 10:38:41 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nodo_a;
	t_list	*nodo_s;

	while (*lst)
	{
		nodo_a = *lst;
		nodo_s = (*lst)->next;
		ft_lstdelone(nodo_a, del);
		*lst = nodo_s;
	}
}
