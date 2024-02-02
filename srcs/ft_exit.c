/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:58:34 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/02 11:19:29 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exit(char *prefix, t_data *data, int exit_code)
{
	perror(prefix);
	if (data)
		ft_free_data(data);
	exit(exit_code);
}
