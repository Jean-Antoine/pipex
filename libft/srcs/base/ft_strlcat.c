/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:36:43 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/15 14:05:57 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;

	src_len = ft_strlen(src);
	if (!dst && !size)
		return (src_len);
	dst_len = ft_strlen(dst);
	if (size < dst_len + 1)
		return (src_len + size);
	if (size > dst_len + src_len + 1)
		size = dst_len + src_len + 1;
	ft_memcpy(&dst[dst_len], src, size - dst_len - 1);
	dst[size - 1] = '\0';
	return (dst_len + src_len);
}
