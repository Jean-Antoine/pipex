/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:00:28 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/16 10:54:13 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next;
	t_list	*elmt;

	if (!lst || !*lst || !del)
		return ;
	next = *lst;
	while (next)
	{
		elmt = next;
		next = next->next;
		ft_lstdelone(elmt, del);
	}
	*lst = NULL;
}
