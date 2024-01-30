/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:21:35 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/16 11:17:19 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_m;
	t_list	*elmt;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	lst_m = NULL;
	while (lst)
	{
		content = f(lst->content);
		elmt = ft_lstnew(content);
		if (!elmt)
		{
			del(content);
			ft_lstclear(&lst_m, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_m, elmt);
		lst = lst->next;
	}
	return (lst_m);
}
