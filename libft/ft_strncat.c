/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfreddie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 17:35:17 by gfreddie          #+#    #+#             */
/*   Updated: 2019/09/12 10:27:18 by gfreddie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (dest[j] != '\0')
		j++;
	while (src[i] != '\0' && n--)
		dest[j++] = src[i++];
	dest[j] = '\0';
	return (dest);
}
