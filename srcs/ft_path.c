/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:11:16 by jeada-si          #+#    #+#             */
/*   Updated: 2024/01/24 16:15:41 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_path(char *path, char *filename)
{
	char	*path_;
	char	*out;

	if (path[ft_strlen(path) - 1] != '/')
		path_ = ft_strjoin(path, "/");
	else
		return (ft_strjoin(path, filename));
	out = ft_strjoin(path_, filename);
	free(path_);
	return (out);
}
