/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfreddie <gfreddie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 19:23:53 by gfreddie          #+#    #+#             */
/*   Updated: 2020/07/23 19:23:54 by gfreddie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex.h"
#include <math.h>

t_complex	new_complex(double re, double im)
{
	t_complex new;

	new.re = re;
	new.im = im;
	return (new);
}

t_complex	complex_mult(t_complex a, t_complex b)
{
	t_complex res;

	res.re = a.re * b.re - b.im * b.im;
	res.im = a.re * b.im + b.im * a.re;
	return (res);
}

t_complex	complex_mult_num(t_complex a, double k)
{
	t_complex res;

	res.re = a.re * k;
	res.im = a.im * k;
	return (res);
}

double		complex_abs(t_complex c)
{
	double res;

	res = c.re * c.re + c.im * c.im;
	return (res);
}

double		complex_abs_min(t_complex a, t_complex b)
{
	t_complex tmp;

	tmp.re = a.re - b.re;
	tmp.im = a.im - b.im;
	return (complex_abs(tmp));
}
