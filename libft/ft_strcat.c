/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 00:30:18 by mbryan            #+#    #+#             */
/*   Updated: 2014/11/17 12:06:44 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	ptr = ft_strdup(s2);
	if (s1 == NULL)
		return (NULL);
	while (s1[j])
	{
		j++;
	}
	while (ptr[i])
	{
		s1[j + i] = ptr[i];
		i++;
	}
	s1[i + j] = '\0';
	free(ptr);
	return (s1);
}
