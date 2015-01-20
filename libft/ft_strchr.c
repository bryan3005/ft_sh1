/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:52:36 by mbryan            #+#    #+#             */
/*   Updated: 2014/11/17 10:51:00 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strchr(const char *str, int c)
{
	char	d;
	char	*ptr;

	d = c;
	ptr = (char *)str;
	while (*ptr && *ptr != d)
		ptr++;
	if (*ptr == d)
		return (ptr);
	return (NULL);
}
