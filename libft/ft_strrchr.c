/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:18:53 by mbryan            #+#    #+#             */
/*   Updated: 2014/11/17 12:07:57 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strrchr(const char *str, int c)
{
	char	d;
	char	*ptr;
	size_t	i;

	d = c;
	i = 0;
	ptr = (char *)str;
	while (*ptr)
		ptr++;
	while (*ptr != d && i < ft_strlen(str))
	{
		ptr--;
		i++;
	}
	if (*ptr == d)
		return (ptr);
	return (NULL);
}
