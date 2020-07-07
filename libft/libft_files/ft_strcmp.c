/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotoussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:17:54 by lotoussa          #+#    #+#             */
/*   Updated: 2020/02/27 15:24:35 by lotoussa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;

	i = 0;
	while ((s1[i] == s2[i]) && s1[i])
		i++;
	return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
}
