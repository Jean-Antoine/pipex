/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:12:32 by jeada-si          #+#    #+#             */
/*   Updated: 2024/01/09 10:43:53 by jeada-si         ###   ########.fr       */
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

double	ft_atof(const char *nptr)
{
	double	out;
	int		sign;
	double	pos;

	out = 0;
	pos = 0.1;
	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		sign = -1;
		if (*nptr++ == '+')
			sign = 1;
	}
	while (ft_isdigit(*nptr))
		out = out * 10 + (*nptr++ - '0');
	if (*nptr++ != '.')
		return (out * sign);
	while (ft_isdigit(*nptr))
	{
		out = out + ((*nptr++ - '0') * pos);
		pos = pos * 0.1;
	}		
	return (out * sign);
}
