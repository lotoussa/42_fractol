/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotoussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:17:51 by lotoussa          #+#    #+#             */
/*   Updated: 2020/02/27 15:24:32 by lotoussa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n)
	{
		if (*(unsigned char *)s1 != *(unsigned char *)s2)
			return ((int)(*(unsigned char *)s1 - *(unsigned char *)s2));
		s1++;
		s2++;
		n--;
	}
	return (0);
}
