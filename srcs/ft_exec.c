/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:08:42 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/02 13:30:50 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exec(t_data *data)
{
	data->cmd_args = ft_parse_cmd(data->cmd[data->i_cmd]);
	ft_get_cmd_path(data);
	if (execve(data->cmd_path, data->cmd_args, data->envp) == -1)
		ft_exit(data->cmd_args[0], data, EXIT_FAILURE);
}
