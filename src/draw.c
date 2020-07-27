/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfreddie <gfreddie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 19:24:53 by gfreddie          #+#    #+#             */
/*   Updated: 2020/07/23 19:24:54 by gfreddie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			draw_fractal(t_fractal *fractal)
{
	draw_fractal_cpu(fractal);
	mlx_clear_window(fractal->image.mlx_ptr, fractal->image.win_ptr);
	mlx_put_image_to_window(fractal->image.mlx_ptr, fractal->image.win_ptr,
		fractal->image.img_ptr, 0, 0);
	put_menu_to_window(fractal);
	return (0);
}

int			reset_fractal(t_fractal *fractal)
{
	clear_image(fractal);
	set_init_params(fractal);
	draw_fractal(fractal);
	return (1);
}

void		put_params(t_fractal *fract, int x, int y)
{
	char	*i;
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = fract->image.mlx_ptr;
	win_ptr = fract->image.win_ptr;
	i = ft_itoa(fract->max_iter);
	mlx_string_put(mlx_ptr, win_ptr, x + 160, y + 550, YELLOW, i);
	ft_strdel(&i);
	if (fract->type == JULIA)
	{
		mlx_string_put(mlx_ptr, win_ptr, x, y + 610, CSEA, "Julia motion: ");
		if (fract->julia_motion)
			mlx_string_put(mlx_ptr, win_ptr, x + 160, y + 610, LIME, "On");
		else
			mlx_string_put(mlx_ptr, win_ptr, x + 160, y + 610, RED, "Off");
	}
}
