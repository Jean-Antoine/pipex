/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:04:23 by jeada-si          #+#    #+#             */
/*   Updated: 2024/01/30 10:17:26 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# define IN 1
# define OUT 0

typedef struct s_data
{
	char	*infile;
	char	*outfile;
	int		here_doc;
	int		n_cmd;
	int		i_cmd;
	pid_t	*pid;
	int		**pipe_fd;
	int		in_fd;
	int		out_fd;
	char	**path;
	char	**envp;
	char	**av;
	char	*cmd;
	char	**cmd_split;
	char	*cmd_path;
}	t_data;

t_data	ft_init_data(int ac, char **av, char **envp);
void	ft_free_data(t_data *data);
char	*ft_get_env_var(char **envp, char *name);
char	*ft_path(char *path, char *filename);
void	ft_exit(char *prefix, char *msg, t_data *data);
void	ft_check_cmd(t_data *data);
void	ft_exec(t_data *data);
char	*ft_get_here_doc(char *limiter);
void	ft_pipex(t_data *data);
int		ft_wait(t_data *data);
void	ft_close_fd(t_data	*data);
#endif
