/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:17:52 by jeada-si          #+#    #+#             */
/*   Updated: 2024/01/30 11:55:28 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close_fd(t_data	*data)
{
	int	j;

	j = 0;
	while (j < data->n_cmd - 1 && data->pipe_fd[j])
	{
		if (data->pipe_fd[j][IN] != -1)
		{
			close(data->pipe_fd[j][IN]);
			data->pipe_fd[j][IN] = -1;
		}
		if (data->pipe_fd[j][OUT] != -1)
		{
			close(data->pipe_fd[j][OUT]);
			data->pipe_fd[j][OUT] = -1;
		}
		j++;
	}
}
