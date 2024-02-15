/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_here_doc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:47:19 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/05 13:05:24 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_read_stdin(t_data *data, int pipe_hd[2])
{
	char	*line;

	while (1)
	{
		ft_putstr_fd("heredoc> ", 1);
		line = get_next_line(STDIN_FILENO);
		if (ft_strncmp(line, data->limiter, ft_strlen(data->limiter)) == 0
			&& ft_strlen(line) - 1 == ft_strlen(data->limiter))
		{
			free(line);
			break ;
		}			
		else
			ft_putstr_fd(line, pipe_hd[1]);
		free(line);
	}
	close(pipe_hd[1]);
}

void	ft_get_here_doc(t_data *data)
{
	int	pipe_hd[2];

	if (pipe(pipe_hd) == -1)
		ft_exit("heredoc", data, EXIT_FAILURE);
	ft_read_stdin(data, pipe_hd);
	data->fd_read[0] = pipe_hd[0];
}
