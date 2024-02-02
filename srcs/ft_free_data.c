/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:34:33 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/02 11:11:15 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_data(t_data *data)
{
	if (data->pid)
		free(data->pid);
	ft_close_fd(data);
	if (data->fd)
		free(data->fd);
	if (data->path)
		ft_free_tab((void **) data->path);
	if (data->cmd_args)
		ft_free_tab((void **) data->cmd_args);
	if (data->cmd_path)
		free(data->cmd_path);
}
