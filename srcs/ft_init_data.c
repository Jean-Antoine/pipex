/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:05:08 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/02 13:59:08 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_malloc_data(t_data *data)
{
	data->pid = (pid_t *) malloc(sizeof(pid_t) * data->n_cmd);
	data->path = ft_split(ft_get_env_var(data->envp, "PATH"), ':');
	if (!data->pid || !data->path)
		ft_exit("malloc", data, EXIT_FAILURE);
}

static void	ft_init_pipe(t_data *data)
{
	int	i;
	int	fd[2];

	data->fd = (int *) malloc(sizeof(int) * (data->n_cmd + 1) * 2);
	if (!data->fd)
		ft_exit("malloc", data, EXIT_FAILURE);
	i = -1;
	while (++i < (data->n_cmd + 1) * 2)
		data->fd[i] = -1;
	i = -1;
	while (++i < data->n_cmd - 1)
	{
		if (pipe(fd) == -1)
			ft_exit("pipe", data, EXIT_FAILURE);
		data->fd[i * 2 + 1] = fd[1];
		data->fd[i * 2 + 2] = fd[0];
	}
}

t_data	ft_init_data(int ac, char **av, char **envp)
{
	t_data	data;

	data.here_doc = 0;
	data.infile = av[1];
	data.outfile = av[ac - 1];
	data.limiter = av[2];
	data.envp = envp;
	data.cmd_path = NULL;
	data.cmd_args = NULL;
	data.here_doc = (ft_strncmp(av[1], "here_doc", 8) == 0
			&& ft_strlen(av[1]) == 8);
	if (data.here_doc && ac < 6)
		exit(EXIT_FAILURE);
	data.cmd = av + 2 + data.here_doc;
	data.n_cmd = ac - 3 - data.here_doc;
	ft_init_pipe(&data);
	ft_malloc_data(&data);
	return (data);
}
