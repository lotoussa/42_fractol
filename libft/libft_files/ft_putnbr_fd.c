/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotoussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:17:53 by lotoussa          #+#    #+#             */
/*   Updated: 2020/02/27 15:24:34 by lotoussa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	m;

	m = n;
	if (m < 0)
	{
		ft_putchar_fd('-', fd);
		m *= -1;
	}
	if (m > 9)
		ft_putnbr_fd((int)(m / 10), fd);
	ft_putchar_fd((m % 10) + '0', fd);
}
