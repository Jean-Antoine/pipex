/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:04:31 by jeada-si          #+#    #+#             */
/*   Updated: 2024/01/24 16:09:01 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_get_env_var(char **envp, char *name)
{
	int	len;

	len = ft_strlen(name);
	while (*envp)
	{
		if (!ft_strncmp(*envp, name, len))
			return (*envp + len + 1);
		envp++;
	}
	return (NULL);
}
