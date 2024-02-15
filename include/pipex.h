/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:04:23 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/15 14:36:59 by jeada-si         ###   ########.fr       */
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

typedef struct s_data
{
	char	*infile;
	char	*outfile;
	int		here_doc;
	char	*limiter;
	int		n_cmd;
	int		i_cmd; 
	pid_t	*pid;
	int		*fd_read;
	int		*fd_write;
	int		*fd_read_err;
	int		*fd_write_err;
	char	**path;
	char	**envp;
	char	**cmd;
	char	**cmd_args;
	char	*cmd_path;
}	t_data;

t_data	ft_init_data(int ac, char **av, char **envp);
void	ft_free_data(t_data *data);
char	*ft_get_env_var(char **envp, char *name);
char	*ft_path(char *path, char *filename);
void	ft_exit(char *prefix, t_data *data, int exit_code);
char	**ft_parse_cmd(char *cmd);
void	ft_get_cmd_path(t_data *data);
void	ft_exec(t_data *data);
void	ft_get_here_doc(t_data *data);
void	ft_pipex(t_data *data);
int		ft_wait(t_data *data);
void	ft_close(int *fd, int size);
#endif
