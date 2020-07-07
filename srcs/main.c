/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotoussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 22:13:34 by lotoussa          #+#    #+#             */
/*   Updated: 2020/03/09 14:02:29 by lotoussa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

static int		usage(void)
{
	ft_putendl("Usage: ./fractol [name]");
	ft_putendl("Mandelbrot\nJulia\nBurningShip");
	return (0);
}

static void		init_choice(t_obj *prog)
{
	prog->iter = 50;
	if (prog->choice == mandelbrot)
	{
		prog->start_x = -2.1;
		prog->end_x = 0.6;
		prog->start_y = -1.2;
		prog->end_y = 1.2;
	}
	else if (prog->choice == julia)
	{
		prog->start_x = -2.5;
		prog->end_x = 2.5;
		prog->start_y = -2.5;
		prog->end_y = 2.5;
		prog->x = -0.812921;
		prog->y = 0.118393;
	}
	else if (prog->choice == burnings)
	{
		prog->start_x = -1.778311;
		prog->end_x = 0.973572;
		prog->start_y = -1.785372;
		prog->end_y = 0.660745;
	}
}

int				add_choice(t_obj *prog)
{
	t_draw		tool;

	tool.add = draw_choice(prog, &tool);
	mlx_put_image_to_window(prog->mlx, prog->win, tool.add, 0, 0);
	mlx_destroy_image(prog->mlx, tool.add);
	return (1);
}

static int		init_prog(t_obj *prog, char *name)
{
	if (!ft_strcmp(name, "mandelbrot"))
		prog->choice = mandelbrot;
	else if (!ft_strcmp(name, "julia"))
		prog->choice = julia;
	else if (!ft_strcmp(name, "burningship"))
		prog->choice = burnings;
	else
		return (usage());
	if (!(prog->name = ft_strjoin("Fract'ol - ", name)))
		return (0);
	prog->mlx = mlx_init();
	prog->win = mlx_new_window(prog->mlx, WIN_X, WIN_Y, prog->name);
	prog->color = -77;
	init_color(prog);
	init_choice(prog);
	return (1);
}

int				main(int argc, char **argv)
{
	t_obj	prog;

	if (argc != 2)
		return (usage());
	if (!(init_prog(&prog, ft_strtolower(argv[1]))))
		return (0);
	add_legend(&prog);
	add_choice(&prog);
	mlx_key_hook(prog.win, key, &prog);
	mlx_mouse_hook(prog.win, mouse, &prog);
	mlx_hook(prog.win, 6, (1L << 6), julia_mouse, &prog);
	mlx_loop(prog.mlx);
	ft_strdel(&prog.name);
	return (0);
}
