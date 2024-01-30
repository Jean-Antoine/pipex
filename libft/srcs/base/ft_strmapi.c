/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:31:38 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/15 14:14:55 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*out;
	size_t	i;

	if (!f || !s)
		return (NULL);
	i = 0;
	out = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!out)
		return (NULL);
	while (s[i])
	{
		out[i] = (*f)(i, s[i]);
		i++;
	}
	return (out);
}
