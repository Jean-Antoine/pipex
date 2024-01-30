/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:06:33 by jeada-si          #+#    #+#             */
/*   Updated: 2023/11/14 13:35:18 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nn;

	nn = (long int)n;
	if (nn < 0)
	{
		ft_putchar_fd('-', fd);
		nn = nn * -1;
	}
	if (nn < 10)
		ft_putchar_fd(nn + '0', fd);
	else
	{
		ft_putnbr_fd(nn / 10, fd);
		ft_putchar_fd(nn % 10 + '0', fd);
	}
}
