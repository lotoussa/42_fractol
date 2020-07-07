/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotoussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:17:50 by lotoussa          #+#    #+#             */
/*   Updated: 2020/02/27 15:24:30 by lotoussa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

static int		ft_nbdigits(int nb)
{
	int		nb_digits;
	long	n;

	n = (long)nb;
	if (n < 0)
		n *= -1;
	nb_digits = 0;
	while (n /= 10)
		nb_digits++;
	return (nb_digits);
}

char			*ft_itoa(int n)
{
	char	*a_nb;
	int		neg;
	int		i;
	long	nb;

	nb = (long)n;
	neg = 0;
	if (nb == 0)
		return (ft_strdup("0"));
	if (nb < 0)
		nb *= (neg = -1);
	if (!(a_nb = malloc((ft_nbdigits(nb) + 1 + (neg * -1)) * sizeof(char))))
		return (NULL);
	i = 0;
	while (nb)
	{
		a_nb[i++] = '0' + (nb % 10);
		nb /= 10;
	}
	if (neg == -1)
		a_nb[i++] = '-';
	a_nb[i] = '\0';
	return (ft_strrev(a_nb));
}
