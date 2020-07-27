/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfreddie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:30:14 by gfreddie          #+#    #+#             */
/*   Updated: 2019/09/15 16:44:34 by gfreddie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*string;

	string = (char *)ft_memalloc(size + 1);
	if (string)
	{
		string[size] = '\0';
		return (string);
	}
	return (NULL);
}
