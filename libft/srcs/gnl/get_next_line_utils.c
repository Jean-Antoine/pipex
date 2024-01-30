/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:19:01 by jeada-si          #+#    #+#             */
/*   Updated: 2024/01/09 08:10:02 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strlen_(const char *s)
{
	int	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	cat_buffer(char **line, char *buf, int *pos)
{
	char	*new_line;
	int		endl;
	int		line_len;
	int		i;

	if (!buf[*pos])
		return (0);
	i = 0;
	line_len = ft_strlen_(*line);
	while (buf[*pos + i] && buf[*pos + i] != '\n')
		i++;
	endl = buf[*pos + i] == '\n';
	new_line = malloc(line_len + i + endl + 1);
	if (!new_line)
		return (0);
	ft_memcpy(new_line, *line, line_len);
	ft_memcpy(new_line + line_len, &buf[*pos], i + endl);
	new_line[line_len + i + endl] = 0;
	free(*line);
	*line = new_line;
	if (endl)
		*pos += i + 1;
	else
		*pos = 0;
	return (endl);
}
