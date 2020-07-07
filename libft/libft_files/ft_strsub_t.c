/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_t.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotoussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:17:58 by lotoussa          #+#    #+#             */
/*   Updated: 2020/02/27 15:24:39 by lotoussa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;
	char	*cur;

	if (s)
	{
		if (!(sub = (char *)malloc((len + 1) * sizeof(char))))
			return (NULL);
		cur = (char *)s + start;
		i = 0;
		while (cur[i] && (i < len))
		{
			sub[i] = cur[i];
			i++;
		}
		sub[i] = '\0';
		return (sub);
	}
	return (NULL);
}
