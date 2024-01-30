/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:32:24 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/16 10:26:59 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ss;

	ss = (char *)s;
	ss--;
	while (*(++ss))
		if (*ss == (char)c)
			return (ss);
	if (!(char)c)
		return (ss);
	return (0);
}
