/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:43:49 by jeada-si          #+#    #+#             */
/*   Updated: 2024/01/30 12:21:34 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_wait(t_data *data)
{	
	int	status;

	data->i_cmd = -1;
	while (++data->i_cmd < data->n_cmd)
	{
		waitpid(data->pid[data->i_cmd], &status, 0);
	}
	return (status);
}
