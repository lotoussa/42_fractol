/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotoussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:17:57 by lotoussa          #+#    #+#             */
/*   Updated: 2020/02/27 15:24:38 by lotoussa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t len)
{
	char	*new;

	if (!(s1 && s2))
		return (NULL);
	if (!(new = ft_memalloc((len + ft_strlen(s2)) + 1)))
		return (NULL);
	ft_strncat(new, s1, len);
	ft_strcat(new, s2);
	return (new);
}
