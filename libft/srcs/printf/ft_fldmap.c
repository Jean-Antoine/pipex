/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fldmap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:04:53 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/29 09:43:27 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fldmap(t_field *field, void (*f)(t_field*))
{
	if (!field)
		return ;
	while (field)
	{
		(*f)(field);
		field = field->next;
	}
}
