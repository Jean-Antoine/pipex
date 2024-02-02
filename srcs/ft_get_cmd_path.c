/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cmd_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:55:57 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/02 14:34:01 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_exit_not_found(char *prefix, t_data *data)
{
	ft_putstr_fd(prefix, 2);
	ft_putstr_fd(": command not found\n", 2);
	if (data)
		ft_free_data(data);
	exit(127);
}

static int	ft_is_cmd_path(t_data *data)
{
	int		len;
	char	*cmd;

	cmd = data->cmd_args[0];
	len = ft_strlen(cmd);
	if (len == 1 && (*cmd == '.' || *cmd == '/'))
		return (0);
	if (ft_strncmp(cmd, "./", 2) != 0
		&& ft_strncmp(cmd, "../", 3) != 0
		&& ft_strncmp(cmd, "/", 1) != 0)
		return (0);
	if (access(data->cmd_args[0], F_OK) == 0)
	{
		data->cmd_path = ft_strdup(data->cmd_args[0]);
		return (1);
	}	
	ft_exit(data->cmd_args[0], data, 127);
	return (0);
}

static void	ft_find_cmd(t_data *data)
{
	int	i;

	if (!data->envp[0]
		|| !data->path[0])
		ft_exit_not_found(data->cmd_args[0], data);
	i = -1;
	while (data->path[++i])
	{
		data->cmd_path = ft_path(data->path[i], data->cmd_args[0]);
		if (access(data->cmd_path, F_OK) == 0)
			break ;
		free(data->cmd_path);
		data->cmd_path = NULL;
	}
	if (!data->cmd_path)
		ft_exit_not_found(data->cmd_args[0], data);
}

void	ft_get_cmd_path(t_data *data)
{
	if (ft_strlen(data->cmd_args[0]) == 0)
		ft_exit_not_found("\'\'", data);
	if (!ft_is_cmd_path(data))
		ft_find_cmd(data);
	if (access(data->cmd_path, X_OK) == 0)
		return ;
	perror(data->cmd_args[0]);
	ft_free_data(data);
	exit(126);
}
