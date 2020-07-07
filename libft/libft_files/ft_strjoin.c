/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotoussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:17:55 by lotoussa          #+#    #+#             */
/*   Updated: 2020/02/27 15:24:36 by lotoussa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*new;

	if (s1 && s2)
	{
		len = (ft_strlen(s1) + ft_strlen(s2));
		if (!(new = ft_memalloc(len + 1)))
			return (NULL);
		ft_strcat(new, s1);
		ft_strcat(new, s2);
		return (new);
	}
	return (NULL);
}
