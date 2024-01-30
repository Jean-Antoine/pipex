/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:55:57 by jeada-si          #+#    #+#             */
/*   Updated: 2024/01/30 17:40:57 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_exit_(char *prefix, t_data *data)
{
	ft_putstr_fd(prefix, 2);
	ft_putstr_fd(": command not found\n", 2);
	if (data)
		ft_free_data(data);
	exit(127);
}

static void	ft_check_cmd_f(t_data *data)
{
	int	i;
	
	if ((ft_strncmp(data->cmd_split[0], "./", 2) == 0
			|| ft_strncmp(data->cmd_split[0], "/", 1) == 0))
	{
		if (access(data->cmd_split[0], F_OK) == 0)
		{
			data->cmd_path = ft_strdup(data->cmd_split[0]);
			return ;
		}
		ft_exit(data->cmd_split[0], data, 127);
	}
	if (ft_strlen(data->cmd_split[0]) == 0 || !data->envp[0] || !data->path[0])
		ft_exit_(data->cmd_split[0], data);
	i = -1;
	while (data->path[++i])
	{
		data->cmd_path = ft_path(data->path[i], data->cmd_split[0]);
		if (access(data->cmd_path, F_OK) == 0)
			break ;
		free(data->cmd_path);
		data->cmd_path = NULL;
	}
	if (!data->cmd_path)
		ft_exit_(data->cmd_split[0], data);
}

void	ft_check_cmd(t_data *data)
{
	ft_check_cmd_f(data);
	if (access(data->cmd_path, X_OK) == 0)
		return ;
	perror(data->cmd_split[0]);
	ft_free_data(data);
	exit(126);
}
