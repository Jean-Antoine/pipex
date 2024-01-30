/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_here_doc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:47:19 by jeada-si          #+#    #+#             */
/*   Updated: 2024/01/30 17:25:04 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_build_temp_path(void)
{
	char	*temp;
	char	*path;

	path = ft_strdup(".here_doc");
	while (access(path, F_OK) == 0)
	{
		temp = ft_strjoin(path, "(1)");
		free(path);
		path = temp;
	}
	return (path);
}

static void	ft_read_stdin(int tmp_fd, int stdin_fd, char *limiter)
{
	char	*line;

	while (1)
	{
		ft_putstr_fd("heredoc> ", 1);
		line = get_next_line(stdin_fd);
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
			&& ft_strlen(line) - 1 == ft_strlen(limiter))
		{
			free(line);
			close(stdin_fd);
			break ;
		}			
		else
			ft_putstr_fd(line, tmp_fd);
		free(line);
	}
}

char	*ft_get_here_doc(char *limiter)
{
	int		tmp_fd;
	int		stdin;
	char	*path;

	path = ft_build_temp_path();
	tmp_fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (tmp_fd < 0)
		ft_exit(path, NULL, EXIT_FAILURE);
	stdin = dup(STDIN_FILENO);
	if (stdin < 0)
	{
		free(path);
		ft_exit(ft_strdup("dup stdin"), NULL, EXIT_FAILURE);
	}
	ft_read_stdin(tmp_fd, stdin, limiter);
	close(tmp_fd);
	return (path);
}
