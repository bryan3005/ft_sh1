/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:47:10 by mbryan            #+#    #+#             */
/*   Updated: 2014/11/17 11:36:26 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	if (n == 0)
		return (0);
	i = 0;
	ptr1 = (unsigned char*)s1;
	ptr2 = (unsigned char*)s2;
	while (ptr1[i] == ptr2[i])
	{
		if (i + 1 == n)
			return (0);
		i++;
	}
	return (ptr1[i] - ptr2[i]);
}
