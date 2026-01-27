/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrigor2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:25:05 by dgrigor2          #+#    #+#             */
/*   Updated: 2025/02/03 16:43:51 by dgrigor2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p;

	p = 0;
	while (lst)
	{
		ft_lstadd_back(&p, ft_lstnew(f(lst->content)));
		if (!ft_lstlast(p))
		{
			ft_lstclear(&p, del);
			return (0);
		}
		lst = lst->next;
	}
	return (p);
}
