/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotoussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:58:23 by lotoussa          #+#    #+#             */
/*   Updated: 2020/03/09 13:27:28 by lotoussa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

static void		move(int keycode, t_obj *prog, double size_x, double size_y)
{
	if (keycode == 123)
	{
		prog->start_x += size_x * 0.1;
		prog->end_x += size_x * 0.1;
	}
	else if (keycode == 124)
	{
		prog->start_x -= size_x * 0.1;
		prog->end_x -= size_x * 0.1;
	}
	else if (keycode == 125)
	{
		prog->start_y -= size_y * 0.1;
		prog->end_y -= size_y * 0.1;
	}
	else
	{
		prog->start_y += size_y * 0.1;
		prog->end_y += size_y * 0.1;
	}
}

int				key(int keycode, void *param)
{
	t_obj		*prog;
	double		size_x;
	double		size_y;

	prog = param;
	size_x = prog->end_x - prog->start_x;
	size_y = prog->end_y - prog->start_y;
	if (keycode == 53)
	{
		ft_strdel(&prog->name);
		exit(2);
	}
	else if (keycode == 8 || keycode == 9)
	{
		prog->color = (keycode == 8) ? prog->color + 1 : prog->color - 1;
		init_color(prog);
	}
	else if (keycode == 69)
		prog->iter += 10;
	else if (keycode == 78 && prog->iter != 10)
		prog->iter -= 10;
	else if (123 <= keycode && keycode <= 126)
		move(keycode, prog, size_x, size_y);
	return (add_choice(prog));
}

static void		zoom(int button, int x, int y, t_obj *prog)
{
	double		percent_x;
	double		percent_y;
	double		size_x;
	double		size_y;

	percent_x = (double)x / ((WIN_X ? WIN_X : 1) * 3 / 4);
	percent_y = (double)y / ((WIN_Y ? WIN_Y : 1) * 3 / 4);
	size_x = prog->end_x - prog->start_x;
	size_y = prog->end_y - prog->start_y;
	if (button == 5)
	{
		prog->start_x += size_x * 0.2 * percent_x;
		prog->end_x -= size_x * 0.2 * (1 - percent_x);
		prog->start_y += size_y * 0.2 * percent_y;
		prog->end_y -= size_y * 0.2 * (1 - percent_y);
	}
	if (button == 4)
	{
		prog->start_x -= size_x * 0.2 * percent_x;
		prog->end_x += size_x * 0.2 * (1 - percent_x);
		prog->start_y -= size_y * 0.2 * percent_y;
		prog->end_y += size_y * 0.2 * (1 - percent_y);
	}
}

int				mouse(int button, int x, int y, void *param)
{
	t_obj		*prog;

	prog = param;
	if (button == 4 || button == 5)
		zoom(button, x, y, prog);
	return (add_choice(prog));
}

int				julia_mouse(int x, int y, void *param)
{
	t_obj		*prog;

	prog = param;
	if (prog->choice == julia && x < WIN_X && y < 3 * WIN_Y / 4)
	{
		prog->x = (double)x / (3 * WIN_X / 4) * (prog->end_x - prog->start_x)
			+ prog->start_x;
		prog->y = (double)y / (3 * WIN_Y / 4) * (prog->end_y - prog->start_y)
			+ prog->start_y;
		add_choice(prog);
	}
	return (0);
}
