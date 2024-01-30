/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itostr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:29:51 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/28 15:16:54 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_anydup(char *str)
{
	char	*str_s;

	while (*str)
	{
		str_s = str + 1;
		while (*str_s)
			if (*str_s++ == *str)
				return (1);
		str++;
	}
	return (0);
}

static int	ft_nbrlen(size_t n, int size)
{
	int	i;

	i = 0;
	if (!n)
		return (1);
	while (n)
	{
		n = n / size;
		i++;
	}
	return (i);
}

char	*ft_uitostr(size_t n, char *base)
{
	int		size;
	int		len;
	char	*out;

	if (!base || ft_anydup(base))
		return (NULL);
	size = ft_strlen(base);
	len = ft_nbrlen(n, size);
	out = (char *)ft_calloc(len + 1, sizeof(char));
	while (len)
	{
		out[--len] = base[n % size];
		n = n / size;
	}
	return (out);
}

char	*ft_itostr(long long int n, char *base)
{
	if (n < 0)
		return (ft_strppd_c(ft_uitostr(-n, base), '-'));
	else
		return (ft_uitostr(n, base));
}
