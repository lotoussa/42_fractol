/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotoussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:17:55 by lotoussa          #+#    #+#             */
/*   Updated: 2020/02/27 15:24:37 by lotoussa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*new;

	if (s)
	{
		if (!(new = (char *)malloc((ft_strlen(s) + 1) * sizeof(char))))
			return (NULL);
		i = 0;
		while (s[i])
		{
			new[i] = f((char)(s[i]));
			i++;
		}
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
