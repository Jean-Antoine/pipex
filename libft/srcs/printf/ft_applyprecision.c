/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applyprecision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 08:42:36 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/29 14:48:25 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_substr_(char *str, size_t precision)
{
	size_t	len;
	char	*sub;

	len = ft_strlen(str);
	if (len < precision)
		return (str);
	sub = ft_substr(str, 0, precision);
	free(str);
	return (sub);
}

void	ft_applyprecision(t_field *field)
{
	if (field->type == 's' && !field->str)
		if (field->precision == -2 || field->precision >= 6)
			field->str = ft_strdup("(null)");
	if (field->precision == -2)
		return ;
	if (ft_strchr(NUMERICTYPES, field->type))
	{
		if (field->str[0] == '0' && field->precision == 0)
			field->str[0] = '\0';
		else
			field->str = ft_strpadding(field->str, '0', field->precision, 0);
	}
	else if (field->type == 's')
		field->str = ft_substr_(field->str, field->precision);
}
