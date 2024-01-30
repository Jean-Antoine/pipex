/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clearfldlst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 08:25:15 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/29 08:05:31 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_clearfldlst(t_field **lst)
{
	t_field	*field;
	t_field	*next;

	if (!lst || !*lst)
		return ;
	next = *lst;
	while (next)
	{
		field = next;
		next = field->next;
		if (field->str)
			free(field->str);
		free(field);
	}
	*lst = NULL;
}
