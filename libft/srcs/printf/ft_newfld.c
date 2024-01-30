/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newfld.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:45:45 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/29 10:46:10 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_field	*ft_newfld(void)
{
	t_field	*field;

	field = (t_field *)ft_calloc(1, sizeof(t_field));
	field->str = NULL;
	field->type = 'r';
	field->width = 0;
	field->precision = -2;
	field->left = 0;
	field->zero_padded = 0;
	field->force_sign = 0;
	field->sign_char = '+';
	field->hex_prefix = 0;
	field->negative = 0;
	field->next = NULL;
	return (field);
}
