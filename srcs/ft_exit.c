/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:58:34 by jeada-si          #+#    #+#             */
/*   Updated: 2024/01/29 12:22:22 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exit(char *prefix, char *msg, t_data *data)
{
	(void) data;
	if (prefix)
	{
		ft_putstr_fd(prefix, 2);
		ft_putstr_fd(": ", 2);
	}	
	if (!msg)
		perror(NULL);
	else
		ft_putstr_fd(msg, 2);
	if (data)
		ft_free_data(data);
	exit(errno);
}
