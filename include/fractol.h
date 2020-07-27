/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfreddie <gfreddie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 19:22:24 by gfreddie          #+#    #+#             */
/*   Updated: 2020/07/25 19:17:36 by gfreddie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "defines.h"
# include "complex.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>

typedef struct	s_color
{
	int		red;
	int		green;
	int		blue;
}				t_color;

typedef struct	s_coord
{
	double	x;
	double	y;
	int		c;
}				t_coord;

typedef	struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		width;
	int		height;
	char	*data;
	int		line_size;
	int		bits_per_pixel;
	int		endian;
}				t_mlx;

typedef struct	s_params
{
	t_complex	z;
	t_complex	t;
	t_complex	c;
	int			x;
	int			y;
	int			i;
}				t_params;

typedef struct	s_color_params
{
	double		f_red;
	double		f_green;
	double		f_blue;
	double		p_red;
	double		p_green;
	double		p_blue;
	int			width;
	int			center;
}				t_color_params;

typedef	struct	s_fractal
{
	t_mlx			image;
	int				type;
	int				max_iter;
	t_complex		min;
	t_complex		max;
	t_complex		k;
	t_complex		d;
	int				color;
	int				julia_motion;
	int				gpu;
	int				start_line;
	int				end_line;
	double			abs_z;
	double			zoom;
	t_coord			start_point_leaf;
	t_color_params	random;
}				t_fractal;

/*
** DRAW FUNCTIONS
*/
int				draw_fractal(t_fractal *fractal);
void			setups_for_fractal(t_fractal *fractal);
void			cl_setup(t_fractal *fractal);
void			draw_fractal_cpu(t_fractal *fractal);
void			draw_fractal_gpu(t_fractal *fractal);
void			clear_image(t_fractal *fractal);
void			set_init_params(t_fractal *fractal);
int				reset_fractal(t_fractal *fractal);
void			put_menu_to_window(t_fractal *fractal);
void			put_params(t_fractal *fractal, int x, int y);
int				draw_pixel(int x, int y, t_color color, t_fractal *fract);
t_color			choose_color_scheme(int i, t_fractal *fractal, t_complex z);
t_color			convert_color_int_to_rgb(unsigned color);
t_color			smooth_color(t_color_params c, int i, double abs_z, double p);
/*
** FRACTALS
*/
void			choose_fractal(t_fractal *fractal);
void			draw_mandelbrot(t_fractal *fractal);
void			draw_julia(t_fractal *fractal);
void			draw_frosty(t_fractal *fractal);
void			draw_radiolaria(t_fractal *fractal);
void			draw_spider(t_fractal *fractal);
void			draw_burning_ship(t_fractal *fractal);
void			draw_newton(t_fractal *fractal);
void			draw_fern_leaf(t_fractal *fractal);
void			draw_nova(t_fractal *fractal);
void			draw_piter(t_fractal *fractal);
void			draw_klifford(t_fractal *fractal);

/*
** COLOR SCHEMES
*/
t_color			rainbow_scheme(int i, int i_max, double abs_z);
t_color			black_and_white_scheme(int i, int i_max, double abs_z);
t_color			from_yellow_to_inf_scheme(int i, int i_max, double abs_z);
t_color			gray_scale(int iteration, int max_iteration);
t_color			dark_blue(int iteration, int max_iteration);
t_color			dark_red(int iteration, int max_iteration);
t_color			sea_color(int i, int i_max);
t_color			blue_scheme(int i, int i_max, double abs_z);
t_color			random_scheme(int i, int i_max, double abs_z, t_color_params p);
void			init_random_color(t_fractal *fractal);
void			switch_color_scheme(t_fractal *fractal);
/*
** HOOKS
*/
int				key_press(int key, void *param);
int				close_hook(void *param);
int				scale_window(int key, t_fractal *fractal);
int				zoom_wheel(int button, int x, int y, t_fractal *fractal);
int				move_hook(int key, t_fractal *fractal);
int				change_color_scheme(int key, t_fractal *fractal);
int				change_max_iteration(int key, t_fractal *fractal);
int				left_mouse_press(int button, int x, int y, t_fractal *fractal);
int				julia_motion(int x, int y, t_fractal *fractal);
int				draw_next_fractal(int key, t_fractal *fractal);

/*
** ERROR HANDLING
*/
int				ft_error(int key);
int				terminate_all(int error, t_fractal *fractal);

#endif
