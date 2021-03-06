/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfreddie <gfreddie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 19:25:37 by gfreddie          #+#    #+#             */
/*   Updated: 2020/07/23 19:25:38 by gfreddie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_mandelbrot(t_fractal *fractal)
{
	t_params	p;

	p.y = fractal->start_line;
	while (p.y < fractal->end_line)
	{
		p.c.im = fractal->max.im - p.y * fractal->d.im;
		p.x = 0;
		while (p.x < fractal->image.width)
		{
			p.c.re = fractal->min.re + p.x * fractal->d.re;
			p.z = new_complex(p.c.re, p.c.im);
			p.i = -1;
			while (++p.i < fractal->max_iter && sqrt(complex_abs(p.z)) <= 4)
				p.z = complex_add(complex_mult(p.z, p.z), p.c);
			draw_pixel(p.x, p.y, choose_color_scheme(p.i,
										fractal, p.z), fractal);
			p.x++;
		}
		p.y++;
	}
}
