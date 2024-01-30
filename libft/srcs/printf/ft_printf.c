/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:50:41 by jeada-si          #+#    #+#             */
/*   Updated: 2024/01/15 18:19:46 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_max_(size_t a, size_t b)
{
	if (a < b)
		return (b);
	return (a);
}

static void	ft_printfld(t_field *field)
{
	if (!field->str)
		return ;
	if (field->type == 'c')
		ft_putstr_f(field->str, ft_max_(field->width, 1));
	else
		ft_putstr(field->str);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_field	*fields;

	if (!format)
		return (-1);
	ft_putcount_reset();
	va_start(args, format);
	fields = ft_readformat((char *)format);
	ft_readparams(fields, args);
	va_end(args);
	ft_fldmap(fields, ft_applyprecision);
	ft_fldmap(fields, ft_applysign);
	ft_fldmap(fields, ft_applyhexprefix);
	ft_fldmap(fields, ft_applywidth);
	ft_fldmap(fields, ft_printfld);
	ft_clearfldlst(&fields);
	return (ft_putcount_reset());
}
