/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
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
	char			*troncon;
	unsigned int	i;
	unsigned int	y;

	i = start;
	y = 0;
	if (s == NULL)
		return (NULL);
	if ((troncon = ft_strnew(len)) == NULL)
		return (NULL);
	while (i < (start + len))
	{
		troncon[y] = s[i];
		i++;
		y++;
	}
	troncon[y] = '\0';
	return (troncon);
}
