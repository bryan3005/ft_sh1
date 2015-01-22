/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 09:56:06 by mbryan            #+#    #+#             */
/*   Updated: 2015/01/22 16:34:58 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strndup(const char *s, size_t length)
{
	char	*cpy;
	size_t	i;

	i = 0;
	if (length > ft_strlen(s))
		length = ft_strlen(s);
	cpy = (char *)malloc((length + 1) * sizeof(char));
	while (i != length)
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

size_t	ft_strclen(const char *s, char c)
{
	size_t		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**ft_restralloc(char **map, int length, size_t size)
{
	char	**tmp;
	int		i;

	i = -1;
	if (length != 0)
		tmp = map;
	map = (char **)malloc((length + size + 1) * sizeof(char*));
	if (map == NULL)
		return (NULL);
	while (++i != length)
		map[i] = tmp[i];
	map[length + size] = NULL;
	if (length != 0)
		free(tmp);
	return (map);
}

char	*ft_strcdup(const char *s, char c)
{
	char	*cpy;

	cpy = ft_strndup(s, ft_strclen(s, c));
	return (cpy);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**map;
	size_t	i;
	size_t	nb_words;

	if (s == NULL)
		return (NULL);
	i = 0;
	nb_words = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if ((map = ft_restralloc(map, nb_words, 1)) == NULL)
			return (NULL);
		map[nb_words] = ft_strcdup(s + i, c);
		i += ft_strclen(s + i, c);
		while (s[i] && s[i] == c)
			i++;
		nb_words++;
	}
	return (map);
}
