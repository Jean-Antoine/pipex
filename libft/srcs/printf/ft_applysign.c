/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applysign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:15:41 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/29 11:33:53 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_applysign(t_field *field)
{
	if (!ft_strchr(NUMERICSIGNEDTYPES, field->type))
		return ;
	if (field->negative)
		field->str = ft_strppd_c(field->str, '-');
	else if (field->force_sign)
		field->str = ft_strppd_c(field->str, field->sign_char);
}
