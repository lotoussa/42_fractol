/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotoussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:33:21 by lotoussa          #+#    #+#             */
/*   Updated: 2020/03/09 13:18:43 by lotoussa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

void			add_legend(t_obj *p)
{
	mlx_string_put(p->mlx, p->win, 20, WIN_Y * 3 / 4 + 20, \
			0x00FFFFFF, p->name);
	mlx_string_put(p->mlx, p->win, 20, WIN_Y * 3 / 4 + 60, \
			0x00FFFFFF, "Zoom   :             Molette");
	mlx_string_put(p->mlx, p->win, 20, WIN_Y * 3 / 4 + 100, \
			0x00FFFFFF, "Move   :             Keyboard Arrow");
	mlx_string_put(p->mlx, p->win, 20, WIN_Y * 3 / 4 + 140, \
			0x00FFFFFF, "+ or - :             Change number of iteration");
	mlx_string_put(p->mlx, p->win, 20, WIN_Y * 3 / 4 + 180, \
			0x00FFFFFF, "C or V :             Change color");
	mlx_string_put(p->mlx, p->win, 20, WIN_Y * 3 / 4 + 220, \
			0x00FFFFFF, "ESC    :             Quit the programm");
}
