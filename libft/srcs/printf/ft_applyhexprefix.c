/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applyhexprefix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:39:16 by jeada-si          #+#    #+#             */
/*   Updated: 2023/12/05 11:34:25 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_allzeros(char *str)
{
	while (*str)
		if (*str++ != '0')
			return (0);
	return (1);
}

void	ft_applyhexprefix(t_field *field)
{
	if (!(field->hex_prefix && (field->type == 'x' || field->type == 'X')))
		return ;
	if (ft_allzeros(field->str))
		return ;
	field->str = ft_strppd_c(field->str, field->type);
	field->str = ft_strppd_c(field->str, '0');
}
