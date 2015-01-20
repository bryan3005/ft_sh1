/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 08:39:28 by mbryan            #+#    #+#             */
/*   Updated: 2014/11/09 13:42:56 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *memaloc;

	memaloc = (void *)malloc (size);
	if (memaloc == NULL)
		return (NULL);
	ft_memset(memaloc, 0, size);
	return (memaloc);
}
