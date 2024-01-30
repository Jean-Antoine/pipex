/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrtostr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:46:08 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/29 08:20:51 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ptrtostr(void *ptr)
{
	char	*out;

	if (!ptr)
		return (ft_strdup("(nil)"));
	out = ft_uitostr((unsigned long long)ptr, "0123456789abcdef");
	out = ft_strppd_c(out, 'x');
	out = ft_strppd_c(out, '0');
	return (out);
}
