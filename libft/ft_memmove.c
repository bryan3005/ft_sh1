/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 13:51:30 by mbryan            #+#    #+#             */
/*   Updated: 2014/11/17 11:43:48 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*pchar2;
	char		*srccpy;
	char		*cpy;

	srccpy = (char *)src;
	pchar2 = (char *)dst;
	cpy = ft_memalloc(n);
	i = 0;
	while (i < n)
	{
		cpy[i] = srccpy[i];
		i++;
	}
	i = 0;
	while (n > 0)
	{
		pchar2[i] = cpy[i];
		i++;
		n--;
	}
	free(cpy);
	return (dst);
}
