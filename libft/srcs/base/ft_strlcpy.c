/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:56:21 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/09 15:35:10 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_length;

	src_length = ft_strlen(src);
	if (!size)
		return (src_length);
	if (src_length + 1 <= size)
		size = src_length + 1;
	ft_memcpy(dst, src, size - 1);
	dst[(int)size - 1] = '\0';
	return (src_length);
}
