/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:29:17 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/16 09:31:12 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*little_p;
	char	*big_p;
	size_t	little_len;	

	if (!*little)
		return ((char *)big);
	if ((!len && *little) || !*big)
		return (0);
	little_len = ft_strlen(little);
	while (len >= little_len)
	{
		little_p = (char *)little;
		big_p = (char *)big;
		while (*little_p)
		{
			if (*little_p++ != *big_p++)
				break ;
			else
				if (!*little_p)
					return ((char *)big);
		}
		big++;
		len--;
	}
	return (0);
}
