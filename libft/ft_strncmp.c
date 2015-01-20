/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:34:21 by mbryan            #+#    #+#             */
/*   Updated: 2014/11/10 11:01:32 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (*((unsigned char*)s1 + i) == *((unsigned char*)s2 + i))
	{
		if (s1[i] == '\0' || i + 1 == n)
			return (0);
		i++;
	}
	return (*((unsigned char*)s1 + i) - *((unsigned char*)s2 + i));
}
