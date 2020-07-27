/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cpu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfreddie <gfreddie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 19:24:59 by gfreddie          #+#    #+#             */
/*   Updated: 2020/07/23 19:25:00 by gfreddie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <pthread.h>

static void	thread_error(void)
{
	ft_error(ERR_TREADS);
	exit(1);
}

void		draw_fractal_cpu(t_fractal *fractal)
{
	pthread_t	threads[THREADS];
	t_fractal	fractals[THREADS];
	int			i;

	i = 0;
	while (i < THREADS)
	{
		fractals[i] = *fractal;
		fractals[i].start_line = i * (HEIGHT / THREADS);
		fractals[i].end_line = (i + 1) * (HEIGHT / THREADS);
		if (pthread_create(&threads[i], NULL,
			(void *(*)(void *))choose_fractal, (void *)&fractals[i]))
			thread_error();
		i++;
	}
	while (i-- > 0)
		if (pthread_join(threads[i], NULL))
			thread_error();
}
