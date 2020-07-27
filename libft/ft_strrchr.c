/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfreddie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 17:49:19 by gfreddie          #+#    #+#             */
/*   Updated: 2019/09/12 17:44:45 by gfreddie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char*d;
	int l;

	d = (char *)s;
	l = ft_strlen(s);
	if (c == '\0')
		return ((char *)s + l);
	while (l--)
		if (d[l] == c)
			return (d + l);
	return (NULL);
}
