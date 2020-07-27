/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfreddie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 17:56:02 by gfreddie          #+#    #+#             */
/*   Updated: 2019/09/15 16:45:12 by gfreddie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		if (ft_strncmp((char *)haystack, (char *)needle,
					ft_strlen(needle)) != 0)
			haystack++;
		else
			return ((char *)haystack);
	}
	return (NULL);
}
