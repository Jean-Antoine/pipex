/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpadding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 08:41:46 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/29 11:38:50 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strpadding(char *str, char c, size_t size, int left_align)
{
	size_t	len;
	char	*padded;

	if (!str)
		return (str);
	len = ft_strlen(str);
	if (len > size)
		return (str);
	padded = (char *)ft_calloc(size + 1, sizeof(char));
	ft_memset(padded, c, size);
	if (left_align)
		ft_memcpy(padded, str, len);
	else
		ft_memcpy(&padded[size - len], str, len);
	free(str);
	return (padded);
}
