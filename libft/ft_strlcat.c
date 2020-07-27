/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfreddie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 16:02:29 by gfreddie          #+#    #+#             */
/*   Updated: 2019/09/15 16:42:49 by gfreddie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t dlen;
	size_t slen;

	i = 0;
	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	if (size < dlen)
		return (size + slen);
	while ((dlen + i + 1) < size && src[i] != '\0')
	{
		dest[dlen + i] = src[i];
		i++;
	}
	dest[dlen + i] = '\0';
	return (dlen + slen);
}
