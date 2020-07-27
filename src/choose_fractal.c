/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfreddie <gfreddie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 19:23:30 by gfreddie          #+#    #+#             */
/*   Updated: 2020/07/23 19:23:31 by gfreddie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			choose_fractal(t_fractal *fractal)
{
	if (fractal->type == JULIA)
		draw_julia(fractal);
	else if (fractal->type == FROSTY)
		draw_frosty(fractal);
	else if (fractal->type == MANDELBROT)
		draw_mandelbrot(fractal);
	else if (fractal->type == RADIOLARIA)
		draw_radiolaria(fractal);
	else if (fractal->type == SPIDER)
		draw_spider(fractal);
	else if (fractal->type == BURNING_SHIP)
		draw_burning_ship(fractal);
	else if (fractal->type == NEWTON)
		draw_newton(fractal);
	else if (fractal->type == NOVA)
		draw_nova(fractal);
}
