/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readparams.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:44:26 by jeada-si          #+#    #+#             */
/*   Updated: 2023/12/05 10:38:14 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_ctostr(char c)
{
	char	*out;

	out = (char *)ft_calloc(2, sizeof(char));
	*out = c;
	return (out);
}

static char	*ft_strdup_(char *str)
{
	if (!str)
		return (NULL);
	return (ft_strdup(str));
}

static void	ft_readsignednbr(t_field *field, long long int n)
{
	field->negative = n < 0;
	if (field->negative)
		n = n * -1;
	field->str = ft_uitostr(n, DECBASE);
}

static void	ft_readprecision(t_field *field, va_list args)
{
	if (field->width == -1)
		field->width = va_arg(args, int);
	if (field->precision == -1)
		field->precision = va_arg(args, int);
	return ;
}

void	ft_readparams(t_field *fields, va_list args)
{
	while (fields)
	{
		ft_readprecision(fields, args);
		if (fields->type == '%')
			fields->str = ft_strdup("%");
		else if (fields->type == 'c')
			fields->str = ft_ctostr(va_arg(args, int));
		else if (fields->type == 's')
			fields->str = ft_strdup_(va_arg(args, char *));
		else if (fields->type == 'p')
			fields->str = ft_ptrtostr(va_arg(args, void *));
		else if (fields->type == 'd' || fields->type == 'i')
			ft_readsignednbr(fields, va_arg(args, int));
		else if (fields->type == 'u')
			fields->str = ft_uitostr(va_arg(args, unsigned int), DECBASE);
		else if (fields->type == 'x')
			fields->str = ft_uitostr(va_arg(args, unsigned int), HEXBASE);
		else if (fields->type == 'X')
			fields->str = ft_uitostr(va_arg(args, unsigned int), HEXBASEUP);
		fields = fields->next;
	}
}
