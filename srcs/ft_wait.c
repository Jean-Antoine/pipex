/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:43:49 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/05 13:03:03 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_wait(t_data *data)
{	
	int		status;
	char	*line;

	data->i_cmd = -1;
	while (++data->i_cmd < data->n_cmd)
	{
		waitpid(data->pid[data->i_cmd], &status, 0);
		while (1)
		{
			line = get_next_line(data->fd_read_err[data->i_cmd]);
			if (!line)
				break ;
			ft_putstr_fd(line, STDERR_FILENO);
			free(line);
		}
	}
	return (WEXITSTATUS(status));
}
