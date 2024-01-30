/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:07:49 by jeada-si          #+#    #+#             */
/*   Updated: 2024/01/30 14:41:43 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_data	data;
	int		exit_code;

	data = ft_init_data(ac, av, envp);
	ft_pipex(&data);
	exit_code = ft_wait(&data);
	if (data.here_doc)
		unlink(data.infile);
	ft_free_data(&data);
	return (exit_code);
}
