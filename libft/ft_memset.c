/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 14:45:00 by mbryan            #+#    #+#             */
/*   Updated: 2014/11/09 12:19:46 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	e;
	unsigned char	*cb;
	size_t			i;

	cb = (unsigned char *)b;
	e = (unsigned char)c;
	i = 0;
	while (len > 0)
	{
		cb[i] = e;
		i++;
		len--;
	}
	return (b);
}
