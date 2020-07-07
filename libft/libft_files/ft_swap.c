/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotoussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:17:58 by lotoussa          #+#    #+#             */
/*   Updated: 2020/02/27 15:24:40 by lotoussa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

void	ft_swap(char *a, char *b)
{
	char	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}
