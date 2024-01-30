/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:34:33 by jeada-si          #+#    #+#             */
/*   Updated: 2024/01/30 11:11:02 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_data(t_data *data)
{
	if (data->cmd)
		free(data->cmd);
	if (data->infile)
		free(data->infile);
	if (data->pid)
		free(data->pid);
	if (data->in_fd != -1)
		close(data->in_fd);
	if (data->out_fd != -1)
		close(data->out_fd);
	if (data->pipe_fd)
	{
		data->i_cmd = -1;
		ft_close_fd(data);
		ft_free_tab((void **) data->pipe_fd);
	}
	if (data->path)
		ft_free_tab((void **) data->path);
	if (data->cmd_split)
		ft_free_tab((void **) data->cmd_split);
	if (data->cmd_path)
		free(data->cmd_path);
}
