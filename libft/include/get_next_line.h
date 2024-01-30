/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:31:18 by jeada-si          #+#    #+#             */
/*   Updated: 2024/01/09 08:08:00 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct t_buffer
{
	int				fd;
	char			content[BUFFER_SIZE + 1];
	int				pos;
	struct t_buffer	*next;
}	t_buffer;

int			cat_buffer(char **line, char *buf, int *pos);
char		*get_next_line(int fd);

#endif
