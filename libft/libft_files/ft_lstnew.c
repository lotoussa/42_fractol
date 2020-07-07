/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotoussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:17:51 by lotoussa          #+#    #+#             */
/*   Updated: 2020/02/27 15:24:31 by lotoussa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		new->content = (NULL);
		new->content_size = 0;
	}
	else
	{
		new->content = ft_memalloc(content_size);
		ft_memmove(new->content, content, content_size);
		new->content_size = content_size;
	}
	new->next = (NULL);
	return (new);
}
