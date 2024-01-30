/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:30:01 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/15 14:10:18 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*out;
	size_t	length;

	length = ft_strlen(s);
	out = (char *)ft_calloc(length + 1, sizeof(char));
	if (!out)
		return (NULL);
	ft_memcpy(out, s, length);
	return (out);
}
