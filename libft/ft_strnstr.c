/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:17:37 by mbryan            #+#    #+#             */
/*   Updated: 2014/11/17 10:55:24 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *)s1;
	while ((*ptr && n-- != 0) || s2[0] == '\0')
	{
		if (*ptr == s2[0] || s2[0] == '\0')
		{
			i = 0;
			while (ptr[i] == s2[i] && n + 1 - i != 0 && ptr[i] != '\0')
				i++;
			if (s2[i] == '\0')
				return (ptr);
		}
		ptr++;
	}
	return (NULL);
}
