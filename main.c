/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:07:49 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/02 16:40:44 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_data	data;
	int		exit_code;

	if (ac < 5)
		exit(EXIT_FAILURE);
	data = ft_init_data(ac, av, envp);
	ft_pipex(&data);
	exit_code = ft_wait(&data);
	ft_free_data(&data);
	return (exit_code);
}

// int	main(int ac, char **av)
// {
// 	(void) ac;

// 	printf("%d ?\n", access(av[1], X_OK | F_OK | W_OK | R_OK));
// 	perror(NULL);
// }

// int	main(int argc, char *argv[], char **envp)
// {
//     char *newargv[] = { NULL, "hello", "world", NULL };
                           
// 	if (argc != 2)
// 		return (1);
//     newargv[0] = argv[1];
//     execve(argv[1], newargv, envp);
//     perror("execve");   /* execve() ne retourne qu'en cas d'erreur */
//     exit(errno);
// }