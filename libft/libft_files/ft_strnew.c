/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotoussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:17:56 by lotoussa          #+#    #+#             */
/*   Updated: 2020/02/27 15:24:38 by lotoussa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

char	*ft_strnew(size_t size)
{
	char *newstr;

	if ((newstr = (char *)malloc(size + 1)) == NULL)
		return (NULL);
	else
		ft_bzero(newstr, size + 1);
	return (newstr);
}
