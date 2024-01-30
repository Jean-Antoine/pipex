/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:05:08 by jeada-si          #+#    #+#             */
/*   Updated: 2024/01/30 10:29:34 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_malloc_data(t_data *data)
{
	data->pid = (pid_t *) malloc(sizeof(pid_t) * data->n_cmd);
	data->pipe_fd = (int **) malloc(sizeof(int *) * data->n_cmd);
	data->path = ft_split(ft_get_env_var(data->envp, "PATH"), ':');
	if (!data->pid || !data->pipe_fd || !data->path)
		ft_exit("malloc", NULL, data);
	data->i_cmd = -1;
	while (++data->i_cmd < data->n_cmd - 1)
	{
		data->pipe_fd[data->i_cmd] = (int *) malloc(sizeof(int) * 2);
		if (!data->pipe_fd[data->i_cmd])
			ft_exit("malloc", NULL, data);
		data->pipe_fd[data->i_cmd][IN] = -1;
		data->pipe_fd[data->i_cmd][OUT] = -1;
	}
	data->pipe_fd[data->n_cmd - 1] = NULL;
	data->in_fd = -1;
	data->out_fd = -1;
	data->cmd_path = NULL;
	data->cmd_split = NULL;
}

t_data	ft_init_data(int ac, char **av, char **envp)
{
	t_data	data;

	if (ac < 5)
		exit(EXIT_FAILURE);
	data.here_doc = ft_strncmp(av[1], "here_doc", 8) == 0;
	data.here_doc &= ft_strlen(av[1]) == 8;
	if (data.here_doc && ac < 6)
		exit(EXIT_FAILURE);
	if (data.here_doc)
		data.infile = ft_get_here_doc(av[2]);
	else
		data.infile = ft_strdup(av[1]);
	if (!data.infile)
		ft_exit("malloc", NULL, NULL);
	data.outfile = av[ac - 1];
	data.n_cmd = ac - 3 - data.here_doc;
	data.envp = envp;
	data.av = av;
	data.cmd = NULL;
	ft_malloc_data(&data);
	data.i_cmd = -1;
	while (++data.i_cmd < data.n_cmd - 1)
		if (pipe(data.pipe_fd[data.i_cmd]) == -1)
			ft_exit("pipe", NULL, &data);
	return (data);
}
