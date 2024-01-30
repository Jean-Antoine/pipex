/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:47:09 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/14 13:11:27 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c >= 9 && c <= 13)
		return (1);
	if (c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	out;
	int	sign;

	sign = 1;
	out = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr++ == '+')
			sign = 1;
		else
			sign = -1;
	}
	while (ft_isdigit(*nptr))
		out = out * 10 + (*nptr++ - '0');
	return (out * sign);
}
