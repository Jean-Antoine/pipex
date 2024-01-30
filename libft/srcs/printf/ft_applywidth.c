/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applywidth.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 08:50:24 by jeada-si          #+#    #+#             */
/*   Updated: 2023/12/07 08:52:56 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_applywidth(t_field *field)
{
	size_t	len;
	int		zero_c;

	zero_c = (field->type == 'c' && !field->str[0]);
	if (ft_strchr(NUMERICTYPES, field->type) && field->precision != -2)
		field->zero_padded = 0;
	if (field->type == 's' || field->type == 'c')
		field->zero_padded = 0;
	len = ft_strlen(field->str);
	if (len >= (size_t)field->width)
		return ;
	if (field->zero_padded)
		field->str = ft_strpadding(field->str, '0', field->width, field->left);
	else
		field->str = ft_strpadding(field->str, ' ', field->width, field->left);
	if (field->zero_padded && field->negative)
	{
		field->str[0] = '-';
		field->str[field->width - len] = '0';
	}
	if (zero_c)
		field->str[!field->left * (field->width - 1)] = '\0';
}
