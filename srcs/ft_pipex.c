/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:14:19 by jeada-si          #+#    #+#             */
/*   Updated: 2024/01/30 15:04:45 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_dup2(int *fd1, int fd2, t_data *data)
{
	if (dup2(*fd1, fd2) == -1)
		ft_exit("dup2", NULL, data);
	close(*fd1);
	*fd1 = -1;
}

static void	ft_first(t_data *data)
{
	data->in_fd = open(data->infile, O_RDONLY);
	if (data->in_fd == -1)
		ft_exit(data->infile, NULL, data);
	ft_dup2(&data->in_fd, STDIN_FILENO, data);
	ft_dup2(&data->pipe_fd[0][IN], STDOUT_FILENO, data);
	ft_close_fd(data);
	ft_exec(data);
}

static void	ft_between(t_data *data)
{	
	ft_dup2(&data->pipe_fd[data->i_cmd - 1][OUT], STDIN_FILENO, data);
	ft_dup2(&data->pipe_fd[data->i_cmd][IN], STDOUT_FILENO, data);
	ft_close_fd(data);
	ft_exec(data);
}

static void	ft_last(t_data *data)
{
	data->out_fd = open(data->outfile, O_CREAT | !data->here_doc * O_TRUNC
			| O_WRONLY | data->here_doc * O_APPEND, 0644);
	if (data->out_fd == -1)
		ft_exit(data->outfile, NULL, data);
	ft_dup2(&data->out_fd, STDOUT_FILENO, data);
	ft_dup2(&data->pipe_fd[data->i_cmd - 1][OUT], STDIN_FILENO, data);
	ft_close_fd(data);
	ft_exec(data);
}

void	ft_pipex(t_data *data)
{
	data->i_cmd = -1;
	while (++data->i_cmd < data->n_cmd)
	{
		if (data->cmd)
			free(data->cmd);
		data->cmd = ft_strtrim(data->av[2 + data->here_doc + data->i_cmd], " ");
		data->pid[data->i_cmd] = fork();
		if (data->pid[data->i_cmd] == -1)
			ft_exit("fork", NULL, data);
		if (data->pid[data->i_cmd] != 0)
			continue ;
		if (data->i_cmd == 0)
			ft_first(data);
		else if (data->i_cmd == data->n_cmd - 1)
			ft_last(data);
		else
			ft_between(data);
	}
	ft_close_fd(data);
}
