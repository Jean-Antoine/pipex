/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readformat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:17:52 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/29 09:44:52 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_substr_c(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (ft_substr(str, 0, i));
}

t_field	*ft_readformat(char *format)
{
	t_field	*field;
	t_field	*lst;

	field = ft_newfld();
	lst = field;
	while (*format)
	{
		if (*format != '%')
		{
			field->str = ft_substr_c(format, '%');
			format = ft_strchr(format, '%');
		}
		else
		{
			ft_readflags(++format, field);
			while (ft_strchr(FLAGS, *format) || ft_strchr(WIDTH, *format))
				format++;
			field->type = *format++;
		}
		if (!format || !*format)
			break ;
		field->next = ft_newfld();
		field = field->next;
	}
	return (lst);
}
