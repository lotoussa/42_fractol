/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotoussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:09:59 by lotoussa          #+#    #+#             */
/*   Updated: 2020/03/09 12:15:20 by lotoussa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

int			color(int iter, t_obj *prog)
{
	return (prog->p_color[iter % 25]);
}

static int	rgb(int r, int g, int b)
{
	return (r * 65536 + g * 256 + b);
}

void		init_color(t_obj *prog)
{
	double	t;
	int		r;
	int		g;
	int		b;
	int		i;

	i = 0;
	while (i < 25)
	{
		t = (double)1 / (i + 1);
		r = 255 * \
			(0.5f + 0.5f * cos(2 * M_PI * (t + (double)prog->color / 25)));
		g = 255 * (0.5f + 0.5f * sin(2 * M_PI * (t + prog->color * 0.33 / 25)));
		b = 255 * (0.5f + 0.5f * sin(2 * M_PI * (t + prog->color * 0.67 / 25)));
		prog->p_color[i] = rgb(r, g, b);
		i++;
	}
}
