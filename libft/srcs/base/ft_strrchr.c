/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:47:04 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/16 10:27:08 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ss;

	ss = (char *)s;
	ss = ss + ft_strlen(s);
	if (!(char)c)
		return (ss);
	while (ss-- != s)
		if (*ss == (char)c)
			return (ss);
	return (0);
}
