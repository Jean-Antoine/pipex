/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readflags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:58:58 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/29 11:07:32 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_readlimits(t_field *field, char *format)
{
	if (ft_isdigit(*format) || *format == '*')
	{
		if (*format == '*')
			field->width = -1;
		else
			field->width = ft_atoi(format);
		while (ft_isdigit(*format) || *format == '*')
			format ++;
	}
	if (*format == '.')
	{
		format++;
		if (ft_isdigit(*format) || *format == '*')
		{
			if (*format == '*')
				field->precision = -1;
			else
				field->precision = ft_atoi(format);
			while (ft_isdigit(*format) || *format == '*')
				format ++;
		}
		else
			field->precision = 0;
	}
}

void	ft_readflags(char *format, t_field *field)
{
	while (ft_strchr(FLAGS, *format))
	{
		if (*format == '-')
			field->left = 1;
		else if (*format == '0')
			field->zero_padded = 1;
		else if (*format == '+' || *format == ' ')
		{
			field->force_sign = 1;
			field->sign_char = *format;
		}
		else if (*format == '#')
			field->hex_prefix = 1;
		format++;
	}
	ft_readlimits(field, format);
}
