/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iullibar <iullibar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:25:01 by iullibar          #+#    #+#             */
/*   Updated: 2024/10/16 10:38:49 by iullibar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lista_n;
	t_list	*nodo_n;

	lista_n = NULL;
	while (lst)
	{
		nodo_n = ft_lstnew(f(lst->content));
		if (!nodo_n)
			ft_lstclear(&lista_n, del);
		else
			ft_lstadd_back(&lista_n, nodo_n);
		lst = lst->next;
	}
	return (lista_n);
}
