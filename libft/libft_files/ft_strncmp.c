/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotoussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:17:56 by lotoussa          #+#    #+#             */
/*   Updated: 2020/02/27 15:24:37 by lotoussa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] == s2[i]) && s1[i] && (i < n))
		i++;
	if (i == n)
		return ((int)((unsigned char)s1[i - 1] - (unsigned char)s2[i - 1]));
	return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
}
