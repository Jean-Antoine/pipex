/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:08:42 by jeada-si          #+#    #+#             */
/*   Updated: 2024/01/30 15:05:30 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exec(t_data *data)
{
	data->cmd_split = ft_split(data->cmd, ' ');
	ft_check_cmd(data);
	if (execve(data->cmd_path, data->cmd_split, data->envp) == -1)
		ft_exit(NULL, NULL, data);
}
