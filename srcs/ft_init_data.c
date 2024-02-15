/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:05:08 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/05 14:52:22 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	*ft_malloc_fd(int size, t_data *data)
{
	int	*fd;

	fd = (int *) malloc(size * sizeof(int));
	if (!fd)
		ft_exit("malloc", data, EXIT_FAILURE);
	while (size--)
		fd[size] = -1;
	return (fd);
}

static void	ft_malloc_data(t_data *data)
{	
	data->fd_read = ft_malloc_fd(data->n_cmd, data);
	data->fd_write = ft_malloc_fd(data->n_cmd, data);
	data->fd_read_err = ft_malloc_fd(data->n_cmd, data);
	data->fd_write_err = ft_malloc_fd(data->n_cmd, data);
	data->pid = (pid_t *) malloc(sizeof(pid_t) * data->n_cmd);
	if (!data->pid)
		ft_exit("malloc", data, EXIT_FAILURE);
	data->path = ft_split(ft_get_env_var(data->envp, "PATH"), ':');
	if (!data->path)
		ft_exit("malloc", data, EXIT_FAILURE);
}

static void	ft_init_pipe(t_data *data, int *fd_read, int *fd_write, int lag)
{
	int	i;
	int	fd[2];

	i = -1;
	while (++i < data->n_cmd - lag)
	{
		if (pipe(fd) == -1)
			ft_exit("pipe", data, EXIT_FAILURE);
		fd_write[i] = fd[1];
		fd_read[i + lag] = fd[0];
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
	data.cmd = NULL;
	data.cmd_path = NULL;
	data.cmd_args = NULL;
	data.path = NULL;
	data.here_doc = (ft_strncmp(av[1], "here_doc", 8) == 0
			&& ft_strlen(av[1]) == 8);
	if (data.here_doc && ac < 6)
		exit(EXIT_FAILURE);
	data.cmd = av + 2 + data.here_doc;
	data.n_cmd = ac - 3 - data.here_doc;
	ft_malloc_data(&data);
	ft_init_pipe(&data, data.fd_read, data.fd_write, 1);
	ft_init_pipe(&data, data.fd_read_err, data.fd_write_err, 0);
	return (data);
}
