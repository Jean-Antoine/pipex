/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:14:19 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/05 14:52:44 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_dup2(int fd1, int fd2, t_data *data)
{
	if (dup2(fd1, fd2) == -1)
		ft_exit("dup2", data, EXIT_FAILURE);
}

static void	ft_open_infile(t_data *data)
{
	if (data->i_cmd != 0)
		return ;
	if (data->here_doc)
		return ;
	data->fd_read[0] = open(data->infile, O_RDONLY);
	if (data->fd_read[0] == -1)
		ft_exit(data->infile, data, EXIT_FAILURE);
}

static void	ft_open_outfile(t_data *data)
{
	if (data->i_cmd != data->n_cmd - 1)
		return ;
	data->fd_write[data->i_cmd] = open(data->outfile,
			O_CREAT | O_WRONLY
			| O_TRUNC * !data->here_doc
			| O_APPEND * data->here_doc, 0644);
	if (data->fd_write[data->i_cmd] == -1)
		ft_exit(data->outfile, data, EXIT_FAILURE);
}

static void	ft_child(t_data *data)
{
	ft_open_infile(data);
	ft_open_outfile(data);
	ft_dup2(data->fd_read[data->i_cmd], STDIN_FILENO, data);
	ft_dup2(data->fd_write[data->i_cmd], STDOUT_FILENO, data);
	ft_dup2(data->fd_write_err[data->i_cmd], STDERR_FILENO, data);
	ft_close(data->fd_read, data->n_cmd);
	ft_close(data->fd_write, data->n_cmd);
	ft_close(data->fd_read_err, data->n_cmd);
	ft_close(data->fd_write_err, data->n_cmd);
	ft_exec(data);
}

void	ft_pipex(t_data *data)
{
	if (data->here_doc)
		ft_get_here_doc(data);
	data->i_cmd = -1;
	while (++data->i_cmd < data->n_cmd)
	{
		data->pid[data->i_cmd] = fork();
		if (data->pid[data->i_cmd] == -1)
			ft_exit("fork", data, EXIT_FAILURE);
		if (data->pid[data->i_cmd] == 0)
			ft_child(data);
	}
	ft_close(data->fd_read, data->n_cmd);
	ft_close(data->fd_write, data->n_cmd);
	ft_close(data->fd_write_err, data->n_cmd);
}
