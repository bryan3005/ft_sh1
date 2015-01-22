/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 17:17:31 by mbryan            #+#    #+#             */
/*   Updated: 2015/01/22 16:33:03 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strcdup(const char *src, char c)
{
	int		i;
	char	*cpy;

	i = 0;
	if (src == NULL && !src)
		return (NULL);
	while (src[i] != c)
		i++;
	cpy = (char*)malloc((i + 1) * sizeof(char));
	cpy[i] = '\0';
	i = 0;
	while (src[i] != c)
	{
		cpy[i] = src[i];
	}
	return (cpy);
}
