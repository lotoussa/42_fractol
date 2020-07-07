/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotoussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 10:16:07 by lotoussa          #+#    #+#             */
/*   Updated: 2020/03/09 13:49:52 by lotoussa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

static int		calc_spec(int iter, t_calc *cal, t_obj *prog)
{
	while (cal->i <= iter && cal->sqrt[0] + cal->sqrt[1] < 4)
	{
		if (prog->choice == mandelbrot)
			cal->z[1] = cal->z[0] * cal->z[1];
		else if (prog->choice == julia)
			cal->z[1] = cal->z[1] * cal->z[0];
		else if (prog->choice == burnings)
			cal->z[1] = fabs(cal->z[0]) * fabs(cal->z[1]);
		cal->z[1] += cal->z[1] + cal->c[1];
		cal->z[0] = cal->sqrt[0] - cal->sqrt[1] + cal->c[0];
		cal->sqrt[0] = cal->z[0] * cal->z[0];
		cal->sqrt[1] = cal->z[1] * cal->z[1];
		cal->i++;
	}
	return (cal->i);
}

static int		calc_choice(double x, double y, int iter, t_obj *prog)
{
	t_calc		cal;

	cal.i = 0;
	if (prog->choice == julia)
	{
		cal.c[0] = prog->x;
		cal.c[1] = prog->y;
		cal.z[0] = x;
		cal.z[1] = y;
		cal.sqrt[0] = cal.z[0] * cal.z[0];
		cal.sqrt[1] = cal.z[1] * cal.z[1];
	}
	else
	{
		cal.c[0] = x;
		cal.c[1] = y;
		cal.z[0] = 0;
		cal.z[1] = 0;
		cal.sqrt[0] = 0;
		cal.sqrt[1] = 0;
	}
	return (calc_spec(iter, &cal, prog));
}

static void		pixel_to_mlx(char *image, int x, int y, int color)
{
	int			start;

	if ((0 <= y && y < WIN_Y * 3 / 4) && (0 <= x && x < WIN_X))
	{
		start = 4 * (x + WIN_X * y);
		image[start] = (color & 0xFF);
		image[start + 1] = (color & 0xFF00) >> 8;
		image[start + 2] = (color & 0xFF0000) >> 16;
	}
}

void			*draw_choice(t_obj *prog, t_draw *tool)
{
	tool->x = WIN_X;
	tool->y = WIN_Y * 3 / 4;
	tool->add = mlx_new_image(prog->mlx, tool->x, tool->y);
	tool->m_str = mlx_get_data_addr(tool->add, \
			tool->i, tool->i + 1, tool->i + 2);
	tool->i[0] = 0;
	tool->len[0] = (prog->end_y - prog->start_y) / (tool->y - 1);
	tool->len[1] = (prog->end_x - prog->start_x) / (tool->x - 1);
	while (tool->i[0] < tool->y)
	{
		tool->i[1] = 0;
		while (tool->i[1] < tool->x)
		{
			tool->iter = calc_choice(\
					tool->i[1] * tool->len[1] + prog->start_x, \
					tool->i[0] * tool->len[0] + prog->start_y, \
					prog->iter, prog);
			if (tool->iter != prog->iter + 1)
				pixel_to_mlx(tool->m_str, tool->i[1], tool->i[0], \
						color(tool->iter, prog));
			tool->i[1]++;
		}
		tool->i[0]++;
	}
	return (tool->add);
}
