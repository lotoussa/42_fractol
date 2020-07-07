/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotoussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:17:56 by lotoussa          #+#    #+#             */
/*   Updated: 2020/02/27 15:24:37 by lotoussa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

char	*ft_strndup(char *s1, int len)
{
	char	*s2;

	if (!(s2 = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	s2 = ft_strncpy(s2, s1, len);
	return (s2);
}
