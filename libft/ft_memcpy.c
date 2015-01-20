/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:39:12 by mbryan            #+#    #+#             */
/*   Updated: 2014/11/17 11:22:05 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*pchar1;
	unsigned char		*pchar2;

	pchar1 = (unsigned char *)src;
	pchar2 = (unsigned char *)dst;
	i = 0;
	while (n > 0)
	{
		pchar2[i] = pchar1[i];
		i++;
		n--;
	}
	return (dst);
}
