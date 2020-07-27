/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfreddie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 11:32:21 by gfreddie          #+#    #+#             */
/*   Updated: 2019/09/15 20:21:44 by gfreddie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**free_ar(char **str)
{
	int	i;

	i = 0;
	while (!(str[i]))
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
	return (str);
}

static int		ft_int_return(char c, char const *str, int i, int words_index)
{
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			words_index++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (words_index);
}

static char		**ft_words_deep(char c, char const *str, char **words_mas,
		int words_index)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		while (str[i] && str[i] != c)
		{
			i++;
			j++;
		}
		if (str[i - 1] != c)
		{
			if (!(words_mas[words_index] =
						(char *)malloc(sizeof(char) * (j + 1))))
				return (free_ar(words_mas));
			words_mas[words_index][j] = '\0';
			words_index++;
		}
		j = 0;
	}
	return (words_mas);
}

static char		**ft_words_record(char c, char const *str, char **words_mas,
		int words_index)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (words_mas[words_index] && str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		while (str[i] && str[i] != c)
		{
			words_mas[words_index][j] = (char)str[i];
			j++;
			i++;
		}
		j = 0;
		words_index++;
	}
	return (words_mas);
}

char			**ft_strsplit(char const *str, char c)
{
	int		words_index;
	char	**words_mas;

	if (!(str))
		return (NULL);
	words_index = ft_int_return(c, str, 0, 0);
	if (!(words_mas = (char **)malloc(sizeof(char *) * (words_index + 1))))
		return (words_mas);
	words_mas[words_index] = NULL;
	if (!(words_index))
		return (words_mas);
	words_mas = ft_words_deep(c, str, words_mas, 0);
	words_mas = ft_words_record(c, str, words_mas, 0);
	return (words_mas);
}
