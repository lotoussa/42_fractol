/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotoussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:17:58 by lotoussa          #+#    #+#             */
/*   Updated: 2020/02/27 15:24:39 by lotoussa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

char	*ft_strtolower(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (ft_isupper(s[i]))
			s[i] = ft_tolower(s[i]);
		i++;
	}
	return (s);
}
