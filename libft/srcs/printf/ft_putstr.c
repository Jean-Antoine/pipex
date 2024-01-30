/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:28:31 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/22 11:44:09 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putcount(int c, int reset)
{
	static int	i;
	int			out;

	if (reset)
	{
		out = i;
		i = 0;
		return (out);
	}
	write(1, &c, 1);
	return (++i);
}

int	ft_putcount_reset(void)
{
	return (ft_putcount(0, 1));
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putcount(*str++, 0);
}

void	ft_putstr_f(char *str, size_t len)
{
	while (len--)
		ft_putchar(*str++);
}

void	ft_putchar(char c)
{
	ft_putcount(c, 0);
}
