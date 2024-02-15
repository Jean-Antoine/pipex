/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:34:33 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/05 12:51:44 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_close_free_fd(int *fd, t_data *data)
{
	if (!fd)
		return ;
	ft_close(fd, data->n_cmd);
	free(fd);
}

void	ft_free_data(t_data *data)
{	
	ft_close_free_fd(data->fd_read, data);
	ft_close_free_fd(data->fd_write, data);
	ft_close_free_fd(data->fd_read_err, data);
	ft_close_free_fd(data->fd_write_err, data);
	if (data->pid)
		free(data->pid);
	if (data->path)
		ft_free_tab((void **) data->path);
	if (data->cmd_args)
		ft_free_tab((void **) data->cmd_args);
	if (data->cmd_path)
		free(data->cmd_path);
}
