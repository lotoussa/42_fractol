/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotoussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:17:51 by lotoussa          #+#    #+#             */
/*   Updated: 2020/02/27 15:24:32 by lotoussa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*new;

	if (!(new = malloc(size)))
		return (NULL);
	ft_bzero(new, size);
	return (new);
}
