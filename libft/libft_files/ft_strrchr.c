/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotoussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:17:57 by lotoussa          #+#    #+#             */
/*   Updated: 2020/02/27 15:24:38 by lotoussa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	value;
	char	*start;
	char	*end;

	value = (char)c;
	start = (char *)s;
	end = (char *)s;
	while (*end)
		end++;
	if (c == '\0')
		return (end);
	end--;
	while (end >= start)
	{
		if (*end == c)
			return (end);
		end--;
	}
	return (NULL);
}
