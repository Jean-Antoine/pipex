/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:33:29 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/14 11:54:01 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countdigits(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * 1;
		count++;
	}
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*out;
	int			digits;
	long int	nn;

	nn = (int long)n;
	digits = ft_countdigits(n);
	out = (char *)ft_calloc(digits + 1, sizeof(char));
	if (!out)
		return (NULL);
	if (nn < 0)
		nn = nn * -1;
	while (digits--)
	{
		out[digits] = nn % 10 + '0';
		nn = nn / 10;
	}
	if (n < 0)
		out[0] = '-';
	return (out);
}
