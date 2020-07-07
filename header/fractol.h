/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotoussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 21:14:33 by lotoussa          #+#    #+#             */
/*   Updated: 2020/03/09 15:21:08 by lotoussa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "libft.h"
# include "../minilibx_macos/mlx.h"
# define WIN_X 1000
# define WIN_Y 1000

typedef struct		s_calc
{
	double			c[2];
	double			z[2];
	double			sqrt[2];
	int				i;
}					t_calc;

typedef struct		s_draw
{
	void			*add;
	double			len[2];
	int				i[3];
	int				iter;
	int				x;
	int				y;
	char			*m_str;
}					t_draw;

typedef enum		e_fract
{
	mandelbrot,
	julia,
	burnings,
}					t_fract;

typedef struct		s_obj
{
	void			*mlx;
	void			*win;
	double			start_x;
	double			end_x;
	double			start_y;
	double			end_y;
	double			x;
	double			y;
	int				color;
	int				iter;
	t_fract			choice;
	char			*name;
	int				p_color[25];
}					t_obj;

int					color(int iter, t_obj *prog);
void				init_color(t_obj *prog);
void				add_legend(t_obj *prog);
int					add_choice(t_obj *prog);
void				*draw_choice(t_obj *prog, t_draw *tool);
int					julia_mouse(int x, int y, void *param);
int					mouse(int button, int x, int y, void *param);
int					key(int keycode, void *param);

#endif
