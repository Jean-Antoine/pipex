/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 08:10:54 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/16 10:42:49 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strwordcount(char const *s, char c)
{
	size_t	count;

	if (!s)
		return (0);
	if (!c)
		return (1);
	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			s = ft_strchr(s, c);
		}
		if (!s)
			break ;
		s++;
	}
	return (count);
}

static char	**ft_freetab(char **out)
{
	size_t	i;

	i = 0;
	while (out[i])
		free(out[i++]);
	free(out);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**out;
	size_t	i;

	out = (char **)ft_calloc(ft_strwordcount(s, c) + 1, sizeof(char *));
	if (!out)
		return (NULL);
	i = 0;
	while (s && *s)
	{
		if (*s != c)
		{
			out[i] = ft_substr(s, 0, ft_strchr(s, c) - s);
			if (!out[i])
				return (ft_freetab(out));
			i++;
			s = ft_strchr(s, c);
		}
		else
			s++;
	}
	return (out);
}
