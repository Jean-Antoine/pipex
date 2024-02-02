/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 09:14:47 by jeada-si          #+#    #+#             */
/*   Updated: 2024/02/02 14:10:27 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_matching_quote(char *cmd)
{
	char	c;

	c = *cmd++;
	while (*cmd && *cmd != c)
		cmd++;
	return (cmd);
}

static char	*ft_pass_word(char *cmd)
{
	while (*cmd && *cmd != ' ')
	{
		if (*cmd == '\'' || *cmd == '\"')
			cmd = ft_matching_quote(cmd);
		if (*cmd)
			cmd++;
	}
	return (cmd);
}

static char	*ft_pass_spaces(char *cmd)
{
	while (*cmd && *cmd == ' ')
		cmd++;
	return (cmd);
}

int	ft_count_words(char *cmd)
{
	int	words;

	if (!cmd || !*cmd)
		return (0);
	words = 0;
	cmd = ft_pass_spaces(cmd);
	while (*cmd)
	{
		cmd = ft_pass_word(cmd);
		words++;
		cmd = ft_pass_spaces(cmd);
	}
	return (words);
}

char	**ft_parse_cmd(char *cmd)
{
	char	**out;
	int		i;
	int		words;
	int		q;

	words = ft_count_words(cmd);
	out = (char **) ft_calloc((words + 1), sizeof(char *));
	if (!out)
		return (NULL);
	i = -1;
	while (++i < words)
	{
		cmd = ft_pass_spaces(cmd);
		q = (*cmd == '\"' || *cmd == '\'');
		out[i] = ft_substr(cmd, q, ft_pass_word(cmd) - cmd - 2 * q);
		if (!out[i])
		{
			ft_free_tab((void **) out);
			return (NULL);
		}
		cmd = ft_pass_word(cmd);
	}
	out[i] = NULL;
	return (out);
}
