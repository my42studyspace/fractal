/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setups.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfreddie <gfreddie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 19:26:38 by gfreddie          #+#    #+#             */
/*   Updated: 2020/07/23 19:26:39 by gfreddie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	create_window_mlx(t_fractal *fractal)
{
	return (!(fractal->image.mlx_ptr = mlx_init()) ||
		!(fractal->image.win_ptr = mlx_new_window(fractal->image.mlx_ptr,
			fractal->image.width + 375, fractal->image.height, "Fract'ol")) ||
		!(fractal->image.img_ptr = mlx_new_image(fractal->image.mlx_ptr,
			fractal->image.width, fractal->image.height)) ||
		!(fractal->image.data = mlx_get_data_addr(fractal->image.img_ptr,
			&fractal->image.bits_per_pixel, &fractal->image.line_size,
			&fractal->image.endian)));
}

static void	set_max_and_min(t_fractal *fractal)
{
	if (fractal->type == MANDELBROT || fractal->type == SPIDER)
	{
		fractal->min = new_complex(-2.0, -1.5);
		fractal->max = new_complex(1.5, 1.5);
	}
	else if (fractal->type == BURNING_SHIP)
	{
		fractal->min = new_complex(-2.1, -1.7);
		fractal->max = new_complex(1.5, 1.9);
	}
	else if (fractal->type == NOVA)
	{
		fractal->min = new_complex(-2.0, -1.5);
		fractal->max = new_complex(2.0, 2.5);
	}
	else
	{
		fractal->min = new_complex(-2.0, -2.0);
		fractal->max = new_complex(2.0, 2.0);
	}
}

void		set_init_params(t_fractal *fractal)
{
	set_max_and_min(fractal);
	fractal->d = new_complex(
		(fractal->max.re - fractal->min.re) / fractal->image.width,
		(fractal->max.im - fractal->min.im) / fractal->image.height);
	fractal->julia_motion = 1;
	fractal->k = new_complex(-0.5, 0.6);
	fractal->max_iter = MAX_ITER;
	fractal->color = RAINBOW_COLOR;
	init_random_color(fractal);
	fractal->zoom = 1;
}

void		setups_for_fractal(t_fractal *fractal)
{
	fractal->image.width = WIDTH;
	fractal->image.height = HEIGHT;
	fractal->image.bits_per_pixel = 32;
	fractal->image.endian = 0;
	fractal->image.line_size = fractal->image.width;
	fractal->gpu = 0;
	set_init_params(fractal);
	if (create_window_mlx(fractal))
		terminate_all(MLX_ERROR, fractal);
}
