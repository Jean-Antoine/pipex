/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:17:52 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/02 09:23:07 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_close(int *fd)
{
	if (*fd != -1)
		close(*fd);
	*fd = -1;
}

void	ft_close_fd(t_data	*data)
{
	int	j;

	if (!data->fd)
		return ;
	j = -1;
	while (++j < (data->n_cmd + 1) * 2)
		ft_close(&(data->fd[j]));
}
