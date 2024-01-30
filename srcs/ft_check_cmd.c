/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:55:57 by jeada-si          #+#    #+#             */
/*   Updated: 2024/01/30 15:10:46 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_check_cmd(t_data *data)
{
	int	i;

	i = -1;
	if (ft_strlen(data->cmd_split[0]) == 0 || !data->envp[0] || !data->path[0])
		ft_exit(data->cmd_split[0], "command not found\n", data);
	if ((!ft_strncmp(data->cmd_split[0], "./", 2)
			|| !ft_strncmp(data->cmd_split[0], "/", 1))
		&& access(data->cmd_split[0], F_OK) == 0)
	{
		data->cmd_path = ft_strdup(data->cmd_split[0]);
		return ;
	}	
	while (data->path[++i])
	{
		data->cmd_path = ft_path(data->path[i], data->cmd_split[0]);
		if (access(data->cmd_path, F_OK) == 0)
			break ;
		free(data->cmd_path);
		data->cmd_path = NULL;
	}
	if (!data->cmd_path)
		ft_exit(data->cmd_split[0], "command not found\n", data);
	return ;
}
